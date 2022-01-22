from robot.robot_module import RobotModule
from PIL import Image
from typing import Tuple

class ImageModule(RobotModule):
    def __init__(self, **kwargs):
        kwargs=kwargs['kwargs']
        super().__init__(attr_list=['bits'], kwargs=kwargs)

    def decode(self, image: Image) -> Image:
        width, height = image.size
        encoded_image = image.load()

        out = []

        for y in range(height):
            for x in range(width):
                r, g, b = encoded_image[x,y]

                r, g, b = self.__class__.extract_lsb(r, g, b, n_bits=self.bits)

                out.append((r, g, b))
        return self.__class__.make_image(out, image.size)

    @classmethod
    def extract_lsb(cls, *levels, n_bits) -> Tuple[int, int, int]:
        out_levels = [0, 0, 0]
        for i, level in enumerate(levels):
            out_levels[i] = level << (8 - n_bits)
            out_levels[i] = out_levels[i] % 255
        return tuple(out_levels)


    @classmethod
    def make_image(cls, data, size):
        img = Image.new("RGB", size)
        img.putdata(data)
        return img