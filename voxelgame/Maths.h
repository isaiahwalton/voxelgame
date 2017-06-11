#pragma once
#include <math.h>
#include <glm/glm.hpp>
#include <Windows.h>

namespace maths {
	struct Vertex {
		glm::vec3 Position;
		glm::vec4 Colors;
		glm::vec2 TexCoords;
	};

	struct point2 {
		double x;
		double z;
		point2(double X = 0, double Z = 0) {
			x = X;
			z = Z;
		}
	};

	struct point3 {
		double x;
		double y;
		double z;
		point3(double X = 0, double Y = 0, double Z = 0) {
			x = X;
			y = Y;
			z = Z;
		}
	};
	point2 WorldCoordToChunkCoord(int x, int z);
}
