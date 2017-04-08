#include "Texture.h"
#include <iostream>

unsigned int Texture::Load(const char* filename) 
{
	unsigned int texId = 0;
	GLenum format = 0;
	GLint colorCount;

	SDL_Surface * image = SDL_LoadBMP(filename);
	colorCount = image->format->BytesPerPixel;
	if (colorCount == 4)
	{
		if (image->format->Rmask == 0x000000ff)
			format = GL_RGBA;
		else
			format = 32993;
	}
	else if (colorCount == 3)
	{
		if (image->format->Rmask == 0x000000ff)
			format = GL_RGB;
		else
			format = 0x80E0;
	}
	std::cout << format << std::endl;
	//std::cout << image->format->BytesPerPixel << std::endl;
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexImage2D(GL_TEXTURE_2D, 0, colorCount, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);
	gluBuild2DMipmaps(GL_TEXTURE_2D, colorCount, image->w, image->h, format, GL_UNSIGNED_BYTE, image->pixels);
	SDL_FreeSurface(image);
	textureID = texId;
	return texId;
}

void Texture::Bind() 
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}