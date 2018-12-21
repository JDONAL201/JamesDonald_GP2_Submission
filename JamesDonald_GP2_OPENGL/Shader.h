#pragma once
#include <fstream>
#include<iostream>
#include <string>
#include <GL\glew.h>
#include "Transform.h"
#include "Camera.h"


#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
class Shader
{
public:
	Shader();
	
	void createShader(const std::string& shaderVert,const std::string& shaderFrag); // INITIALISE THE SHADER AND CREATE SHADER PROGRAM
	GLuint addShader(const std::string& text, unsigned int type); // ADD A SHADER TO SHADERS BY CALLING CREATE SHADER FROM FILE.
	std::string createShaderFromFile(const std::string& fileName);// RETURN THE SHADER FROM FILE

	void useShader(); // WHEN WANT TO USE SHADER
	

	void shaderErrorCheck(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage); // error handling for shader

	GLuint getAmbientIntensityLocation(); // RETURN AMBIENT INTENSITY LOCATION
	GLuint getAmbientColourLocation(); // RETURN AMBIENT COLOUR LOCATION
	GLuint getDiffuseIntensityLocation();
	GLuint getDirectionLocation();
	GLuint getDiffColourLocation(); 
	
	GLuint getProjectionLocation();
	GLuint getModelLocation();
	GLuint getViewLocation();
	
	~Shader();

private:
	
	static const unsigned int NUMBER_OF_SHADERS = 2; // HOW MANY SHADERS


	GLuint shaderID, uniformTransform, uniformProjection, uniformModel, uniformView, uniformAmbientColour, uniformAmbientIntensity,uniformDiffuseIntensity,uniformDirection, uniformDiffuseColour; // UNSIGNED INTS USED FOR THE LOCATION OF UNIFORMS 
	GLuint shaders[NUMBER_OF_SHADERS];//NUMBER OF SHADERS ARRAY

};

