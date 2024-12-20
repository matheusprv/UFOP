#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

// Vertex Shader source code
const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 vertexColor;
void main()
{
    gl_Position = vec4(aPos, 1.0);
    vertexColor = aColor;
}
)";

// Fragment Shader source code
const char* fragmentShaderSource = R"(
#version 330 core
in vec3 vertexColor;
out vec4 FragColor;
void main()
{
    FragColor = vec4(vertexColor, 1.0);
}
)";

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}  

// ===================================================================

int inicializar_GLFW(){
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return 0;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);

    return 1;
}

GLFWwindow* instanciarJanela(){
    // Cria uma janela de com largura de 800 e altura de 600
    GLFWwindow* window = glfwCreateWindow(800, 600, "Introdução ao OpenGL", NULL, NULL);
    
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

    return window;
}


int inicializar_glad(){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return 0;
    }
    return 1;
}

int main() {

    if (!inicializar_GLFW()) return 1;

    GLFWwindow* window = instanciarJanela();
    if(window == NULL) return -1;

    if (!inicializar_glad()) return 1;

    // Posicoes dos vertices
    float positions[] = {
         0.0f,  0.5f, 0.0f,  // Topo
        -0.5f, -0.5f, 0.0f,  // Inferior esquerdo
         0.5f, -0.5f, 0.0f   // Inferior direito
    };

    // Cores dos vertices
    float colors[] = {
        1.0f, 0.0f, 0.0f,   // Vermelho
        0.0f, 1.0f, 0.0f,   // Verde
        0.0f, 0.0f, 1.0f    // Azul
    };

    // Vertex Array Object (VAO), Vertex Buffer Objects (VBOs)
    unsigned int VAO, VBO_posicoes, VBO_cores;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO_posicoes);
    glGenBuffers(1, &VBO_cores);

    // Bind VAO
    glBindVertexArray(VAO);

    // Buffer para posicoes
    glBindBuffer(GL_ARRAY_BUFFER, VBO_posicoes);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Buffer para cores
    glBindBuffer(GL_ARRAY_BUFFER, VBO_cores);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    // Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    // Shader Program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Renderizacao
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Desenhar triangulo
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO_posicoes);
    glDeleteBuffers(1, &VBO_cores);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}