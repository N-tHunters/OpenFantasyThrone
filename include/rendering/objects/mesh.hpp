#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <rendering/objects/model.hpp>

class Mesh {
	int size;
	GLuint VAO, VBO, EBO;
public:
	Mesh(Model* model);
	void render();
};

#endif