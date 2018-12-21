#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <vector>
#include "GameWindow.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Light.h"
#include "Audio.h"
#include "Skybox.h"
enum class GameStates { PLAY, EXIT };
class MainGame
{
public:
	MainGame();
	~MainGame();
	void run();
	
	GLfloat deltaTime,lastTimeCheck;


private:

	void processInput();
	void gameLoop();
	void draw();
	void processTime();
	void modelRenderer();

	//INITIALISE
	void initShaders();
	void initModels();
	void initTextures();
	void initLights();
	void initAudio();
	void renderLights();
	void initInput();
	void initSkybox();
	void initSystems();
	void handleTransformForCollisionTesting();
	bool collisionDetection(glm::vec3 posOne, float radOne, glm::vec3 posTwo, float radTwo);
	void updateModelBounds();
	//INPUT
	bool keysDown[1024];
	bool firstMove;

	//FOR TIME
	GLfloat currentTime = SDL_GetPerformanceCounter();
	GLfloat lastXpos,lastYpos,changeInX,changeInY;

	//MODELS
	Mesh spaceShip,spaceShip2,ufo,mars,ground;

	//SHADERS
	Shader shader;

	Skybox skybox,skybox1,skybox2,skybox3,skybox4;
	std::vector<std::string> skyboxFaces,skyboxFaces1,skyboxFaces2,skyboxFaces3,skyboxFaces4;
	
	Camera camera;

	//textures..move to mesh on clean up
	Texture marsTex,donutTex, redCamoTex,groundTex, zebraTex;
	//LIGHT
	Light whiteLight, purpleLight,redLight,greenLight,blueLight;
	GLuint skyboxNumber = 0 , lightColour = 0, uniformAmbientIntensity = 0, uniformAmbientColour = 0, uniformDiffuseIntensity = 0, uniformDirection = 0, uniformDiffColour = 0, uniformProjection = 0, uniformModel = 0, uniformView = 0;
	
	//AUDIO
	Audio audioSource;	
	GLuint whoosh,backgroundAudio,collision;
	
	//WINDOW
	GameWindow gameWindow;
	GameStates gameState;


	float counter = 0;
	bool moveUp = false,moveRight = false,testCollision = false;


	glm::vec3 red = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 green = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 blue = glm::vec3(0.0f, 0.0f, 0.4f);
	glm::vec3 purple = glm::vec3(1.0f, 0.0f, 1.0f);
	glm::vec3 white = glm::vec3(1.0f, 1.0f, 1.0f);
};

