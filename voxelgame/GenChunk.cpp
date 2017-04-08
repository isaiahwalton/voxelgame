#include "GenChunk.h"

Chunk GenChunk::GenerateChunk(int chunk_x, int chunk_z, unsigned int seed)
{
	int hights[15][15];
	Chunk generatedchunk;
	generatedchunk = Chunk();
	generatedchunk.x = chunk_x;
	generatedchunk.z = chunk_z;

	module::RidgedMulti mountainTerrain;
	mountainTerrain.SetSeed(seed);

	module::Billow baseFlatTerrain;
	baseFlatTerrain.SetFrequency(2.0);
	baseFlatTerrain.SetSeed(seed);

	module::ScaleBias flatTerrain;
	flatTerrain.SetSourceModule(0, baseFlatTerrain);
	flatTerrain.SetScale(0.125);
	flatTerrain.SetBias(-0.75);

	module::Perlin terrainType;
	terrainType.SetFrequency(0.5);
	terrainType.SetPersistence(0.25);
	terrainType.SetSeed(seed);

	module::Select finalTerrain;
	finalTerrain.SetSourceModule(0, flatTerrain);
	finalTerrain.SetSourceModule(1, mountainTerrain);
	finalTerrain.SetControlModule(terrainType);
	finalTerrain.SetBounds(0.0, 1000.0);
	finalTerrain.SetEdgeFalloff(0.125);

	utils::NoiseMap heightMap;
	utils::NoiseMapBuilderPlane heightMapBuilder;
	heightMapBuilder.SetSourceModule(finalTerrain);
	heightMapBuilder.SetDestNoiseMap(heightMap);
	heightMapBuilder.SetDestSize(16, 16);
	heightMapBuilder.SetBounds(6.0, 10.0, 1.0, 5.0);
	heightMapBuilder.Build();

	for (int x = 0; x < 15; x++) 
	{
		for (int z = 0; z < 15; z++)
		{
			hights[x][z] = heightMap.GetValue(x, z);
		}
	}

	for (int y = 0; y < WORLD_HIGHT; y++) 
	{
		for (int x = 0; x < 15; x++) 
		{
			for (int z = 0; z < 15; z++) 
			{
				if (y == 0) 
				{
					generatedchunk.layers[y].blocks[x][y].SetType(types::bedrock);
				}
				if (hights[x][z] >= y) 
				{
					if (hights[x][z] = y) {
						generatedchunk.layers[y].blocks[x][y].SetType(types::grassblock);
					}
					else 
					{
						generatedchunk.layers[y].blocks[x][y].SetType(types::dirtblock);
					}
				}
			}
		}
	}

	return generatedchunk;
}