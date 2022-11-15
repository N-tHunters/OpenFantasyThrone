#include <rendering/renderer3D.hpp>

Renderer3D::Renderer3D() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);

	video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	window = glfwCreateWindow(video_mode->width, video_mode->height, "OpenFantasyThrone", glfwGetPrimaryMonitor(), nullptr);

	glfwMakeContextCurrent(window);
}

void Renderer3D::addMesh(Mesh* mesh) {
	meshes.push_back(mesh);
}

void Renderer3D::render() {
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.5f, 0.7f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (Mesh* mesh : meshes) {
		mesh->render();
	}

	glFinish();

	glfwSwapBuffers(window);
}

bool Renderer3D::opened() {
	return !glfwWindowShouldClose(window);
}