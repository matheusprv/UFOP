//gcc animacao_circular.c -o animacao_circular -lGL -lGLU -lglut -lm
#include <GL/glut.h>
#include <math.h>

// Raio da trajetória circular
#define RADIUS 2.0

// Ângulo de rotação
float angle = 0.0;

// Função de exibição
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Configuração da câmera
    gluLookAt(0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    // Calcula a posição do objeto na trajetória circular
    float x = RADIUS * cos(angle);
    float y = RADIUS * sin(angle);
    
    // Desenha a trajetória circular (opcional)
    glColor3f(0.5, 0.5, 0.5); // Cinza
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float theta = i * M_PI / 180.0;
        glVertex2f(RADIUS * cos(theta), RADIUS * sin(theta));
    }
    glEnd();

    // Desenha o objeto em movimento
    glPushMatrix();
        glTranslatef(x, y, 0.0); // Move o objeto para a posição circular
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glutSolidSphere(0.2, 20, 20); // Esfera para representar o objeto
    glPopMatrix();

    glutSwapBuffers();
}

// Atualiza o ângulo para a animação
void timer(int value) {
    angle += 0.05; // Incrementa o ângulo para o movimento circular
    if (angle > 2 * M_PI) angle -= 2 * M_PI;

    glutPostRedisplay(); // Redesenha a cena
    glutTimerFunc(16, timer, 0); // Atualiza a cada 16ms (~60FPS)
}

// Inicializa o OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0); // Fundo preto
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animação Circular em OpenGL");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}