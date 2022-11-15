#include <rendering/objects/model.hpp>

Model::Model(std::string path) {
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
	{
		printf("ERROR::ASSIMP::%s\n", import.GetErrorString());
		return;
	}

	aiMesh *mesh = scene->mMeshes[0];
	
	bool isTexCoords = false;
	if(mesh->mTextureCoords[0]) isTexCoords = true;
	for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
		this->vertices.push_back(mesh->mVertices[i].x);
		this->vertices.push_back(mesh->mVertices[i].y);
		this->vertices.push_back(mesh->mVertices[i].z);
		if(isTexCoords) {
			this->vertices.push_back(mesh->mTextureCoords[0][i].x);
			this->vertices.push_back(mesh->mTextureCoords[0][i].y);
		} else {
			this->vertices.push_back(0.0f);
			this->vertices.push_back(0.0f);
		}
	}
	for(unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for(unsigned int j = 0; j < face.mNumIndices; j++)
			this->indices.push_back(face.mIndices[j]);
	}
}