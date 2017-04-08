#pragma once

#include "Block.h"

#define WORLD_HIGHT 100

struct Layer {
	Layer();
	Block blocks[15][15];
};

struct Chunk {
	Chunk();
	Layer layers[WORLD_HIGHT];
	int x;
	int z;
};
