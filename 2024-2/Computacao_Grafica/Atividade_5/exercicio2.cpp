#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

typedef struct BackgroundColor{
    float r, g, b;
}BackgroundColor;
BackgroundColor colors;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}  

glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f);

// Interação com o usuário
void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP)    == GLFW_PRESS && offset.y <= .5) offset.y += 0.01f;
    if (glfwGetKey(window, GLFW_KEY_DOWN)  == GLFW_PRESS && offset.y >= -.5) offset.y -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_LEFT)  == GLFW_PRESS && offset.x >= -.5) offset.x -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && offset.x <= .5) offset.x += 0.01f;
}

const unsigned int WIDTH = 800, HEIGHT = 600;

void inicializar_GLFW(){
    // Inicializa o GLFW
    glfwInit();
    // Configurando o GLFW 
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
    // Definindo o callback para quando ocorrer mudanças no tamanho da janela
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

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

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    return vertexShader;
}

unsigned int compilarFragmentShader(unsigned int vertexShader){
    const char* fragmentShaderSource = "#version 420 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(0.2f, 0.3f, 1.0f, 1.0f);\n"
        "}\n\0";

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void configurarDesenhos(unsigned int *VAO, unsigned int *VBO, float (&square)[12]){
    glBindVertexArray(*VAO);
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(square),
        square,
        GL_STREAM_DRAW
    );
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void loopDeExibicao(GLFWwindow* window, unsigned int shaderProgram, unsigned int VAO) {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(colors.r, colors.g, colors.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glUniform3fv(glGetUniformLocation(shaderProgram, "offset"), 1, &offset[0]);
        glBindVertexArray(VAO);
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
    unsigned int shaderProgram = compilarFragmentShader(vertexShader);

    glDeleteShader(vertexShader);

    float square[12] = {
        //x      y     z
        -0.5f, -0.5f, 0.0f, // Esquerdo inferior
        0.5f, -0.5f, 0.0f, // Direito inferior
        -0.5f,  0.5f, 0.0f, // Esquerdo superior
        0.5f,  0.5f, 0.0f  // Direito superior
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    configurarDesenhos(&VAO, &VBO, square);
    
    glBindVertexArray(0);

    loopDeExibicao(window, shaderProgram, VAO);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    return 0;
}
