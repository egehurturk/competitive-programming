from PIL import Image

import matplotlib.pyplot as plt

import math

input_image = Image.open("grayscale1.jpeg")

pixel_map = input_image.load()

freq_table = {} 

for i in range(1, 255//8 + 2):
    freq_table[str(i)] = 0



'''
1: 7                1: [0, 7]
2: 6                2: [8, 15]
...                 

C = {c1, c2, c3, ..., c ceil(255/8) }


c1: [0, 8)
c2: [8, 16)
c3: [16, 24)
c4: [24, 32)
c5: [32, 40)
c6: [40, 48)
c7: [48, 56)
c8: [56, 64)
c9: [64, 72)

c1: [0, s)
c2: [s, 2s)
c3: [2s, 3s)
...
ci: [(i-1)*s, i*s)
'''


width, height = input_image.size

for i in range(width):
    for j in range(height):
        r, g, b= input_image.getpixel((i, j))
        # r = g = b
        # p --> p // s + 1 ==> p: pixel degeri, s: aralik degeri (8)
        ait_oldugu_class = str(r // 8 + 1)
        '''
        ustteki formul dogru cunku class'lari 1'den baslattigimiz icin 1 ekliyoruz ve aralik 8 oldugu icin
        de 8 e boluyoruz
        '''
        # print(ait_oldugu_class, r)
        
        freq_table[ait_oldugu_class] += 1


sorted_freq_table = {k: v for k, v in sorted(freq_table.items(), key=lambda item: item[1], reverse=True)}

x = sorted_freq_table.keys()
y = sorted_freq_table.values()
plt.plot(x, y)
plt.show()