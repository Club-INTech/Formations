class MissingParameterException(Exception):
    def __init__(self, var_name):
        super().__init__(var_name, "Variable is missing")
