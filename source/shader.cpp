#include "shader.hpp"

shader::shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;

  vShaderFile.exceptions(std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::badbit);

  try {
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);

    std::stringstream vShaderStream, fShaderStream;
    
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    vShaderFile.close();
    fShaderFile.close();

    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  } catch (std::ifstream::failure exception) {
    std::cerr << "error: shader : file not read" << std::endl;
  }

  const GLchar* vShaderCode = vertexCode.c_str();
  const GLchar* fShaderCode = fragmentCode.c_str();

  GLuint vertex, fragment;
  GLint success;
  GLchar infoLog[512];

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, nullptr);
  glCompileShader(vertex);

  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
    std::cerr << "error::shader::vertex::compilation failed\n" << infoLog << std::endl;
  }

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, nullptr);
  glCompileShader(fragment);

  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
    std::cerr << "error::shader::fragment::compilation failed\n" << infoLog << std::endl;
  }

  this->program = glCreateProgram();
  glAttachShader(this->program, vertex);
  glAttachShader(this-> program, fragment);
  glLinkProgram(this->program);

  glGetProgramiv(this->program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
    std::cerr << "error::shader::program::linking failed\n" << infoLog << std::endl;
  }

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void shader::use() {
  glUseProgram(this->program);
}
