import socket
from cypher import *

# authentification/authorization to vpn server
# <vpnserver ip, your ip, your vpn ip, socket> 
def auth(ip, yip, yip2, key, sock, port): 
    message = bytearray(f"AUTH&{yip}&{yip2}&{key}", "utf-8")
    sock.sendto(message, (ip, port)) 
    data = sock.recv(1024)
    k = data.decode("utf-8").split('&')[1]
    if k == "ok":
        return key
    elif k == "error":
        raise ValueError("Invalid key")
    else:
        print(f"New key optained! Key: {k}\n")
        return k


# send message to target through vpn server
# <vpnserver ip, target ip, your ip, message, socket, port, key> 
def send(vpnip, ip, yip2, m, sock, port, key):
    m = encrypt(m, key)
    message = bytearray(f"SEND&{ip}&{yip2}&{m}", "utf-8")
    sock.sendto(message, (vpnip, port))


if __name__ == "__main__":
    f = open('./config.cfg', 'r')
    lines=f.readlines()
    yourIP = lines[5].strip()
    yourIP2 = lines[6].strip()
    VPNIP = lines[7].strip()
    port = int(lines[8])
    key = lines[9].strip()

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((yourIP, port))
    key = auth(VPNIP, yourIP, yourIP2, key, sock, port)
    lines[9] = key
    f = open('./config.cfg', 'w')
    f.writelines(lines)
    sock.close()
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    targetIP = input("Target IP:\n")
    while True:
        message = input("Message to send:\n")
        send(VPNIP, targetIP, yourIP2 , message, sock, port, key)
