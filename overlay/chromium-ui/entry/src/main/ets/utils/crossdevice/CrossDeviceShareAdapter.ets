export interface CrossDeviceSharePayload {
  url: string;
  title: string;
  source: string;
}

export class CrossDeviceShareAdapter {
  static createPayload(url: string, title: string = ''): CrossDeviceSharePayload {
    return {
      url,
      title,
      source: 'aura-shell'
    };
  }
}
