#pragma once
#include "Texture.h"
#include <vector>

class TextureAtlas
{
private:
	Texture m_texture;
	GLuint m_size;
	GLuint m_textureSize;
public:
	TextureAtlas() {  };
	TextureAtlas(GLuint Size, GLuint TextureSize);
	std::vector<GLfloat> getTexCoords(int x, int y);
	~TextureAtlas();
};

