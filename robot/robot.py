from typing import Tuple, Any
from exception.missing_parameter import MissingParameterException
from robot.network_module import NetworkModule
from robot.image_module import ImageModule
from robot.move_module import MoveModule
from PIL import Image


class Robot():
    def __init__(self, desc_list: list, **robot_description) -> None:
        robot_description = robot_description['robot_description']
        success, var = self.__check_entry(desc_list, robot_description)
        if not success:
            raise MissingParameterException(var)
        self.name = robot_description["name"]
        for module in robot_description.keys():
            if module != "name":
                try:
                    setattr(self, module[0].lower() + module[1:], globals()[module](kwargs=robot_description[module]))
                except MissingParameterException as e:
                    print(e)

    def __check_entry(self, desc_list: list, robot_description: dict) -> Tuple[bool, Any]:
        for x in desc_list:
            if not robot_description.keys().__contains__(x):
                return (False, x)
        return (True, None)

    def run(self) -> None:
        # image = Image.open('/home/tsimafei/intech/RobotSimulator/images/encoded.png')
        # self.imageModule.decode(image).save("/home/tsimafei/intech/RobotSimulator/images/decoded.png")
        self.networkModule.connect()
        while(True):
            res = self.networkModule.check(self.moveModule.x, self.moveModule.y)
            if res == 100:
                print("Found")
                self.networkModule.close()
                break
            else:
                print("Not found")
                print(res)
                print("=========")
            x = int(input())
            y = int(input())
            self.moveModule.move(x, y)
