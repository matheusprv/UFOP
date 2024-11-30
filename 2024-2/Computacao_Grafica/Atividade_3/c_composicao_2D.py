import sys, pygame
pygame.init()

size = largura, altura = 800, 600
black = 255, 255, 255

screen = pygame.display.set_mode(size)
screen_center = screen.get_rect().center

mario = pygame.image.load("image.png")
mario = pygame.transform.scale_by(mario, 0.1)
mario_rect = mario.get_rect(center = screen_center)

image_array = pygame.surfarray.array3d(mario)

print(image_array.shape)

def composicao(angulo, escala, surface):
    composta =  pygame.transform.scale_by(
        pygame.transform.rotate(surface, angulo),
        escala
    )
    return composta

while True:
    angulacao = 0 # Rotacao em graus
    escala = 1 # escala
    for event in pygame.event.get():
        if event.type == pygame.QUIT: 
            sys.exit()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_w:
                angulacao += 90
                escala += 0.1
            if event.key == pygame.K_s:
                angulacao -= 90
                if escala >0: escala -= 0.1
            
    if angulacao !=0 or escala !=0:
        mario = composicao(angulacao, escala, mario)

    screen.fill(black)
    screen.blit(mario, mario_rect)
    pygame.display.flip()