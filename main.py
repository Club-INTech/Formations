import sys, getopt
from robot.robot import Robot
import yaml
from exception.missing_parameter import MissingParameterException

if __name__ == "__main__":
    short_options = "h"
    long_options = ["help", "config="]

    arg_list = sys.argv[1:]

    try:
        args, vals = getopt.getopt(arg_list, short_options, long_options)
    except getopt.error as err:
        print("You have -h and --help options for help and config options to use your yaml config")
        print(str(err))

    config_path = "./config/default_config.yaml"

    for arg, val in args:
        if arg in ("-h", "--help"):
            print("===== Help =====")
            print("Use -h or --help for help")
            print("Use config=<path_to_your_config.yaml> to create robot with yaml config")
            print("Take a look at the yaml example in the config folder")
            print("==========")
            sys.exit(0)
        elif arg in ("--config"):
            config_path = val

    with open(config_path, 'r') as stream:
        data = yaml.safe_load(stream)
    try:
        desc = list(['name', 'NetworkModule', 'MoveModule', 'ImageModule'])
        robot = Robot(desc_list=desc, robot_description=data)
        robot.run()
    except MissingParameterException as e:
        print(e)
