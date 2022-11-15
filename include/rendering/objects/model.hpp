#ifndef MODEL_HPP
#define MODEL_HPP

// std includes
#include <string>
#include <vector>
#include <stdio.h>

// lib includes
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model {
public:
	Model(std::string path);
	std::vector<float> vertices;
	std::vector<int> indices;
};

#endif