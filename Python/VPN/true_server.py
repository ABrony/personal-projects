import socket
from datetime import datetime
from cypher import *

if __name__ == "__main__":
    key_length = 64
    f=open('./config.cfg')
    lines=f.readlines()
    yourIP = lines[5].strip()
    port = int(lines[8])

    sock = socket.socket(socket.AF_INET,
                         socket.SOCK_DGRAM)
    sock.bind((yourIP, port))

    cache = {}
    while True:
        data, addr = sock.recvfrom(1024)
        print(datetime.now().isoformat())
        print(f"received message: {data}")
        data = data.decode("utf-8").split('&')
        # AUTH&yourip&yourip2&key
        if data[0] == "AUTH":
            if data[3] == 'default':
                cache[data[2]] = [data[1], keygen(key_length)]
                print(f"Generated key: {cache[data[2]][1]}\n")
                message = bytearray(f"KEY&{cache[data[2]][1]}", "utf-8")
                sock.sendto(message, (data[1], port))
            elif data[2] in cache and data[3] == cache[data[2]][1]:
                print(f"Valid key\n")
                message = bytearray("KEY&ok", "utf-8")
                sock.sendto(message, (data[1], port))
            else:
                print(f"Invalid key\n")
                message = bytearray("KEY&error", "utf-8")
                sock.sendto(message, (data[1], port))

        # SEND&ip&yip2&m
        if data[0] == "SEND":
            s = decrypt(data[3], cache[data[2]][1])
            print(f"decrypted message: {s}")
            s = encrypt(s, cache[data[1]][1])
            message = bytearray(f"SEND&{data[2]}&{data[1]}&{s}", "utf-8")
            print(f"encrypted message: {message}\n")
            sock.sendto(message, (cache[data[1]][0], port))
