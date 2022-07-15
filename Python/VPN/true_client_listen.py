import socket
from datetime import datetime
from cypher import *


if __name__ == "__main__":
    f=open('./config.cfg')
    lines=f.readlines()
    yourIP = lines[5].strip()
    port = int(lines[8])
    key = lines[9].strip()

    sock = socket.socket(socket.AF_INET,
                        socket.SOCK_DGRAM)
    sock.bind((yourIP, port))

    while True:
        data = sock.recv(1024)
        data = data.decode("utf-8").split('&')
        s = decrypt(data[3], key)
        print(datetime.now().isoformat())
        print(f"received message: {s}\n")
    
