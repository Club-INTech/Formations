from robot.robot_module import RobotModule

class MoveModule(RobotModule):
    def __init__(self, **kwargs):
        kwargs=kwargs['kwargs']
        super().__init__(attr_list=['x', 'y'], kwargs=kwargs)

    def move(self, x: int, y: int) -> None:
        self.x = x
        self.y = y