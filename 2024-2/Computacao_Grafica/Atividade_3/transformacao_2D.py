import numpy as np
import math

class Transformacao2D:
    def translacao(self, dx, dy):
        return  np.array([
            [1., 0., dx],
            [0., 1., dy],
            [0., 0., 1.],
        ])

    def rotacao(self, graus):
        radianos = math.radians(graus)
        cos = math.cos(radianos)
        sen = math.sin(radianos) 
        return np.array([
            [cos, -sen, 0],
            [sen, cos, 0],
            [0, 0, 1],
        ])

    def escala(self, sx, sy):
        return np.array([
            [sx, 0., 0.],
            [0., sy, 0.],
            [0., 0., 1.],
        ])
p = np.array([1,0,1])
t = Transformacao2D()
R = t.rotacao(90)
T = t.translacao(2, 3)
final = (np.dot(T, R)).dot(p)
print(final)