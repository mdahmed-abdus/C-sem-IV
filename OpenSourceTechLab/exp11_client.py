import socket

IP = socket.gethostbyname("localhost")
PORT = 8000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((IP, PORT))

msg = s.recv(1024)
print(msg.decode("utf-8"))

s.close()
