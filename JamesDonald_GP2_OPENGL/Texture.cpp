#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"


Texture::Texture()
{

}

void Texture::loadTexture(const std::string& fileString,bool isAlpha)
{
	unsigned char *textureData = stbi_load((fileString).c_str(), &width, &height, &numComponents, 4);
	if (!textureData)
	{
		printf("Failed to find: %s\n", fileString);
		return;
	}

	glGenTextures(1, &textureID); // gen texture 
	glBindTexture(GL_TEXTURE_2D, textureID); // texture in use

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set the parameters 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (isAlpha)  // check if has alpha or not 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData); 
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
	}

	glGenerateMipmap(GL_TEXTURE_2D); // generate mipmap

	glBindTexture(GL_TEXTURE_2D, 0); // unbind

	stbi_image_free(textureData); // free up image
}

void Texture::useTexture()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
}


Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}