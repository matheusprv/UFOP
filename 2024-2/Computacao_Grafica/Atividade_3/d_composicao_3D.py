import math
import numpy as np
import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *

vertices = [
    (1, -1, -1),
    (1, 1, -1),
    (-1, 1, -1),
    (-1, -1, -1),
    (1, -1, 1),
    (1, 1, 1),
    (-1, -1, 1),
    (-1, 1, 1)
]

arestas = (
    (0,1), (0,3), (0,4),
    (2,1), (2,3), (2,7),
    (6,3), (6,4), (6,7),
    (5,1), (5,4), (5,7)
)

def composicao(graus):
    radianos = math.radians(graus)
    cos = math.cos(radianos)
    sen = math.sin(radianos) 
    matriz_rotacaoX = np.array([
        [1,   0,    0, 0],
        [0, cos, -sen, 0],
        [0, sen,  cos, 0],
        [0,   0,    0, 1]
    ])    
    matriz_rotacaoY = np.array([
        [cos, 0, -sen, 0],
        [  0, 1,    0, 0],
        [sen, 0,  cos, 0],
        [0,   0,    0, 1],
    ])    
    matriz_rotacaoZ = np.array([
        [cos, -sen, 0, 0],
        [sen,  cos, 0, 0],
        [  0,    0, 1, 0],
        [0,      0, 0, 1],
    ])    

    # f(x) = rotacaoX * rotacaoY * rotacaoZ
    for i, (x, y, z) in enumerate(vertices):
        vertice = np.array([x, y, z, 1])
        rz = np.dot(matriz_rotacaoZ, vertice)
        ry = np.dot(matriz_rotacaoY, rz)
        rx = np.dot(matriz_rotacaoX, ry)
        vertices[i] = rx[:3]

def Cube():
    glBegin(GL_LINES)
    for edge in arestas:
        for vertex in edge:
            glVertex3fv(vertices[vertex])
    glEnd()

pygame.init()
display = (800,600)
pygame.display.set_mode(display, DOUBLEBUF|OPENGL)
gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)
glTranslatef(0.0,0.0, -5)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()
    
    keys = pygame.key.get_pressed()
    x = y = angulo = 0
    if keys[pygame.K_LEFT]: angulo -= 0.5
    if keys[pygame.K_RIGHT]: angulo += 0.5

    if angulo != 0:
        composicao(angulo)

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    Cube()
    pygame.display.flip()
    pygame.time.wait(10)
