#include "Mesh.h"
#include "Texture.h"


Mesh::Mesh()
{
	drawCount = NULL;

}

void Mesh::createModel(const IndexedModel& model)
{
	drawCount = model.indices.size();

	glGenVertexArrays(1, &vertexArrayObject); //generate one vertex array, location of where to store.
	glBindVertexArray(vertexArrayObject);		// bind the vertex array object to allow to be worked with.
												///SETUP THE BUFFERS	
	glGenBuffers(NUMBER_OF_BUFFERS, vertextArrayBuffers);//generate bufferes based on how many are in our array of buffer data.

	glBindBuffer(GL_ARRAY_BUFFER, vertextArrayBuffers[VERTEX_BUFFER_POSITION]);															 //binding of the buffer,specify the type of data (array buffer data) pass the data to be worked on in specified position.
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW); //data moved over to GPU, specify the type of data, size of the data, starting address(pointer) of data,where to store the data.
	
	glEnableVertexAttribArray(0);								 //enable the use of currently bound vertex array object
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);		//how openGl will read the arrays specified above.  Which array to work with,how many parts of data 3 vertex, what type of data, normalise false,how much data to skip,how far from begining to find first attribute.

	glBindBuffer(GL_ARRAY_BUFFER, vertextArrayBuffers[TEXCOORD_VB]); //binding of the buffer,specify the type of data (array buffer data) pass the data to be worked on in specified position.
	glBufferData(GL_ARRAY_BUFFER, model.texCoords.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW); //data moved over to GPU, specify the type of data, size of the data, starting address(pointer) of data,where to store the data.
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vertextArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);//how openGl will read the arrays specified above.  Which array to work with,how many parts of data 3 vertex, what type of data, normalise false,how much data to skip,how far from begining to find first attribute.

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertextArrayBuffers[INDEX_VB]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU


	glBindVertexArray(0);// unbind the buffer

}
void Mesh::renderModel()
{
	if (drawCount != 0) 
	{
		glBindVertexArray(vertexArrayObject);							 // bind the array to the object
		glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);	//now draw the array using the draw mode triangles,using the drawcount indices,the type of data, the start pos and where to end.
		glBindVertexArray(0);											//unbind the array
	}
	else
	{
		printf("draw count is 0 , nothing to draw");
	}
	
}
void Mesh::loadModel(const std::string& fileName)
{
	BoundingSphere();// call the constructor to create a bounding sphere
	IndexedModel model = OBJModel(fileName).ToIndexedModel(); // create an indexed model for obj loader to load from file
	createModel(model); // call create model using the model from file
}

void Mesh::UpdateBounds(glm::vec3 pos, float rad)
{
	boundingSphere.SetPos(pos);
	boundingSphere.SetRadius(rad);
}
Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArrayObject); //delete arrays created
}
void Mesh::CreateMesh(Vertex* vertices, unsigned int numberOfVerts, unsigned int* indices, unsigned int numIndices)
{
	IndexedModel model;
	for (unsigned int i = 0; i < numberOfVerts; i++)
	{
		model.positions.push_back(*vertices[i].GetPos());
		model.texCoords.push_back(*vertices[i].GetTextCoords());
		model.normals.push_back(*vertices[i].GetNormals());
	}

	for (unsigned int i = 0; i < numIndices; i++) {
		model.indices.push_back(indices[i]);
	}

	createModel(model);
}