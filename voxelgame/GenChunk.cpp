#include "GenChunk.h"
#include <iostream>


int GenChunk::ConvertHeightVal(double val)
{
	int height = ((val / 2) + 0.5) * 100;
	std::cout << "val: " << val << "  height: " << height << std::endl;
	return height;
	//return ((int)(((val / 2) + 0.5) * 100));
}

void GenChunk::GenerateChunk(int chunk_x, int chunk_z, unsigned int seed)
{
	int heights[16][16];
	Chunk generatedchunk = Chunk();
	generatedchunk.x = chunk_x;
	generatedchunk.z = chunk_z;

	module::Perlin MoistureMap;
	MoistureMap.SetSeed(seed);
	MoistureMap.SetFrequency(.1);
	MoistureMap.SetPersistence(.1);
	module::Perlin TreeMap;
	TreeMap.SetSeed(seed);
	TreeMap.SetFrequency(1);
	TreeMap.SetPersistence(1);
/*
	module::RidgedMulti mountainTerrain;
	mountainTerrain.SetFrequency(0.1);
	mountainTerrain.SetSeed(seed);
	module::Billow baseFlatTerrain;
	baseFlatTerrain.SetFrequency(2.0);
	baseFlatTerrain.SetSeed(seed);
	module::ScaleBias flatTerrain;
	flatTerrain.SetSourceModule(0, baseFlatTerrain);
	flatTerrain.SetScale(0.125);
	//flatTerrain.SetBias(-0.75);
	module::Perlin terrainType;
	terrainType.SetFrequency(0.1);
	terrainType.SetOctaveCount(6);
	terrainType.SetPersistence(0.6);
	terrainType.SetSeed(seed);
	module::Select finalTerrain;
	finalTerrain.SetSourceModule(0, flatTerrain);
	finalTerrain.SetSourceModule(1, mountainTerrain);
	finalTerrain.SetControlModule(terrainType);
	finalTerrain.SetBounds(0.0, 1000.0);
	finalTerrain.SetEdgeFalloff(0.125);
	*/
	module::Perlin finalTerrain;
	finalTerrain.SetSeed(seed);
	finalTerrain.SetFrequency(.05);
	finalTerrain.SetPersistence(.1);
	for (int x = 0; x < 16; x++) 
	{
		for (int z = 0; z < 16; z++)
		{
			heights[x][z] = ConvertHeightVal(finalTerrain.GetValue((chunk_x * 16) + x, (chunk_z * 16) + z, 0)) - 10;
			std::cout << "heights: " << heights[x][z] << std::endl;
		}
	}
	
	for (int x = 0; x < 16; x++)
	{
		for (int z = 0; z < 16; z++)
		{
			for (int y = 0; y < WORLD_HEIGHT - 1; y++)
			{
				//if (y == 0)
				//{
				//	generatedchunk.layers[y].blocks[x][z].SetType(types::bedrock);
				//}
				if (heights[x][z] >= y)
				{
				//	if (heights[x][z] = y)
				//	{
				//		generatedchunk.layers[y].blocks[x][z].SetType(types::grassblock);
				//	}
				//	else
				//	{
						generatedchunk.layers[y].blocks[x][z].SetType(types::dirtblock);
				//	}
				}
				//std::cout << "chunk data: " << generatedchunk.layers[y].blocks[x][z].GetType() << "  y: " << y << "  x: " << x << "  z: " << z << std::endl;
			}
		}
	}
	chunk = generatedchunk;
}