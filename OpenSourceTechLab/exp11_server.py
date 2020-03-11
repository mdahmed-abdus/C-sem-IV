import socket

IP = socket.gethostbyname("localhost")
PORT = 8000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((IP, PORT))

s.listen(5)

while True:
    print("Waiting for connection...")
    clientsocket, address = s.accept()
    print(f"Connection from {address} successful.")
    clientsocket.send(bytes(f"Welcome to the server {address[0]}.", "utf-8"))
    clientsocket.close()

s.close()
