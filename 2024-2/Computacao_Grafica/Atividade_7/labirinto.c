// gcc labirinto.c -o labirinto -lGL -lGLU -lglut -lm; ./labirinto
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

float camX = 0.0, camY = 0.3, camZ = 4.0;
float camAngle = 0.0; 

// Velocidade de movimento e rotação
float moveSpeed = 0.2;
float turnSpeed = 3.0;
float margemColisao = 0.1; // Margem para colisão

// Estrutura para representar uma parede (usada como cubo)
typedef struct Parede{
    float x;
    float z;
} Parede;

Parede paredes[100];
int numParedes = 0;


void adicionarParede(float x, float z) {
    paredes[numParedes].x = x;
    paredes[numParedes].z = z;
    numParedes++;
}

void setupLabirinto() {
    // paredes externas
    for (int x = -5; x <= 5; x++) {
        adicionarParede(x, -5); // frente 
        adicionarParede(x, 5);  // atrás 
    }
    
    for (int z = -4; z <= 4; z++) {
        adicionarParede(-5, z); //  esquerda
        adicionarParede(5, z);  //  direita
    }
    
    float paredesInternas[][2] = {
        { 0, -3 },
        { 0, -1 },
        { -2, 1 },
        { -1, 1 },
        { 0, 1 },
        { 1, 1 },
        { 2, 0 },
        { 2, 2 },
        { -3, -1 },
        { -3, -2 }
    };
    
    for (int i = 0; i < 10; i++) 
        adicionarParede(paredesInternas[i][0], paredesInternas[i][1]);

}


void desenharParedesLabirinto() {
    glColor3f(23./255., 195./255., 230./255.);
    for (int i = 0; i < numParedes; i++) {
        glPushMatrix();
            glTranslatef(paredes[i].x, 0.0, paredes[i].z);
            glutSolidCube(1.0);
        glPopMatrix();
    }
}

void desenharChao() {
    glColor3f(84.0/255.0, 103.0/255.0, 107.0/255.0);
    glBegin(GL_QUADS);
        glVertex3f(-6, -0.51, -6);
        glVertex3f(-6, -0.51,  6);
        glVertex3f( 6, -0.51,  6);
        glVertex3f( 6, -0.51, -6);
    glEnd();
}

// Verifica se a posicao da camera esta perto de uma parede
bool verificarColisao(float newX, float newZ) {
    for (int i = 0; i < numParedes; i++) {
        float dx = fabs(newX - paredes[i].x);
        float dz = fabs(newZ - paredes[i].z);
        if (dx < (0.5 + margemColisao) && dz < (0.5 + margemColisao)) {
            return true;
        }
    }
    return false;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Calcula a direção da câmera
    float camLookX = camX + sin(camAngle * M_PI / 180.0);
    float camLookZ = camZ - cos(camAngle * M_PI / 180.0);

    gluLookAt(camX, camY, camZ,   // Posição da câmera
              camLookX, camY, camLookZ,  // Para onde a câmera aponta
              0.0, 1.0, 0.0);   // Define o "cima" da câmera

    desenharChao();
    desenharParedesLabirinto();

    glutSwapBuffers();
}

// Controle de teclado
void keyboard(unsigned char key, int x, int y) {
    float angleRad = camAngle * M_PI / 180.0;
    float newX = camX;
    float newZ = camZ;

    switch (key) {
        case 'w': // Avançar
            newX += sin(angleRad) * moveSpeed;
            newZ -= cos(angleRad) * moveSpeed;
            break;
        case 's': // Retroceder
            newX -= sin(angleRad) * moveSpeed;
            newZ += cos(angleRad) * moveSpeed;
            break;
        case 'a': // Esquerda
            newX -= cos(angleRad) * moveSpeed;
            newZ -= sin(angleRad) * moveSpeed;
            break;
        case 'd': // Direita
            newX += cos(angleRad) * moveSpeed;
            newZ += sin(angleRad) * moveSpeed;
            break;
        case 27: // ESC para sair
            exit(0);
            break;
    }
    // Só atualiza a posição se não houver colisão
    if (!verificarColisao(newX, newZ)) {
        camX = newX;
        camZ = newZ;
    }
    glutPostRedisplay();
}

// Controle de rotação com as setas do teclado
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            camAngle -= turnSpeed;
            break;
        case GLUT_KEY_RIGHT:
            camAngle += turnSpeed;
            break;
        case GLUT_KEY_UP:     
            if(camY < 0.5)
                camY += moveSpeed;
            break;
        case GLUT_KEY_DOWN:
            if(camY > 0.0)
                camY -= moveSpeed;
            break;
    }
    printf("Posicao da camera.\n\tx: %f - y: %f\n", camAngle, camY);
    glutPostRedisplay();
}


// Inicializa o OpenGL e configura a perspectiva
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(230.0/255., 209.0/255.0, 23.0/255.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 800.0/600.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);

    setupLabirinto();
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Labirinto 3D - Andar e explorar");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}
