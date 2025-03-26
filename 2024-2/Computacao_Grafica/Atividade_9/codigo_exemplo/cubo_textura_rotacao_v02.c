//gcc cubo_textura_rotacao_v02.c -o cubo -lGL -lGLU -lglut -lm

#include <GL/glut.h>  // Biblioteca GLUT para OpenGL
#include <stdio.h>     // Biblioteca para entrada/saída padrão
#include <stdlib.h>    // Biblioteca para alocação de memória e controle do sistema

GLuint texture;   // Identificador da textura (ID que será usado para aplicar a textura)
float angle = 0;  // Ângulo de rotação do cubo

// Função para carregar a textura a partir de um arquivo BMP
void loadTexture() {
    FILE *file = fopen("texture.bmp", "rb"); // Abre o arquivo de imagem em modo binário
    if (!file) {
        printf("Erro ao abrir o arquivo texture.bmp!\n");
        exit(1);
    }

    unsigned char header[54]; // Buffer para armazenar o cabeçalho do BMP (54 bytes)
    fread(header, sizeof(unsigned char), 54, file); // Lê o cabeçalho

    // Obtém as dimensões da imagem BMP (largura e altura)
    int width = *(int*)&header[18];  
    int height = *(int*)&header[22]; 
    int size = 3 * width * height; // Calcula o tamanho total da imagem (3 bytes por pixel - RGB)

    // Aloca memória para armazenar os dados da imagem
    unsigned char *data = (unsigned char *)malloc(size);
    fread(data, sizeof(unsigned char), size, file); // Lê os dados da imagem
    fclose(file); // Fecha o arquivo

    // Gera e configura a textura no OpenGL
    glGenTextures(1, &texture);  // Gera um identificador para a textura
    glBindTexture(GL_TEXTURE_2D, texture); // Ativa a textura

    // Configura os filtros de textura (suavização)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Define a textura na memória do OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    free(data); // Libera a memória alocada para a textura
}

// Função para inicializar o OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);    // Ativa o teste de profundidade para ocultação de faces
    glEnable(GL_TEXTURE_2D);    // Ativa o uso de texturas 2D
    glEnable(GL_LIGHTING);      // Ativa a iluminação
    glEnable(GL_LIGHT0);        // Ativa a fonte de luz 0
    glEnable(GL_COLOR_MATERIAL); // Permite que cores de materiais sejam influenciadas pela luz
    glClearColor(0.2, 0.2, 0.2, 1.0); // Define a cor de fundo (cinza escuro)

    loadTexture(); // Carrega a textura para uso no OpenGL

    // Configuração da projeção da câmera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0); // Define projeção perspectiva
    glMatrixMode(GL_MODELVIEW);
}

// Função para desenhar um cubo texturizado
void drawTexturedCube() {
    glBindTexture(GL_TEXTURE_2D, texture); // Associa a textura ao cubo

    glBegin(GL_QUADS); // Inicia o desenho de quadrados para cada face do cubo
    
    // Face frontal
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0,  1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0,  1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0,  1.0);

    // Face traseira
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);

    // Face esquerda
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0,  1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);

    // Face direita
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0,  1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0,  1.0,  1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0,  1.0, -1.0);

    // Face superior
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0,  1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0,  1.0);

    // Face inferior
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, -1.0,  1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, -1.0,  1.0);

    glEnd(); // Finaliza o desenho do cubo
}

// Função de exibição do OpenGL
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Configura a câmera

    glRotatef(angle, 1.0, 1.0, 0.0); // Aplica rotação ao cubo

    drawTexturedCube(); // Desenha o cubo com textura

    glutSwapBuffers(); // Troca os buffers para exibição
}

// Função para atualizar a rotação do cubo
void timer(int value) {
    angle += 2.0f; // Incrementa o ângulo de rotação
    if (angle > 360.0f) angle -= 360.0f;
    glutPostRedisplay(); // Solicita redesenho
    glutTimerFunc(16, timer, 0); // Chama novamente em 16ms (~60 FPS)
}

// Função principal do programa
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cubo Texturizado e Rotacionando");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0); // Inicia a rotação
    glutMainLoop();
    return 0;
}

