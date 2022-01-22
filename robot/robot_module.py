from typing import Any, Tuple
from exception.missing_parameter import MissingParameterException

class RobotModule():
    def __init__(self, attr_list: list, **kwargs) -> None:
        kwargs = kwargs['kwargs']
        for key, value in kwargs.items():
            setattr(self, key, value)
        success, var = self.__check_entry(attr_list)
        if not success:
            raise MissingParameterException(var)

    def __check_entry(self, attr_list: list) -> Tuple[bool, Any]:
        for x in attr_list:
            if not self.__dict__.keys().__contains__(x):
                return (False, x)
        return (True, None)
    
    def run(self) -> None:
        pass

    def check(self) -> int:
        pass 