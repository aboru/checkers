#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

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
  window = glfwCreateWindow(1024, 768, "Checkers", NULL, NULL);

  if (window == NULL) {
    std::cerr << "failed to open GLFW window, check opengl version" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);
  glewExperimental = true;

  if (glewInit() != GLEW_OK) {
    std::cerr << "failed to initialize GLEW" << std::endl;
    return EXIT_FAILURE;
  }

  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  do {
    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
