#ifndef RENDERER3D
#define RENDERER3D

/**
 * @brief      Singleton object for handling 3d rendering.
 */
class Renderer3D {
public:
	Renderer3D();
	void addMesh(Mesh* mesh);
	void render();
private:
	std::vector<Mesh*> meshes;
};

static Renderer3D renderer3D;

#endif