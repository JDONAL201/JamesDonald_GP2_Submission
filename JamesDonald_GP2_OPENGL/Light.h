#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
class Light
{
public:
	Light();
	Light(glm::vec3 RGB, GLfloat aIntensity, glm::vec3 direction, GLfloat directionIntensity, glm::vec3 dRGB); // construct light using colour,direction and intesity for both diffuse and ambient
	~Light();
	void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,GLfloat diffuseIntensityLocation,GLfloat directionLocation, GLfloat diffuseColourLocation);//use the light by passing the location of the uniforms
private:
	glm::vec3 colour; // holds the colour for amb
	GLfloat ambIntensity; // brightness

	glm::vec3 colourDiff; // colour for diffuse
	glm::vec3 direction; // direction for diffuse
	GLfloat diffuseIntensity;// brightness
};
