#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <thread>

using namespace std;

typedef struct BackgroundColor{
    float r, g, b;
}BackgroundColor;
BackgroundColor colors;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}  

glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 offset2 = glm::vec3(0.0f, 0.0f, 0.0f);

// Interação com o usuário
void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Quadrado 1
    if (glfwGetKey(window, GLFW_KEY_W)     == GLFW_PRESS) offset.y += 0.01f;
    if (glfwGetKey(window, GLFW_KEY_S)     == GLFW_PRESS) offset.y -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_A)     == GLFW_PRESS) offset.x -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_D)     == GLFW_PRESS) offset.x += 0.01f;

    // Quadrado 2
    if (glfwGetKey(window, GLFW_KEY_UP)    == GLFW_PRESS) offset2.y += 0.01f;
    if (glfwGetKey(window, GLFW_KEY_DOWN)  == GLFW_PRESS) offset2.y -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_LEFT)  == GLFW_PRESS) offset2.x -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) offset2.x += 0.01f;
}

void mouseClickEvent(GLFWwindow* window, int button, int action, int mods){
    static int background = 0;
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        background = (background + 1) % 4;
    
    if      (background == 0){colors.r = 1.0, colors.g = 0.0; colors.b = 0.0;}  // Vermelho
    else if (background == 1){colors.r = 0.0; colors.g = 1.0; colors.b = 0.0;}  // Verde
    else if (background == 2){colors.r = 0.0; colors.g = 0.0; colors.b = 1.0;}  // Azul
    else                     {colors.r = 1.0; colors.g = 1.0; colors.b = 1.0;}  // Branco
    std::this_thread::sleep_for( std::chrono::microseconds( 100000 ) );

}
const unsigned int WIDTH = 800, HEIGHT = 600;

void inicializar_GLFW(){
    // Inicializa o GLFW
    glfwInit();
    // Confgurando o GLFW 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
}

int inicializar_GLAD(){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return 0;
    }  
    return 1;  
}

GLFWwindow* instanciarJanela(){
    // Cria uma janela de com largura de 800 e altura de 600
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Introdução ao OpenGL", NULL, NULL);
    
    // Fazendo o contexto da janela ser o principal da thread atual
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    // Definindo a janela como o contexto da thread
    glfwMakeContextCurrent(window);
    // Definindo o callback para quando ocorrer mudancas no tamanho da janela
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
    glfwSetMouseButtonCallback(window, mouseClickEvent);

    return window;
}

unsigned int compilarVertexShader(){
    const char *vertexShaderSource = "#version 420 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "uniform vec3 offset;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x + offset.x, aPos.y + offset.y, aPos.z + offset.z, 1.0);\n"
        "}\n\0";

    // --- VERTEX SHADER ---
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    return vertexShader;
}

unsigned int compilarFragmentShader(unsigned int vertexShader ,string vec4_info){
    string fragmentShaderSource = "#version 420 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = "+ vec4_info +";\n"
    "}\n\0";
    const char* source = fragmentShaderSource.c_str();
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &source, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void configurarDesenhos(unsigned int *VAOs, unsigned int *VBOs, float squares[2][12]){
    for(int i = 0; i < 2; i++){
        glBindVertexArray(VAOs[i]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(squares[i]),
            squares[i],
            GL_STREAM_DRAW
        );
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
}

void loopDeExibicao(GLFWwindow* window, unsigned int* shaderPrograms, unsigned int* VAOs) {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(colors.r, colors.g, colors.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Quadrado 1
        glUseProgram(shaderPrograms[0]);
        glUniform3fv(glGetUniformLocation(shaderPrograms[0], "offset"), 1, &offset[0]);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        // Quadrado 2
        glUseProgram(shaderPrograms[1]);
        glUniform3fv(glGetUniformLocation(shaderPrograms[1], "offset"), 1, &offset2[0]);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


int main(){
    colors.r = 1.0; colors.g = 1.0; colors.b = 1.0;

    inicializar_GLFW();
    
    GLFWwindow* window = instanciarJanela();
    if(window == NULL) return -1;
    
    if(!inicializar_GLAD()) return -1;

    unsigned int vertexShader = compilarVertexShader();

    unsigned int shaderProgram_1 = compilarFragmentShader(vertexShader, "vec4(0.2f, 0.3f, 1.0f, 1.0f)");
    unsigned int shaderProgram_2 = compilarFragmentShader(vertexShader, "vec4(1.0f, 0.5f, 0.2f, 1.0f)");
    unsigned int shaderPrograms[2] = {shaderProgram_1, shaderProgram_2};

    glDeleteShader(vertexShader);

    float squares [2][12] = {
        {
            -0.9f, -0.5f, 0.0f, // Esquerdo inferior
            -0.1f, -0.5f, 0.0f, // Direito inferior
            -0.9f,  0.5f, 0.0f, // Esquerdo superior
            -0.1f,  0.5f, 0.0f  // Direito superior
        },
        {
            0.1f, -0.5f, 0.0f,  // Esquerdo inferior
            0.9f, -0.5f, 0.0f,  // Direito inferior
            0.1f,  0.5f, 0.0f,  // Esquerdo superior
            0.9f,  0.5f, 0.0f   // Direito superior
        }
    };

    unsigned int VAOs[2];
    glGenVertexArrays(2, VAOs);

    unsigned int VBOs[2];
    glGenBuffers(2, VBOs);  

    configurarDesenhos(VAOs, VBOs, squares);
    
    glBindVertexArray(0);

    loopDeExibicao(window, shaderPrograms, VAOs);

    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteProgram(shaderPrograms[0]);
    glDeleteProgram(shaderPrograms[1]);

    return 0;
}