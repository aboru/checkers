#ifndef L_SHADER_HPP
#define L_SHADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class shader {
 public:
  GLuint program;
  shader(const GLchar* vertexPath, const GLchar* fragmentPath);
  void use();
};

#endif
