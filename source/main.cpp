#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

int main() {
  if (!glfwInit()) {
    std::cerr << "failed to initialize GLFW" << std::endl;
    return EXIT_FAILURE;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window;
  window = glfwCreateWindow(1024, 768, "Checkers", nullptr, nullptr);

  if (window == nullptr) {
    std::cerr << "failed to open GLFW window, check opengl version" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);
  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    std::cerr << "failed to initialize GLEW" << std::endl;
    return EXIT_FAILURE;
  }

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  glfwSetKeyCallback(window, key_callback);
  
  do {
    glfwPollEvents();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(window);
  } while (!glfwWindowShouldClose(window));

  glfwTerminate();

  return EXIT_SUCCESS;
}
