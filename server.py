import socket
from math import sqrt
ADRESSE = ''
PORT = 6789

a,b = 10, 20

table = [[0 for _ in range(100)] for _ in range(100)]
for i in range(100):
    for j in range(100):
        d = int(100 - sqrt(((i - a)**2) + ((j-b)**2)))
        table[i][j] = d

print(table[a][b])

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((ADRESSE, PORT))
server.listen(1)
client, addressClient = server.accept()


while True:
    data = client.recv(1024).decode()
    if not data:
            print('Error')
    else:
            coors = data.split(" ")
            x, y = int(coors[0]), int(coors[1]) 
            res = 0
            if x < 0 or x > 99 or y < 0 or y > 99:
                res = str(-1)
            else:
                res = str(table[x][y])

            n = client.send(res.encode())
            if (n != len(res)):
                print("Send error")
            else:
                print("Ok")


client.close()
server.close()