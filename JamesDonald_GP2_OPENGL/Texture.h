#pragma once

#include <GL\glew.h>
#include <string>
#include "Common.h"


class Texture
{
public:
	Texture();

	void loadTexture(const std::string& fileString,bool isAlpha); // loading a texture from file and checking if should be alpha or not
	void useTexture(); // use the texture loaded


	~Texture();

private:
	GLuint textureID; // texture id 
	int width, height, numComponents; // int values for the dimentions 

};


