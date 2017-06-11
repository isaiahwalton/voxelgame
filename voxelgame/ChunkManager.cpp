#include "ChunkManager.h"
#include "GenChunk.h"
#include <vector>

ChunkManager::ChunkManager(std::string worldname, unsigned int seed)
{
	mesh = Mesh();
	this->seed = seed;
}

void ChunkManager::LoadChunk(int chunk_x, int chunk_z)
{
	ChunkLoader loader;
	std::string file_name;
	file_name = WorldName + std::to_string(chunk_x) + "," + std::to_string(chunk_z);
	LoadedChunks[chunk_x][chunk_z] = loader.LoadChunk(file_name);
}

void ChunkManager::SaveChunk(Chunk chunk)
{
	std::stringstream s;
	std::string file_name;
	file_name = WorldName + std::to_string(chunk.x) + "," + std::to_string(chunk.z);
	std::fstream OutFile;
	OutFile.open(file_name);
	for (int y = 0; y < WORLD_HEIGHT; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			for (int z = 0; z < 15; z++)
			{
				s << chunk.layers[y].blocks[x][z].GetType();
				OutFile << s.str();
				OutFile << ":";
			}
		}
	}
	OutFile.close();
}

point2 ChunkManager::WorldCoordToChunkCoord(int x, int z)
{
	point2 point = point2(ceil(x / 16), ceil(z / 16));
	return point;
}

void ChunkManager::GenerateChunk(int x, int z)
{
	GenChunk chunkgen = GenChunk();
	chunkgen.GenerateChunk(x, z, seed);
	LoadedChunks[x][z] = chunkgen.chunk;
	LoadedChunks[x][z].GenMesh();
}
void ChunkManager::DisplayAllChunks()
{
	mesh.Update();
}

void ChunkManager::SetBlock(int x, int y, int z, types type)
{
	//TODO make this actually 
}