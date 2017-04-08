#pragma once

#include <string>
#include <fstream>
#include "World.h"
#include "ChunkLoader.h"
#include <sstream>
#include <math.h>

struct point3 {
	double x;
	double y;
	double z;
};

class ChunkManager
{
private:
	Chunk LoadedChunks[19][19];
	std::string WorldName;
	void DisplayChunk(Chunk chunk);
	void LoadChunk(int chunk_x, int chunk_z);
	void SaveChunk(int chunk_x, int chunk_z, Chunk chunk);
	bool CheckVisibility(double x, double y, double z, double cam_x, double cam_y, double cam_z, double angle, double upangle, int fov);
public:
	void DisplayAllChunks();
	ChunkManager(std::string world);
};
