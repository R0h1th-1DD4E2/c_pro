# Basic Networking Commands - Windows vs Linux

| Purpose | Windows Command | Linux Command | Description |
|---------|----------------|---------------|-------------|
| **ARP (Address Resolution Protocol)** | `arp -a` | `arp -a` | Display ARP table (IP to MAC address mappings) |
| | `arp -d <IP>` | `arp -d <IP>` | Delete specific ARP entry |
| | `arp -s <IP> <MAC>` | `arp -s <IP> <MAC>` | Add static ARP entry |
| **IP Configuration** | `ipconfig` | `ip addr show` or `ifconfig` | Show network interface configuration |
| | `ipconfig /all` | `ip addr show` | Show detailed network configuration |
| | `ipconfig /release` | `dhclient -r` | Release DHCP lease |
| | `ipconfig /renew` | `dhclient` | Renew DHCP lease |
| | `ipconfig /flushdns` | `systemd-resolve --flush-caches` | Clear DNS cache |
| **Hostname** | `hostname` | `hostname` | Display system hostname |
| | `nslookup <domain>` | `nslookup <domain>` | DNS lookup for domain |
| | `nslookup <IP>` | `nslookup <IP>` | Reverse DNS lookup |
| **Tracert/Traceroute** | `tracert <destination>` | `traceroute <destination>` | Trace route to destination |
| | `tracert -h <hops> <dest>` | `traceroute -m <hops> <dest>` | Limit maximum hops |
| **Route** | `route print` | `route -n` or `ip route show` | Display routing table |
| | `route add <network> <gateway>` | `route add -net <network> gw <gateway>` | Add static route |
| | `route delete <network>` | `route del -net <network>` | Delete route |
| **Ping** | `ping <destination>` | `ping <destination>` | Test connectivity |
| | `ping -t <destination>` | `ping <destination>` | Continuous ping (Linux pings continuously by default) |
| | `ping -n <count> <dest>` | `ping -c <count> <dest>` | Ping with specific count |
| | `ping -l <size> <dest>` | `ping -s <size> <dest>` | Ping with specific packet size |

## Additional Notes

### Windows Specific:
- Use `ipconfig /?` for help with ipconfig options
- `netsh` command provides advanced network configuration
- `pathping` combines ping and tracert functionality

### Linux Specific:
- `ip` command is the modern replacement for many traditional commands
- Use `man <command>` for detailed help (e.g., `man ping`)
- Some distributions may require installing `net-tools` package for `ifconfig`, `route`, etc.
- `dig` command provides more detailed DNS information than `nslookup`

### Common Usage Examples:
```bash
# Check if a host is reachable
Windows: ping google.com
Linux:   ping google.com

# View network interfaces
Windows: ipconfig /all
Linux:   ip addr show

# Trace path to destination
Windows: tracert google.com
Linux:   traceroute google.com

# View ARP table
Windows: arp -a
Linux:   arp -a

# Check hostname resolution
Windows: nslookup google.com
Linux:   nslookup google.com
```
