#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_OBJ 4

typedef struct Objeto{
    float cor[4];
    float pos[2];
}Objeto;


float bg_color[3] = {0.0f, 0.0f, 0.0f}; // Cor do fundo 

Objeto objetos[3];

void instanciarObjetos(){
    // Iniciando com valores padrão
    for(int i = 0; i < NUM_OBJ; i++){
        for(int j = 0; j < 4; j++)
            objetos[i].cor[j] = 0.0f;
        
        for(int j = 0; j < 2; j++)
            objetos[i].pos[j] = 0.0f;
    }

    // Retangulo vermelho com 50% de transparencia
    objetos[0].cor[0] = 1.0f;
    objetos[0].cor[3] = 0.5f;

    // Triangulo verde com 70% de transparencia
    objetos[1].cor[1] = 1.0f;
    objetos[1].cor[3] = 0.7f;

    // Circulo azul com 30% de transparencia
    objetos[2].cor[2] = 1.0f;
    objetos[2].cor[3] = 0.3f;
}


// 0: quadrado, 1: triangulo, 2: circulo, 3: fundo
enum ObjetoSelecionado{QUADRADO, TRIANGULO, CIRCULO, FUNDO};

enum ObjetoSelecionado objeto_atual_selecionado = QUADRADO;


void exibirObjetoSelecionado() {
    glColor3f(1.0f, 1.0f, 1.0f);
    char label[50];
    if(objeto_atual_selecionado == QUADRADO)
        sprintf(label, "Selecionado: Retangulo");

    else if(objeto_atual_selecionado == TRIANGULO)
            sprintf(label, "Selecionado: Triangulo");
    
    else if(objeto_atual_selecionado == CIRCULO)
        sprintf(label, "Selecionado: Circulo");
    
    else if(objeto_atual_selecionado == FUNDO)
        sprintf(label, "Selecionado: Background");
    
    float x = -1.0f;
    float y = 0.90f;
    glRasterPos2f(x, y);
    int tamanhoString = strlen(label);
    for(int i=0; i<tamanhoString; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }
}

void display(void) {
    // Definindo a cor de fundo
    glClearColor(bg_color[0], bg_color[1], bg_color[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Quadrado
    glPushMatrix();
        glTranslatef(objetos[0].pos[0], objetos[0].pos[1], 0.0f);
        glColor4fv(objetos[0].cor);
        glBegin(GL_QUADS);
            glVertex2f(-0.8f,  0.8f);
            glVertex2f(-0.2f,  0.8f);
            glVertex2f(-0.2f,  0.2f);
            glVertex2f(-0.8f,  0.2f);
        glEnd();
    glPopMatrix();

    // Triangulo
    glPushMatrix();
        glTranslatef(objetos[1].pos[0], objetos[1].pos[1], 0.0f);
        glColor4fv(objetos[1].cor);
        glBegin(GL_TRIANGLES);
            glVertex2f( 0.2f,  0.8f);
            glVertex2f( 0.8f,  0.8f);
            glVertex2f( 0.5f,  0.2f);
        glEnd();
    glPopMatrix();

    // Circulo
    glPushMatrix();
        glTranslatef(objetos[2].pos[0], objetos[2].pos[1], 0.0f);
        glColor4fv(objetos[2].cor);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.0f, -0.5f);  // Centro do circulo
            int numSegments = 50;
            float radius = 0.3f;
            for (int i = 0; i <= numSegments; i++) {
                float angle = 2.0f * 3.14159f * i / numSegments;
                glVertex2f(cos(angle) * radius, -0.5f + sin(angle) * radius);
            }
        glEnd();
    glPopMatrix();

    glDisable(GL_BLEND);

    exibirObjetoSelecionado();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.0, 1.0, -1.0 * (GLfloat)h/(GLfloat)w, 1.0 * (GLfloat)h/(GLfloat)w, -1.0, 1.0);
    else
        glOrtho(-1.0 * (GLfloat)w/(GLfloat)h, 1.0 * (GLfloat)w/(GLfloat)h, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

typedef struct Retorno{
    int rgb;
    bool incremento; // true para incremento e false para decremento
    bool valido;
}Retorno;

Retorno mapear_teclas_e_valores(char key){
    Retorno ret = {.valido=true};
    if(key == 'r') {
        ret.rgb = 0;
        ret.incremento = false;
    }
    else if(key == 'g') {
        ret.rgb = 1;
        ret.incremento = false;
    }
    else if(key == 'b'){
        ret.rgb = 2;
        ret.incremento = false;
    }

    else if(key == 'R') {
        ret.rgb = 0;
        ret.incremento = true;
    }
    else if(key == 'G') {
        ret.rgb = 1;
        ret.incremento = true;
    }
    else if(key == 'B'){
        ret.rgb = 2;
        ret.incremento = true;
    }
    else{
        ret.valido = false;
    }

    return ret;
}

void keyboard(unsigned char key, int x, int y) {
    printf("KEY: {%c} - Objeto selecionado: {%d}\n", key, objeto_atual_selecionado);

    if (key == 'q') exit(0);

    if (key == '1') objeto_atual_selecionado = QUADRADO;
    else if (key == '2') objeto_atual_selecionado = TRIANGULO;
    else if (key == '3') objeto_atual_selecionado = CIRCULO;
    else if (key == '0') objeto_atual_selecionado = FUNDO;

    // Ajustando a transparencia para o que nao é o fundo
    else if (key == 'w' && objeto_atual_selecionado != FUNDO)
        objetos[objeto_atual_selecionado].cor[3] = fminf(1.0f, objetos[objeto_atual_selecionado].cor[3] + 0.1f);
    
    else if (key == 's' && objeto_atual_selecionado != FUNDO)
        objetos[objeto_atual_selecionado].cor[3] = fmaxf(0.0f, objetos[objeto_atual_selecionado].cor[3] - 0.1f);
    
    else {
        Retorno ret = mapear_teclas_e_valores(key);
        if(ret.valido){
            if(ret.incremento){
                if (objeto_atual_selecionado == FUNDO)
                    bg_color[ret.rgb] = fminf(1.0f, bg_color[ret.rgb] + 0.1f);
                else
                    objetos[objeto_atual_selecionado].cor[ret.rgb] = fminf(1.0f, objetos[objeto_atual_selecionado].cor[ret.rgb] + 0.1f);
            }
            else {
                if (objeto_atual_selecionado == FUNDO)
                    bg_color[ret.rgb] = fmaxf(0.0f, bg_color[ret.rgb] - 0.1f);
                else
                    objetos[objeto_atual_selecionado].cor[ret.rgb] = fmaxf(0.0f, objetos[objeto_atual_selecionado].cor[ret.rgb] - 0.1f);
            }
        }
    }
        
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    float moveAmount = 0.05f;
    if (objeto_atual_selecionado == 3)
        return;

    if(key == GLUT_KEY_UP)
        objetos[objeto_atual_selecionado].pos[1] += moveAmount;    
    else if(key == GLUT_KEY_DOWN)
        objetos[objeto_atual_selecionado].pos[1] -= moveAmount;    
    else if(key == GLUT_KEY_LEFT)
        objetos[objeto_atual_selecionado].pos[0] -= moveAmount;  
    else if(key == GLUT_KEY_RIGHT)
        objetos[objeto_atual_selecionado].pos[0] += moveAmount;  

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Colorizacao e transparencia");
    
    instanciarObjetos();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    
    glutMainLoop();
    return 0;
}
