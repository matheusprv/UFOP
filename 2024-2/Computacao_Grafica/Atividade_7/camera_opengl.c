//gcc camera_opengl.c -o camera_opengl -lGL -lGLU -lglut -lm

#include <GL/glut.h>
#include <math.h>

// Posição da câmera
float camX = 0.0, camY = 1.0, camZ = 5.0; // Altura Y = 1.0 para uma visão natural
float camAngle = 0.0; // Ângulo de rotação da câmera

// Velocidade de movimento
float moveSpeed = 0.2;
float turnSpeed = 3.0;

// Função para desenhar a cena 3D (cubos representando obstáculos)
void drawScene() {
    glColor3f(0.0, 0.5, 1.0); // Azul
    glPushMatrix();
        glTranslatef(-2.0, 0.0, -3.0);
        glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glPushMatrix();
        glTranslatef(2.0, 0.0, -5.0);
        glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.0, 1.0, 0.0); // Verde
    glPushMatrix();
        glTranslatef(0.0, 0.0, -7.0);
        glutSolidCube(1.0);
    glPopMatrix();
}

// Função de exibição
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Calcula a direção da câmera
    float camLookX = camX + sin(camAngle * M_PI / 180.0);
    float camLookZ = camZ - cos(camAngle * M_PI / 180.0);

    // Define a posição e direção da câmera
    gluLookAt(camX, camY, camZ,  // Posição da câmera
              camLookX, camY, camLookZ,  // Ponto para onde a câmera olha
              0.0, 1.0, 0.0);  // Define o "cima" da câmera

    drawScene(); // Desenha os objetos da cena

    glutSwapBuffers();
}

// Controle de teclado
void keyboard(unsigned char key, int x, int y) {
    float angleRad = camAngle * M_PI / 180.0;

    switch (key) {
        case 'w': // Move para frente
            camX += sin(angleRad) * moveSpeed;
            camZ -= cos(angleRad) * moveSpeed;
            break;
        case 's': // Move para trás
            camX -= sin(angleRad) * moveSpeed;
            camZ += cos(angleRad) * moveSpeed;
            break;
        case 'a': // Move para a esquerda
            camX -= cos(angleRad) * moveSpeed;
            camZ -= sin(angleRad) * moveSpeed;
            break;
        case 'd': // Move para a direita
            camX += cos(angleRad) * moveSpeed;
            camZ += sin(angleRad) * moveSpeed;
            break;
        case 27: // Tecla ESC para sair
            exit(0);
            break;
    }

    glutPostRedisplay();
}

// Controle de rotação com setas do teclado
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            camAngle -= turnSpeed; // Rotaciona para a esquerda
            break;
        case GLUT_KEY_RIGHT:
            camAngle += turnSpeed; // Rotaciona para a direita
            break;
    }

    glutPostRedisplay();
}

// Inicializa o OpenGL
void init() {
    glEnable(GL_DEPTH_TEST); // Habilita profundidade para renderização 3D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Fundo preto

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 0.1, 100.0); // Define a perspectiva
    glMatrixMode(GL_MODELVIEW);
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simulação de Câmera em OpenGL");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
