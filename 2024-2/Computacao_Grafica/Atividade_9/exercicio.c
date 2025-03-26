// gcc exercicio.c -o exec -lGL -lGLU -lglut -lm
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

// Variáveis globais
GLuint texture;         // Identificador da textura
float rotX = 0.0f;      // Ângulo de rotação em torno do eixo X
float rotY = 0.0f;      // Ângulo de rotação em torno do eixo Y

// Parâmetros de transformação da textura
float offestU = 0.0f, offsetV = 0.0f;
float escalaU = 1.0f, escalaV = 1.0f;

// Função para carregar a textura a partir de um arquivo BMP
void loadTexture() {
    FILE *file = fopen("texture_diamante.bmp", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo texture_diamante.bmp!\n");
        exit(1);
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = 3 * width * height;

    unsigned char *data = (unsigned char *)malloc(size);
    fread(data, sizeof(unsigned char), size, file);
    fclose(file);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    free(data);
}

// Inicialização do OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    loadTexture();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
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
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Rotação do cubo pelas setas
    glRotatef(rotY, 1.0f, 0.0f, 0.0f);
    glRotatef(rotX, 0.0f, 1.0f, 0.0f);

    // Configura a matriz de textura com os parâmetros definidos pelo usuário
    glMatrixMode(GL_TEXTURE);
        glLoadIdentity();
        glTranslatef(offestU, offsetV, 0.0f);
        glScalef(escalaU, escalaV, 1.0f);
    glMatrixMode(GL_MODELVIEW);

    drawTexturedCube();
    glutSwapBuffers();
}

// Callback para entrada de teclas normais (para controlar a textura)
void keyboard(unsigned char key, int x, int y) {

    // Offset
    if(key == 'l' || key == 'L')
        offestU -= 0.1f;

    else if(key == 'j' || key == 'J') 
        offestU += 0.1f;

    else if(key == 'k' || key == 'K') 
        offsetV += 0.1f;

    else if(key == 'i' || key == 'I') 
        offsetV -= 0.1f;

    // Escala
    else if(key == 'd' || key == 'D')
        escalaU -= 0.1f;

    else if(key == 'a' || key == 'A') 
        escalaU += 0.1f;

    else if(key == 'w' || key == 'W')
        escalaV -= 0.1f;
    
    else if(key == 's' || key == 'S') 
        escalaV += 0.1f;

    // Reiniciar
    else if(key == 'r' || key == 'R'){
        offestU = offsetV = 0.0f;
        escalaU = escalaV = 1.0f;
    }

    // Encerrar
    else if (key == 'q' || key == 'Q')
        exit(0);

    glutPostRedisplay();
}

// Callback para entrada de teclas especiais (setas do teclado)
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) rotX += 5.0f;
    else if (key == GLUT_KEY_LEFT) rotX -= 5.0f;
    else if (key == GLUT_KEY_DOWN) rotY -= 5.0f;
    else if (key == GLUT_KEY_UP) rotY += 5.0f;
    glutPostRedisplay();
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mapeamento de textura");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys); // Registra callback para teclas especiais (setas)
    glutMainLoop();
    return 0;
}
