#pragma once

#include <string>
#include <fstream>
#include "World.h"
#include "ChunkLoader.h"
#include <sstream>
#include <math.h>
#include "Block.h"
#include <time.h>

struct point2 {
	double x;
	double z;
	point2(double X = 0, double Z = 0) {
		x = X;
		z = Z;
	}
};

struct point3 {
	double x;
	double y;
	double z;
	point3(double X = 0, double Y = 0, double Z = 0) {
		x = X;
		y = Y;
		z = Z;
	}
};

class ChunkManager
{
private:
	Mesh mesh;
	unsigned int seed;
	Chunk LoadedChunks[39][39];
	std::string WorldName;
	point2 WorldCoordToChunkCoord(int x, int z);
	void LoadChunk(int chunk_x, int chunk_z);
	void SaveChunk(Chunk chunk);
public:

	void GenerateChunk(int x, int z);
	void DisplayAllChunks();
	void SetBlock(int x, int y, int z, types type);
	ChunkManager(std::string worldname, unsigned int seed = time(nullptr));
};
