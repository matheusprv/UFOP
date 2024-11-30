import sys, pygame
import numpy as np
pygame.init()

size = width, height = 800, 600
black = 255, 255, 255

screen = pygame.display.set_mode(size)
screen_center = screen.get_rect().center

mario = pygame.image.load("image.png")
mario = pygame.transform.scale_by(mario, 0.1)
mario_rect = mario.get_rect(center = screen_center)

print(mario.__dict__)
print(mario_rect)

def translacao(antigo, novo):
    x, y = antigo
    dx, dy = novo
    matriz_translacao = np.array([
        [1., 0., dx],
        [0., 1., dy],
        [0., 0., 1.],
    ])
    posicao = np.array([x, y, 1]).T
    nova_posicao = np.dot(matriz_translacao, posicao)[:2]

    novo_x = nova_posicao[0]
    if novo_x > width: novo_x = width
    elif novo_x < 0: novo_x = 0

    novo_y = nova_posicao[1] 
    if novo_y > height: novo_y = height
    elif novo_y < 0: novo_y = 0

    return novo_x, novo_y

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: 
            sys.exit()

    keys = pygame.key.get_pressed()
    x = y = 0
    if keys[pygame.K_w]: y = -1
    if keys[pygame.K_s]: y = +1
    if keys[pygame.K_a]: x = -1
    if keys[pygame.K_d]: x = +1
    
    if x != 0 or y != 0:
        mario_rect.center = translacao(mario_rect.center, (x, y))


    screen.fill(black)
    screen.blit(mario, mario_rect)
    pygame.display.flip()