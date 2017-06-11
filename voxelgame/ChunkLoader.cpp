#include "ChunkLoader.h"

ChunkLoader::ChunkLoader()
{

}

Chunk ChunkLoader::LoadChunk(std::string path_to_chunk)
{
	Chunk LoadedChunk;
	std::string filename;
	std::ifstream file;
	int BlockType;
	file.open(filename.c_str(), std::ifstream::in);
	if (!file.is_open())
	{
		LoadedChunk.layers[0].blocks[0][0].SetType(NULL);
		return LoadedChunk;
	}
	std::string stuff;
	std::getline(file, stuff, ':');
	BlockType = 0;
		for (int y = 0; y < WORLD_HEIGHT; y++)
		{
			for (int x = 0; x < 15; x++)
			{
				for (int z = 0; z < 15; z++)
				{
					BlockType = atoi(stuff.c_str());
					LoadedChunk.layers[y].blocks[x][z].SetType(BlockType);
					std::getline(file, stuff, ':');
				}
			}
		}
	file.close();
	return LoadedChunk;
}
