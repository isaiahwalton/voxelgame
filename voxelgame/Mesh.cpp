#include <GL/glew.h>
#include "Mesh.h"
#include <iostream>
#include <glm/glm.hpp>

Mesh::Mesh(std::vector<maths::Vertex> vertices, std::vector<GLuint> indices)
{
	
	_vertices = vertices;
	_indices = indices;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(maths::Vertex),
		&_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint),
		&_indices[0], GL_STATIC_DRAW);

	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(maths::Vertex),
		(GLvoid*)0);
	// Vertex Colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(maths::Vertex),
		(GLvoid*)offsetof(maths::Vertex, Colors));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(maths::Vertex),
		(GLvoid*)offsetof(maths::Vertex, TexCoords));

	glBindVertexArray(0);
}

void Mesh::EditVert(int at, maths::Vertex val)
{
	_vertices.at(at) = val;
}

void Mesh::EditIndice(int at, GLuint val)
{
	_indices.at(at) = val;
}

void Mesh::UpdateBuffer()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(maths::Vertex),
		&_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint),
		&_indices[0], GL_STATIC_DRAW);

	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(maths::Vertex),
		(GLvoid*)0);
	// Vertex Colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(maths::Vertex),
		(GLvoid*)offsetof(maths::Vertex, Colors));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(maths::Vertex),
		(GLvoid*)offsetof(maths::Vertex, TexCoords));

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
}

void Mesh::Update()
{

	glBindVertexArray(VAO);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_INDEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, 0);
	glIndexPointer(GL_UNSIGNED_BYTE, 0, 0);
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, nullptr);

	glDisableClientState(GL_INDEX_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindVertexArray(0);
}