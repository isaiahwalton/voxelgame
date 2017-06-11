#pragma once
#include <Windows.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <vector>
#include "Maths.h"

class Mesh
{
public:
	Mesh() {};
	Mesh(std::vector<maths::Vertex> vertices, std::vector<GLuint> indices);
	void EditVert(int at, maths::Vertex val);
	void EditIndice(int at, GLuint val);
	void UpdateBuffer();
	~Mesh();
	void Update();
private:
	std::vector<maths::Vertex> _vertices;
	std::vector<GLuint> _indices;

	GLuint VAO, VBO, EBO;
};