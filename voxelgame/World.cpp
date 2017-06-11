#include "World.h"

Layer::Layer() 
{

}

Chunk::Chunk()
{
	atlas = TextureAtlas(512, 16);
}

int Chunk::GetType(int x, int y, int z)
{
	if (x > 15 || x < 0 || z > 15 || z < 0 || y > WORLD_HEIGHT || y < 0) {
		return 0;
	}
	else {
		return layers[y].blocks[x][z].GetType();
	}
}

void Chunk::addSide(maths::Vertex topright, maths::Vertex topleft, maths::Vertex bottomright, maths::Vertex bottomleft)
{
	int indicescount = m_Vertices.size();
	m_Vertices.push_back(topright);
	m_Vertices.push_back(topleft);
	m_Vertices.push_back(bottomright);
	m_Vertices.push_back(bottomleft);
	m_Indices.push_back(indicescount);
	m_Indices.push_back(indicescount + 1);
	m_Indices.push_back(indicescount + 3);

	m_Indices.push_back(indicescount);
	m_Indices.push_back(indicescount + 3);
	m_Indices.push_back(indicescount + 2);
}

void Chunk::addCube(int id, float x, float y, float z)
{
	bool top = true;
	bool bottom = true;
	bool front = true;
	bool back = true;
	bool left = true;
	bool right = true;
	if (GetType(x, y + 1, z) > 0) {top = false;}
	if (GetType(x, y - 1, z) > 0) {bottom = false;}
	if (GetType(x, y, z + 1) > 0) {front = false;}
	if (GetType(x, y, z - 1) > 0) {back = false;}
	if (GetType(x - 1, y, z) > 0) {left = false;}
	if (GetType(x + 1, y, z) > 0) {right = false;}
	maths::Vertex topright;
	maths::Vertex topleft;
	maths::Vertex bottomright;
	maths::Vertex bottomleft;
	topright.TexCoords = { atlas.getTexCoords(1,1).at(0), atlas.getTexCoords(1,1).at(1) };
	topleft.TexCoords = { atlas.getTexCoords(1,1).at(2), atlas.getTexCoords(1,1).at(1) };
	bottomright.TexCoords = { atlas.getTexCoords(1,1).at(0), atlas.getTexCoords(1,1).at(3) };
	bottomleft.TexCoords = { atlas.getTexCoords(1,1).at(2), atlas.getTexCoords(1,1).at(3) };
	
	if (top) {
		topright.Position = { x + .5,y,z - .5 };
		topleft.Position = { x - .5, y,z - .5 };
		bottomright.Position = { x + .5, y,z + .5 };
		bottomleft.Position = { x - .5, y,z + .5 };
		//topright.TexCoords = { 1,1 };
		//topleft.TexCoords = { 1,1 };
		//bottomright.TexCoords = { 1,1 };
		//bottomleft.TexCoords = { 1,1 };
		addSide(topright, topleft, bottomright, bottomleft);//top
	}
	if (bottom) {
		topright.Position = { x + .5, y - 1,z - .5 };
		topleft.Position = { x - .5, y - 1,z - .5 };
		bottomright.Position = { x + .5, y - 1,z + .5 };
		bottomleft.Position = { x - .5, y - 1,z + .5 };
		//topright.TexCoords = { 1,1 };
		//topleft.TexCoords = { 1,1 };
		//bottomright.TexCoords = { 1,1 };
		//bottomleft.TexCoords = { 1,1 };
		addSide(topright, topleft, bottomright, bottomleft);//bottom
	}
	if (left) {
		topright.Position = { x - .5, y,z + .5 };
		topleft.Position = { x - .5, y,z - .5 };
		bottomright.Position = { x - .5, y - 1,z + .5 };
		bottomleft.Position = { x - .5, y - 1,z - .5 };
		//topright.TexCoords = { 1,1 };
		//topleft.TexCoords = { 1,1 };
		//bottomright.TexCoords = { 1,1 };
		//bottomleft.TexCoords = { 1,1 };
		addSide(topright, topleft, bottomright, bottomleft);//left
	}
	if (right) {
		topright.Position = { x + .5, y,z - .5 };
		topleft.Position = { x + .5, y,z + .5 };
		bottomright.Position = { x + .5, y - 1,z - .5 };
		bottomleft.Position = { x + .5, y - 1,z + .5 };
		//topright.TexCoords = { 1,1 };
		//topleft.TexCoords = { 1,1 };
		//bottomright.TexCoords = { 1,1 };
		//bottomleft.TexCoords = { 1,1 };
		addSide(topright, topleft, bottomright, bottomleft);//right
	}
	if (front) {
		topright.Position = { x + .5, y,z + .5 };
		topleft.Position = { x - .5, y,z + .5 };
		bottomright.Position = { x + .5, y - 1,z + .5 };
		bottomleft.Position = { x - .5, y - 1,z + .5 };
		//topright.TexCoords = { 1,1 };
		//topleft.TexCoords = { 1,1 };
		//bottomright.TexCoords = { 1,1 };
		//bottomleft.TexCoords = { 1,1 };
		addSide(topright, topleft, bottomright, bottomleft);//front
	}
	if (back) {
		topright.Position = { x + .5, y,z - .5 };
		topleft.Position = { x - .5, y,z - .5 };
		bottomright.Position = { x + .5, y - 1,z - .5 };
		bottomleft.Position = { x - .5, y - 1,z - .5 };
		//topright.TexCoords = { 1,1 };
		//topleft.TexCoords = { 1,1 };
		//bottomright.TexCoords = { 1,1 };
		//bottomleft.TexCoords = { 1,1 };
		addSide(topright, topleft, bottomright, bottomleft);//back
	}
}

void Chunk::GenMesh()
{
	std::vector<maths::Vertex> vertices;
	std::vector<GLuint> indices;
	for (int y = 0; y < WORLD_HEIGHT - 1; y++)
	{
		for (int x = 0; x < 16; x++)
		{
			for (int z = 0; z < 16; z++)
			{
				if (layers[y].blocks[x][z].GetType() != 0) 
				{
					if (GetType(x, y + 1, z) == 0 || 
						GetType(x, y - 1, z) == 0 ||
						GetType(x + 1, y, z) == 0 ||
						GetType(x - 1, y, z) == 0 ||
						GetType(x, y, z + 1) == 0 ||
						GetType(x, y, z - 1) == 0)
					{
						addCube(layers[y].blocks[x][z].GetType(), x, y, z);
					}
				}
			}
		}
	}
	m_Indices.insert(m_Indices.end(), indices.begin(), indices.end());
	
	m_Vertices.insert(m_Vertices.end(), vertices.begin(), vertices.end());;
}