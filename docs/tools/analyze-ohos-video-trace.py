#!/usr/bin/env python3
"""Summarize Chromium JSON traces from the OHOS staged video playback test.

PHASE timestamps mark the END of each measured operation in that test. Pass
--phase-markers=start for a harness that labels the start instead. Numeric
skip reasons are deliberately not decoded: use the following traced ack.
Thread slices and flow latency are not GPU hardware execution measurements.
"""

import argparse
import bisect
import collections
import hashlib
import json
import pathlib
import statistics


def analyze(path, marker_mode):
    raw = path.read_bytes()
    digest = hashlib.sha256(raw).hexdigest()
    document = json.loads(raw)
    del raw
    events = document["traceEvents"] if isinstance(document, dict) else document
    markers = sorted(
        (e["ts"], e.get("args", {}).get("data", {}).get("message", ""))
        for e in events
        if e.get("name") == "TimeStamp"
        and e.get("args", {}).get("data", {}).get("message", "").startswith("PHASE ")
    )
    marker_times = [ts for ts, _ in markers]

    def phase(ts):
        if not markers:
            return "whole-trace"
        if marker_mode == "end":
            i = bisect.bisect_left(marker_times, ts)
            if i == 0:
                return "before-first-marker"
        else:
            i = bisect.bisect_right(marker_times, ts) - 1
            if i < 0:
                return "before-first-marker"
        return markers[i][1] if i < len(markers) else "after-last-marker"

    counts = collections.defaultdict(collections.Counter)
    intervals = collections.defaultdict(list)
    threads = collections.defaultdict(list)
    sources = collections.defaultdict(set)
    waits = collections.defaultdict(list)
    flow_starts = {}
    flow_ends = {}
    names = {}
    for e in events:
        name = e.get("name", "")
        key = (e.get("pid"), e.get("tid"))
        p = phase(e["ts"])
        if name == "thread_name":
            names[key] = e["args"]["name"]
        if name == "Scheduler::BeginFrame":
            args = e["args"]["args"]
            intervals[p].append(args["interval_us"])
            sources[key].add(args["source_id"])
        if name in ("Scheduler::BeginFrame", "Scheduler::BeginFrameDropped",
                    "LayerTreeHostImpl::DidNotProduceFrame") or (
                "Scheduler::SendDidNotProduceFrame" in name):
            threads[key].append(e)
        if name == "VideoFramesDropped":
            counts[p]["video_frames_dropped"] += e["args"]["count"]
        if name == "SyncToken::Wait":
            if e["ph"] == "X":
                waits[(p, key)].append(e["dur"])
            elif e["ph"] in ("s", "f") and "id" in e:
                flow_key = (e["pid"], e["id"])
                (flow_starts if e["ph"] == "s" else flow_ends)[flow_key] = e

    for key, sequence in threads.items():
        sequence.sort(key=lambda e: e["ts"])
        previous_ack = {}
        missed = {}
        for i, e in enumerate(sequence):
            name, args = e["name"], e.get("args", {})
            if name == "Scheduler::BeginFrame" and args["args"]["subtype"] == "MISSED":
                missed[args["args"]["sequence_number"]] = e["ts"]
            if name == "LayerTreeHostImpl::DidNotProduceFrame":
                previous_ack[args["Frame Sequence Number"]] = (
                    args["FrameSkippedReason"], e["ts"])
            if name != "Scheduler::BeginFrameDropped":
                continue
            count = counts[phase(e["ts"])]
            count["begin_frame_dropped"] += 1
            # Correlate only an immediate same-thread Send/ack pair, with the
            # ack nested inside its Send scope. Leave ambiguous cases unknown.
            following = sequence[i + 1:i + 4]
            send = next((x for x in following
                         if "Scheduler::SendDidNotProduceFrame" in x["name"]), None)
            ack = next((x for x in following
                        if x["name"] == "LayerTreeHostImpl::DidNotProduceFrame"), None)
            if not (send and ack and 0 <= send["ts"] - e["ts"] < 2000
                    and send["ts"] <= ack["ts"] < send["ts"] + send.get("dur", 0)):
                count["unclassified"] += 1
                continue
            reason = ack["args"]["FrameSkippedReason"]
            number = ack["args"]["Frame Sequence Number"]
            count[reason] += 1
            prior = previous_ack.get(number)
            # Ack events omit source_id. Do not join numeric frame sequences
            # across multiple sources on a thread.
            if (len(sources[key]) == 1 and reason == "kRecoverLatency"
                    and prior and prior[0] == "kNoDamage"):
                count["recover_previously_no_damage"] += 1
                if prior[1] < missed.get(number, 0) < e["ts"]:
                    count["recover_after_missed_redelivery"] += 1

    flow_latencies = collections.defaultdict(list)
    for key, start in flow_starts.items():
        end = flow_ends.get(key)
        if end and end["ts"] >= start["ts"]:
            flow_latencies[phase(start["ts"])].append(end["ts"] - start["ts"])

    def stats(values):
        return {"count": len(values), "median_us": statistics.median(values),
                "max_us": max(values)}

    return {
        "file": path.name, "sha256": digest, "phase_markers": marker_mode,
        "phases": dict(counts),
        "begin_frame_intervals": {p: stats(v) for p, v in intervals.items()},
        "sync_token_wait_cpu_slices": [
            {"phase": p, "thread": names.get(key, str(key)), **stats(v)}
            for (p, key), v in waits.items()],
        "sync_token_flow_latency_not_gpu_time": {
            p: stats(v) for p, v in flow_latencies.items()},
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("traces", nargs="+", type=pathlib.Path)
    parser.add_argument("--phase-markers", choices=("start", "end"), default="end")
    options = parser.parse_args()
    print(json.dumps([analyze(p, options.phase_markers) for p in options.traces],
                     indent=2, ensure_ascii=False))
