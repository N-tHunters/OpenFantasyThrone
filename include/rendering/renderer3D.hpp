#ifndef RENDERER3D
#define RENDERER3D

// std includes
#include <vector>

// local includes
#include <rendering/objects/mesh.hpp>
#include <rendering/objects/shader.hpp>

/**
 * @brief      Singleton object for handling 3d rendering.
 */
class Renderer3D {
public:
	Shader* shader3D;
	Renderer3D();
	void addMesh(Mesh* mesh);
	void render();
	bool opened();
private:
	std::vector<Mesh*> meshes;
	GLFWwindow* window;
	const GLFWvidmode* video_mode;
};

static Renderer3D* renderer3D;

#endif