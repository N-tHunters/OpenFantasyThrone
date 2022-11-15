#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>

class Shader {
	GLuint Program;
public:
	Shader(std::string vertex_path, std::string fragment_path);
	void Use();
};

#endif