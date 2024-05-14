//
//  main.cpp
//  Laberinto3D
//
//  Created by Angel Zuñiga on 30/04/24.
//

#include <OpenGL/gl3.h>
#include <SFML/OpenGL.hpp>
#include<fstream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "Shader.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void processInput(sf::Window &window);
// settings
//using namespace std;
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
float deltaTime = 0.0f;    // Time between current frame and last frame
float lastFrame = 0.0f;
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

int main() {
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "SFML window", sf::Style::Default);
    window.setMouseCursorGrabbed(true);
    window.setMouseCursorVisible(false);
#ifdef __APPLE__
    sf::ContextSettings settings;
    settings.majorVersion = 3;
    settings.minorVersion = 2;
    settings.depthBits = 24; // Bits de profundidad (el búfer de profundidad)
    settings.stencilBits = 8;
    settings.attributeFlags = sf::ContextSettings::Default;
    window.create(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "SFML Window",
                  sf::Style::Default, settings);
    window.setMouseCursorGrabbed(true);
    window.setMouseCursorVisible(false);
#endif
    glEnable(GL_DEPTH_TEST);
    Shader ourShader("/Users/angelzuniga/Documents/bamtamg-prueba/Laberinto3D/Laberinto3D/VertexShader.vert", "/Users/angelzuniga/Documents/bamtamg-prueba/Laberinto3D/Laberinto3D/Fragment.frag");
    std::ifstream dataFile("/Users/angelzuniga/Documents/bamtamg-prueba/Laberinto3D/Laberinto3D/data.txt");
    std::string line;
    std::string inputPattern;
    std::vector<glm::vec3> cubes;
    int i = 0;
    while (std::getline(dataFile, line)) {
        inputPattern+=line;
        i++;
    }
    const int rows = i;
    const int cols = 15;
    for (int i = 0; i < rows; ++i) {
       for (int j = 0; j < cols; ++j) {
           char currentChar = inputPattern[i * (cols) + j]; // +1 para contar el carácter de nueva línea
           if (currentChar =='*') {
               float x = static_cast<float>(j) ;
               float y = 0.0f;
               float z = static_cast<float>(i)  ;
                cubes.push_back(glm::vec3(x, y, z));
           }
       }
   }
    for (int i =0 ; i<cubes.size(); ++i) {
        std::cout<<cubes[i].x<<","<<cubes[i].y<<","<<cubes[i].z<<std::endl;
    }
 
    float vertices[] = {
          -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
           0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
          -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
          -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
           0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
           0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
           0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
          -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

          -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
          -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
          -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
          -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
          -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
           0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
           0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
           0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

          -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
           0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
           0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
           0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
          -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

          -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
          -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
          -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
      };
      unsigned int VBO, VAO;
      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      glBindVertexArray(VAO);

      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      // position attribute
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
      // texture coord attribute
      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
      glEnableVertexAttribArray(1);


    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
        // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("/Users/angelzuniga/Documents/bamtamg-prueba/Laberinto3D/Laberinto3D/assets/container.jpeg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    ourShader.use();
    ourShader.setInt( "texture1", 0);
    sf::Clock clock;
//    Camera camera(cameraPos, cameraFront, cameraUp);
    while (window.isOpen()) {
        sf::Event event;
        float currentFrame = clock.getElapsedTime().asSeconds();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
//        std::cout<<deltaTime<<std::endl;
//        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//        while (window.pollEvent(event)) {
//            switch (event.type) {
//                case sf::Event::Closed:
//                    window.close();
//                    break;
//                case sf::Event::KeyPressed:
//                    camera.listenKeyPressed(event.key.code);
//                    break;
//                case sf::Event::MouseWheelMoved:
//                    camera.mouseMoved(mousePosition.x, mousePosition.y);
//                    break;
//            }
//        }

        processInput(window);
        window.clear(sf::Color::Black);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        
        
        ourShader.use();
        const float radius = 10.0f;
        glm::mat4 projection    = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        ourShader.setMat4("view", view);
        glBindVertexArray(VAO);
        for (unsigned int i = 0; i < cubes.size(); i++)
       {
           glm::mat4 model = glm::mat4(1.0f);
           model = glm::translate(model, cubes[i]);
           ourShader.setMat4("model", model);
           glDrawArrays(GL_TRIANGLES, 0, 36);
       }
        window.display();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    return 0;
}

void processInput(sf::Window &window)
{
    static sf::Vector2i lastMousePosition = sf::Vector2i(SCR_WIDTH / 2, SCR_HEIGHT / 2);
    sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window);
    
    if (currentMousePosition != sf::Vector2i(SCR_WIDTH / 2, SCR_HEIGHT / 2)) {
        // Capturar el movimiento del ratón
        float xOffset = currentMousePosition.x - lastMousePosition.x;
        float yOffset = lastMousePosition.y - currentMousePosition.y; // Invertido ya que las coordenadas y van de abajo hacia arriba

        // Restablecer el cursor al centro de la ventana
        sf::Mouse::setPosition(sf::Vector2i(SCR_WIDTH / 2, SCR_HEIGHT / 2), window);

        // Ajustar la sensibilidad del ratón
        float sensitivity = 0.1f;
        xOffset *= sensitivity;
        yOffset *= sensitivity;

        // Actualizar los ángulos yaw y pitch
        yaw += xOffset;
        pitch += yOffset;

        // Asegurar que pitch no exceda los límites para evitar el flipping
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        // Actualizar la dirección de la cámara
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(front);
    }

    // Manejo de otros eventos
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::Resized) {
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        cameraPos += cameraFront * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        cameraPos -= cameraFront * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * deltaTime;
}
