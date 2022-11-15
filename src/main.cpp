#include <rendering/renderer3D.hpp>

int main() {
	renderer3D = new Renderer3D();

	while (renderer3D->opened()) {
		glfwPollEvents();
		renderer3D->render();
	}
	
	glfwTerminate();
	return 0;
}