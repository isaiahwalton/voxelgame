#include "TextureAtlas.h"



TextureAtlas::TextureAtlas(GLuint Size, GLuint TextureSize)
{
	m_size = Size;
	m_textureSize = TextureSize;
}

std::vector<GLfloat> TextureAtlas::getTexCoords(int x, int y)
{
	float texturesPerRow = m_size / m_textureSize;
	float unitSize = 1.0f / (float)texturesPerRow;
	float pixelSize = 1.0f / (float)m_size;
	float xMin = (x * unitSize) + 0.5 * pixelSize;
	float yMin = (y * unitSize) + 0.5 * pixelSize;
	float xMax = (xMin + unitSize) - 0.5 * pixelSize;
	float yMax = (yMin + unitSize) - 0.5 * pixelSize;
	return {xMax, yMax, xMin, yMin};
}

TextureAtlas::~TextureAtlas()
{
}
