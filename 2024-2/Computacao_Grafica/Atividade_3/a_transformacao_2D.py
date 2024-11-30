import sys, pygame
import numpy as np
pygame.init()

tamanho_tela = largura, altura = 800, 600
background = 255, 255, 255

# Calculando a translação manualmente
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

    # Impedindo que o X e o Y ultrapassem os limites da tela
    novo_x = nova_posicao[0]
    if novo_x > largura: novo_x = largura
    elif novo_x < 0: novo_x = 0

    novo_y = nova_posicao[1] 
    if novo_y > altura: novo_y = altura
    elif novo_y < 0: novo_y = 0

    return novo_x, novo_y

if __name__ == "__main__":
    screen = pygame.display.set_mode(tamanho_tela)
    screen_center = screen.get_rect().center

    # Carregando a imagem do mario e diminuindo ela para caber na tela
    mario = pygame.image.load("image.png")
    mario = pygame.transform.scale_by(mario, 0.1)
    mario_rect = mario.get_rect(center = screen_center)

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

        screen.fill(background)
        screen.blit(mario, mario_rect)
        pygame.display.flip()