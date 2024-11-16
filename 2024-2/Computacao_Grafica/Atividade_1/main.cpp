#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}  

// Permitindo que a janela consiga ser fechada pressionando o ESC
void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
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

    return window;
}

unsigned int compilarVertexShader(){
    const char *vertexShaderSource = "#version 420 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    // --- VERTEX SHADER ---
    // Criando um objeto de shader (Pelo menos um deve ser criado obrigatoriamente)
    // Como esta sendo criado um um shader para um vertex, entao passamos GL_VERTEX_SHADER
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Conecta o codigo do shader ao objeto e o compila em run time
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    return vertexShader;
}

unsigned int compilarFragmentShader(unsigned int vertexShader ,string vec4_info){
    // Codigo para compilar do shader de fragmento
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

    // Linkando o shader com o programa do vertex
    // Conecta diferentes shaders em um unico programa
    unsigned int shaderProgram = glCreateProgram();
    // Anexando os programas de shaders
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // Linkando os shaders em um unico projeto
    glLinkProgram(shaderProgram);
    // Apagando os objetos de shaders apos serem linkados
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void consfigurarDesenhos(unsigned int *VAOs, unsigned int *VBOs, float triangles[2][9]){
    for(int i = 0; i < 2; i++){
        glBindVertexArray(VAOs[i]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
        glBufferData(
            GL_ARRAY_BUFFER,        // Qual o tipo do buffer (o bind foi feito no comando anterior)
            sizeof(triangles[i]),   // Tamanho dos dados
            triangles[i],           // Valores a serem enviados
             GL_STATIC_DRAW         // Sugestao de uso da gpu (Aqui os dados sao definidos uma vez e usados varias vezes)
        );
        // Especifica como o dado no vbo deve ser interpretado para cada vertex
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        // Permite que o atributo use o shader
        glEnableVertexAttribArray(0);
    }
}

void loopDeExibicao(GLFWwindow* window, unsigned int * shaderPrograms, unsigned int * VAOs){
    while(!glfwWindowShouldClose(window)){
        processInput(window);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for(int i = 0; i < 2; i++){
            glUseProgram(shaderPrograms[i]);
            glBindVertexArray(VAOs[i]);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
}

int main(){
    inicializar_GLFW();
    
    GLFWwindow* window = instanciarJanela();
    if(window == NULL) return -1;
    
    if(!inicializar_GLAD()) return -1;

    unsigned int vertexShader = compilarVertexShader();

    unsigned int shaderProgram_1 = compilarFragmentShader(vertexShader, "vec4(0.2f, 0.3f, 1.0f, 1.0f)");
    unsigned int shaderProgram_2 = compilarFragmentShader(vertexShader, "vec4(1.0f, 0.5f, 0.2f, 1.0f)");
    unsigned int shaderPrograms[2] = {shaderProgram_1, shaderProgram_2};

    glDeleteShader(vertexShader);

    float triangles [2][9] = {
            // X     Y     Z
        {
            -0.9f, -0.5f, 0.0f, // Esquerdo inferior
            -0.1f, -0.5f, 0.0f, // Direito inferior
            -0.5f,  0.5f, 0.0f  // Topo
        },
        {
            0.2f, 0.5f, 0.0f, // Esquerdo inferior
            0.7f, 0.5f, 0.0f, // Direito inferior
            0.5f, -0.5f, 0.0f  // Topo
        }
    };

    // O VAO armazena o estado de configuração de todos os vertexes 
    unsigned int VAOs[2];
    glGenVertexArrays(2, VAOs);

    // Inicializando o buffer do OpenGL para GPU para carregar o vertex shader
    unsigned int VBOs[2]; // VBO = Vertex Buffer Object
    glGenBuffers(2, VBOs);  

    consfigurarDesenhos(VAOs, VBOs, triangles);
    
    glBindVertexArray(0);

    loopDeExibicao(window, shaderPrograms, VAOs);

    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteProgram(shaderPrograms[0]);
    glDeleteProgram(shaderPrograms[1]);

    return 0;
}