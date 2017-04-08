#include "ChunkManager.h"

ChunkManager::ChunkManager(std::string world)
{
	
}

void ChunkManager::DisplayChunk(Chunk chunk)
{

}

void ChunkManager::LoadChunk(int chunk_x, int chunk_z)
{
	ChunkLoader loader;
	std::string file_name;
	file_name = WorldName + std::to_string(chunk_x) + "," + std::to_string(chunk_z);
	loader.LoadChunk(file_name);
}

void ChunkManager::SaveChunk(int chunk_x, int chunk_z, Chunk chunk)
{
	std::stringstream s;
	std::string file_name;
	file_name = WorldName + std::to_string(chunk_x) + "," + std::to_string(chunk_z);
	std::fstream OutFile;
	int data;
	OutFile.open(file_name);
	for (int y = 0; y < WORLD_HIGHT; y++)
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

bool ChunkManager::CheckVisibility(double x, double y, double z, double cam_x, double cam_y, double cam_z, double angle, double upangle, int fov)
{
	double dist = 500 * tan(fov / 2);
	point3 Cam;
	Cam.x = cam_x;
	Cam.y = cam_y;
	Cam.z = cam_z;
	point3 TopRight;
	point3 TopLeft;
	point3 BottomRight;
	point3 BottomLeft;
	TopRight.x = sin(angle - (fov / 2));
	BottomRight.x = sin(angle - (fov / 2));
	TopRight.y = sin(angle - (fov / 2));
	BottomRight.y = sin(angle - (fov / 2));
	if (1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ChunkManager::DisplayAllChunks()
{

}