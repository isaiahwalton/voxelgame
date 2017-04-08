#pragma once

#include <string>
#include "World.h"
#include <fstream>
#include <iostream>

class ChunkLoader
{
public:
	ChunkLoader();
	Chunk LoadChunk(std::string path_to_chunk);
};

