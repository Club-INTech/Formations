from robot.robot_module import RobotModule
import socket

class NetworkModule(RobotModule):
    def __init__(self, **kwargs):
        kwargs=kwargs['kwargs']
        super().__init__(attr_list=['ip', 'port'], kwargs=kwargs)
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    def connect(self) -> None:
        self.client.connect((self.ip, self.port))

    def check(self, x: int, y: int) -> int:
        self.client.send((str(x) + ' ' + str(y)).encode())
        return int(self.client.recv(1024).decode())

    def close(self) -> None:
        self.client.close()