#pragma once

#include "Block.h"
#include "Mesh.h"
#include "TextureAtlas.h"
#include <vector>
#include "Maths.h"
#include <iostream>

#define WORLD_HEIGHT 255

struct Layer {
	Layer();
	Block blocks[16][16];
};

class Chunk {
private:
	TextureAtlas atlas;

	int GetType(int x, int y, int z);
	void addSide(maths::Vertex topright, maths::Vertex topleft, maths::Vertex bottomright, maths::Vertex bottomleft);
	void addCube(int id, float x, float y, float z);
public:
	std::vector<maths::Vertex> m_Vertices;
	std::vector<GLuint> m_Indices;
	Chunk();
	void GenMesh();
	Layer layers[WORLD_HEIGHT];
	int x;
	int z;
};
