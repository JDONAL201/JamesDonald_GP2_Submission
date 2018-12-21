#include "Skybox.h"

//Shader skyboxShader;
Skybox::Skybox()
{

}

Skybox::Skybox(std::vector<std::string> faceLocations)
{
	skyboxShader = new Shader(); // create new shader
	skyboxShader->createShader("..\\Resources\\shaders\\skybox.vert", "..\\Resources\\shaders\\skybox.frag");//from these shader files

	uniformProjection = skyboxShader->getProjectionLocation(); // set up the uniform projection loc
	uniformView = skyboxShader->getViewLocation(); //view loc

	//setting up textures to work with a cube map 
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height, numComponents;
	int faces = 6;

	for (size_t i = 0; i < faces; i++) // loop through the faces
	{
		unsigned char *textureData = stbi_load(faceLocations[i].c_str(), &width, &height, &numComponents, 0); // texture data = each face
		if (!textureData)
		{
			printf("Failed to find: %s\n", faceLocations[i].c_str()); // error check and print which face
			return;
		}
		// iterate through each cup map face by adding i 
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
		stbi_image_free(textureData);//free the image here to make room for each image
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	createCube();
}

void Skybox::createCube()
	{
		// Mesh Setup
		unsigned int skyboxIndices[] = 
		{
			
			0, 1, 2,// front
			2, 1, 3,
		
			2, 3, 5,// right
			5, 3, 7,
			
			5, 7, 4,// back
			4, 7, 6,
			
			4, 6, 0,// left
			0, 6, 1,
			
			4, 0, 5,// top
			5, 0, 2,
			
			1, 6, 3,// bottom
			3, 6, 7
		};

		Vertex skyboxVertices[] = {
			Vertex(glm::vec3(-1.0f, 1.0f, -1.0f),glm::vec2(0.0f, 0.0f)), // create the cube 
			Vertex(glm::vec3(-1.0f, -1.0f, -1.0f),glm::vec2(0.0f, 0.0f)),
			
			Vertex(glm::vec3(1.0f, 1.0f, -1.0f),glm::vec2(0.0f, 0.0f)),
			Vertex(glm::vec3(1.0f, -1.0f, -1.0f),glm::vec2(0.0f, 0.0f)),

			Vertex(glm::vec3(-1.0f, 1.0f, 1.0f),glm::vec2(0.0f, 0.0f)),
			Vertex(glm::vec3(1.0f, 1.0f, 1.0f),glm::vec2(0.0f, 0.0f)),
			
			Vertex(glm::vec3(-1.0f, -1.0f, 1.0f),glm::vec2(0.0f, 0.0f)),
			Vertex(glm::vec3(1.0f, -1.0f, 1.0f),glm::vec2(0.0f, 0.0f))
		};

		skyCube = new Mesh();
		skyCube->CreateMesh(skyboxVertices, sizeof(skyboxVertices), skyboxIndices, sizeof(skyboxIndices));
}


void Skybox::renderSkybox(Camera camera)
{
	glm::mat4 viewMatrix = camera.getView();
	glm::mat4 projectionMatrix = camera.getProjection();

	viewMatrix = glm::mat4(glm::mat3(viewMatrix)); // convert the view matrix into a 3x3 to remove transform values, so the cube can still rotate and scale but not move.Cuts to a 3 and then makes a 4 from the n

	glDepthMask(GL_FALSE); // disable depth mask 

	skyboxShader->useShader(); // sky shader is shader in use

	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projectionMatrix)); // update the shader  with projection matrix
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(viewMatrix)); // update the shader with view matrix

	glActiveTexture(GL_TEXTURE0); // set active texture
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);// binde the texture to use for cube map with texture location
	
	skyCube->renderModel(); // render the skybox

	glDepthMask(GL_TRUE); // enable the depth mask 
}

Skybox::~Skybox()
{
}
