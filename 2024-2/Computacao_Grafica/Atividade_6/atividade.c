// gcc atividade.c -o atividade -lGL -lGLU -lglut -lm

#include <GL/glut.h>
#include <math.h>

#define SUN_RADIUS          1.0

#define EARTH_ORBIT_RADIUS  4.0
#define EARTH_RADIUS        0.3

#define MOON_ORBIT_RADIUS   0.7
#define MOON_RADIUS         0.1

// Ângulos de rotação -- radianos
float angleEarth = 0.0;  // Ângulo da órbita da Terra
float angleMoon  = 0.0;  // Ângulo da órbita da Lua

// Função de exibição
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Configura a câmera
    gluLookAt(0.0, 45.0, 10.0,  0.0, 0.0, 0.0, 0.0, 10.0, 0.0);
    
    // Desenha o Sol
    glColor3f(1.0, 1.0, 0.0);  // Amarelo
    glutSolidSphere(SUN_RADIUS, 50, 50);
    
    // Desenha a órbita da Terra em torno do Sol
    glColor3f(0.5, 0.5, 0.5);  // Cinza
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            float theta = i * M_PI / 180.0;
            glVertex3f(EARTH_ORBIT_RADIUS * cos(theta), 0, EARTH_ORBIT_RADIUS * sin(theta));
        }
    glEnd();
    
    // Desenha a Terra
    glPushMatrix();
        // Desenha a Terra
        glRotatef(angleEarth * 180.0 / M_PI, 0.0, 1.0, 0.0);
        glTranslatef(EARTH_ORBIT_RADIUS, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);  
        glutSolidSphere(EARTH_RADIUS, 20, 20);
        
        // Desenha a órbita da Lua em torno da Terra
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < 360; i++) {
                float theta = i * M_PI / 180.0;
                glVertex3f(MOON_ORBIT_RADIUS * cos(theta), 0, MOON_ORBIT_RADIUS * sin(theta));
            }
        glEnd();
        
        // Desenha a Lua
        glPushMatrix();
            glRotatef(angleMoon * 180.0 / M_PI, 0.0, 1.0, 0.0);
            glTranslatef(MOON_ORBIT_RADIUS, 0.0, 0.0);
            
            glColor3f(0.8, 0.8, 0.8); 
            glutSolidSphere(MOON_RADIUS, 20, 20);
        glPopMatrix();
        
    glPopMatrix();
    
    glutSwapBuffers();
}

// Atualiza o ângulo para a animação
void timer(int value) {
    angleEarth += 0.01; 
    if (angleEarth > 2 * M_PI) angleEarth -= 2 * M_PI;
    
    angleMoon += 0.05;
    if (angleMoon > 2 * M_PI) angleMoon -= 2 * M_PI;
    
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// Inicialização do OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(15.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Sistema Solar");
    
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    
    return 0;
}
