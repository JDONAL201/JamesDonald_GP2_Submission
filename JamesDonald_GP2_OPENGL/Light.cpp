#include "Light.h"


Light::Light()
{
	//colour = glm::vec3(1.0f, 1.0f, 1.0f);
	//ambIntensity = 1.0f;

	//colourDiff = glm::vec3(1.0f, 1.0f, 1.0f);

	//direction = glm::vec3(0.0f, -1.0f, 0.0f);
	//diffuseIntensity = 0.0f;
}
Light::Light(glm::vec3 RGB, GLfloat aIntensity,glm::vec3 dir, GLfloat directionIntensity ,glm::vec3 dRGB) /*GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat directionIntensity)*/
{
	colour = RGB;//assigncolour to the light
	ambIntensity = aIntensity;	// how strong light will be
	colourDiff = dRGB;// set directional light colour
	direction = dir;// set up the direction of the light
	diffuseIntensity =  directionIntensity; // the intensity of the directional light
}
void Light::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, GLfloat diffuseIntensityLocation, GLfloat directionLocation, GLfloat diffuseColourLocation)/*, GLfloat diffuseIntensityLocation, GLfloat directionLocation)*/
{
	glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z); //set the uniform at this location the value of the colour
	glUniform1f(ambientIntensityLocation, ambIntensity); // set the uniform to the value of ambIntensity

	glUniform3f(directionLocation, direction.x, direction.y, direction.z);// set the direction using the uniform location and the direction to use
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);// set the uniform to the value of diffuseIntensity

	glUniform3f(diffuseColourLocation, colourDiff.x, colourDiff.y, colourDiff.z); // set the colour of the diffuse colour in shader to the colour.diff specified
}

Light::~Light()
{
}
