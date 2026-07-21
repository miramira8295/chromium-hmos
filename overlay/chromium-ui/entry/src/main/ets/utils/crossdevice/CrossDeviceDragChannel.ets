export class CrossDeviceDragChannel {
  static resolveDroppedUrl(data: string): string {
    if (data.startsWith('http://') || data.startsWith('https://')) {
      return data;
    }

    return '';
  }
}
