#include "Maths.h"


namespace maths {
	point2 WorldCoordToChunkCoord(int x, int z)
	{
		point2 point = point2(ceil(x / 16), ceil(z / 16));
		return point;
	}
}
 