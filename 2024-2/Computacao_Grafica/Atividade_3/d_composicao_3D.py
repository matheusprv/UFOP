import math
import numpy as np
import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

pygame.init()

vertices = [
    (0, 1, 0),  # Topo
    (-1, -1, 1), # Frente esquerda
    (1, -1, 1), # Frente direita
    (-1, -1, -1), # trás esquerda
    (1, -1, -1) # trás direita
]

# Definição das arestas para conectar a base e o ápice
arestas = (
    (0, 1), (0, 2), (0, 3), (0, 4),
    (1, 2), (1, 3), (2, 4), (3, 4)
)

def Pyramid():
    glBegin(GL_LINES)
    for edge in arestas:
        for vertex in edge:
            glVertex3fv(vertices[vertex])
    glEnd()

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


if __name__ == "__main__":
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
        Pyramid()
        pygame.display.flip()
        pygame.time.wait(10)
