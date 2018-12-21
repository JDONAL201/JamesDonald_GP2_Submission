#pragma once
#include <iostream>
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include "obj_loader.h"
#include "transform.h"

struct BoundingSphere {
public:
	BoundingSphere() {} // constructer
	BoundingSphere(glm::vec3 pos, float rad)  // the bounding sphere takes in a position and a radius
	{
		position = pos; // position is equal to the input position
		radius = rad; // radius is equal to the input radius
	}

	float radius; // float to hold the radius

	glm::vec3 GetPos() { return position; } // a getter method to return the position
	float GetRadius() { return radius; } // getter method to retun the radius

	void SetPos(glm::vec3 newPos) { this->position = newPos; } // a setter method to take in an input and change the current to new input position
	void SetRadius(float newRadius) { this->radius = newRadius; } // another setter taking a float for radius

private:
	glm::vec3 position; // a vector 3 to hold the position
};


struct Vertex  // vertex class used to store mesh data in simple form for openGL for speeding up opersation.
{
public:

	Vertex(const glm::vec3&pos, const glm::vec2& texCoord)
	{
		this->pos = pos;
		this->texCoords = texCoord;
		this->normal = normal;
	}
	glm::vec3 pos;
	glm::vec2 texCoords; // position on the texture for mapping to vertex.
	glm::vec3 normal;

	glm::vec3* GetPos() { return &pos; }
	glm::vec2* GetTextCoords() { return &texCoords; }
	glm::vec3* GetNormals() { return &normal; }

protected:

private:

};

class Mesh
{
public:
	Mesh();


	void loadModel(const std::string& fileName); // load this model from file
	void createModel(const IndexedModel& model); // with the model from file create and pass to gpu
	void renderModel(); // render this model to screen

////
	void CreateMesh(Vertex* vertices, unsigned int numberOfVerts, unsigned int* indices, unsigned int numIndices);
///
	BoundingSphere boundingSphere;
	Transform transform;

	glm::vec3 GetPos() { return boundingSphere.GetPos(); }
	float GetRadius() { return boundingSphere.GetRadius(); }

	void UpdateBounds(glm::vec3 position, float radius);


	~Mesh();
private:
	enum
	{
		VERTEX_BUFFER_POSITION, TEXCOORD_VB, NORMAL_VB, INDEX_VB, NUMBER_OF_BUFFERS
	};

	GLuint vertexArrayObject;
	GLuint vertextArrayBuffers[NUMBER_OF_BUFFERS];// Create an array of buffers.
	unsigned int drawCount;//how much of the array object to draw

	//GLuint vertexArrayObject, vertexBufferObject, IndexBufferObject;
	//GLsizei drawCount;
};

