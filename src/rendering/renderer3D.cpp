#include <rendering/renderer3D.hpp>

Renderer3D::Renderer3D() {
	
}

void Renderer3D::addMesh(Mesh* mesh) {
	meshes.push_back(mesh);
}

void Renderer3D::render() {
	for (Mesh* mesh : meshes) {
		mesh->render();
	}
}

static Renderer3D renderer3D;