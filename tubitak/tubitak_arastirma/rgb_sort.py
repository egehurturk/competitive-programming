from PIL import Image

import matplotlib.pyplot as plt

import math

input_image = Image.open("rgb.webp")

pixel_map = input_image.load()

freq_table = {} 

for i in range(1, 255//8 + 2):
    freq_table[str(i)] = 0


def avg(x):
    return sum(x) / len(x)

aggregator = avg # representetive function'i sec ve table


width, height = input_image.size

print("total pixels: ", width*height)

for i in range(width):
    for j in range(height):
        r, g, b = input_image.getpixel((i, j))
        p = aggregator([r, g, b])
        ait_oldugu_class = str(int(p // 8 + 1))
        freq_table[ait_oldugu_class] += 1


sorted_freq_table = {k: v for k, v in sorted(freq_table.items(), key=lambda item: item[1], reverse=True)}

x = sorted_freq_table.keys()
y = sorted_freq_table.values()
plt.plot(x, y)
plt.show()