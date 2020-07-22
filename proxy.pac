function FindProxyForURL(url, host) {
    if (host == 'music.163.com' || host == 'interface.music.163.com' || host == 'interface3.music.163.com' || host == 'apm.music.163.com' || host == 'apm3.music.163.com' || host == '103.126.92.133' || host == '103.126.92.132' || host == '59.111.181.38' || host == '59.111.181.60' || host == '223.252.199.66' || host == '223.252.199.67' || host == '59.111.160.195' || host == '59.111.160.197' || host == '59.111.181.35') {
        return 'PROXY ecs.magicxin.tech:114'
    }
    return 'DIRECT'
}