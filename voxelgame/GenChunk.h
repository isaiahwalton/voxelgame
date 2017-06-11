#pragma 

#include <noise.h>
#include "World.h"
#include "noiseutils.h"

class GenChunk
{
private:
	/*
	const int snow_level = 100;
	const int sea_level = 10;
	const int sand_level = sea_level + 1;
	*/
	int ConvertHeightVal(double val);
public:
	Chunk chunk = Chunk();
	GenChunk() {};
	void GenerateChunk(int chunk_x, int chunk_z, unsigned int seed);
};
