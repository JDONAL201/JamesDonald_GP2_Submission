#include "MainGame.h"


///GROUND
unsigned int groundIndices[] =
{
	0, 2, 1,
	1, 2, 3
};
Vertex groundVertices[] =
{

	Vertex(glm::vec3(-15.0f, 0.0f, -15.0f),glm::vec2(0.0f,0.0f)),
	Vertex(glm::vec3(15.0f, 0.0f, -15.0f),glm::vec2(15.0f,0.0f)),
	Vertex(glm::vec3(-15.0f, 0.0f, 15.0f),glm::vec2(0.0f,15.0f)),
	Vertex(glm::vec3(15.0f, 0.0f, 15.0f),glm::vec2(15.0f,15.0f))
};
//////////////////////////////////////////////////////////////////////////////
MainGame::MainGame()
{
	gameState = GameStates::PLAY; // set game state
	GameWindow* gameWindow = new GameWindow(); //new display
	Shader* shader();
	
}
void MainGame::initModels()
{

	spaceShip.loadModel("..\\Resources\\models\\scout patrol.obj"); // go to resources and get the moneky obj to load
	spaceShip.transform.SetPos(glm::vec3(-10.0f, 2.0f, 10.0f)); //set the position of this monkey obj
	spaceShip.transform.SetScale(glm::vec3(0.05f, 0.05f, 0.05f));//set the scale of the monkey obj
	spaceShip.transform.SetRot(glm::vec3(0.0f, 3.0f, 0.0f));

	spaceShip2.loadModel("..\\Resources\\models\\jet.obj"); // go to resources and get the moneky obj to load
	spaceShip2.transform.SetPos(glm::vec3(-10.0f, 2.0f,-10.0f)); //set the position of this monkey obj
	spaceShip2.transform.SetScale(glm::vec3(0.5f, 0.5f, 0.5f));//set the scale of the monkey obj
	spaceShip2.transform.SetRot(glm::vec3(0.0f, 0.2f, 0.0f));

	ufo.loadModel("..\\Resources\\models\\ufo.obj"); // go to resources and get the moneky obj to load
	ufo.transform.SetPos(glm::vec3(15.0f,6.0f, -2.0f)); //set the position of this monkey obj
	ufo.transform.SetScale(glm::vec3(0.025f, 0.025f, 0.025f));//set the scale of the monkey obj

	mars.loadModel("..\\Resources\\models\\mars.obj"); // go to resources and get the moneky obj to load
	mars.transform.SetPos(glm::vec3(5.0f, 3.0f, 0.0f)); //set the position of this monkey obj
	mars.transform.SetScale(glm::vec3(1.0f, 1.0f, 1.0f));//set the scale of the monkey obj
	mars.transform.SetRot(glm::vec3(10.0f, 0.0f, 0.0f));
	
}
void MainGame::initTextures()
{
	marsTex.loadTexture("..\\Resources\\textures\\mars.png",true); // load each texture from file
	donutTex.loadTexture("..\\Resources\\textures\\donut.jpg",true);
	groundTex.loadTexture("..\\Resources\\textures\\ground.jpg",true);
	redCamoTex.loadTexture("..\\Resources\\textures\\redCamo.jpg",true);
	zebraTex.loadTexture("..\\Resources\\textures\\zebra.jpg", true);
}
void MainGame::initSkybox()
{	// populate the list of strings to hold the faces of the skybox
	skyboxFaces.push_back("..\\Resources\\textures\\Skybox\\orbital-element\\orbital-element_ft.tga");
	skyboxFaces.push_back("..\\Resources\\textures\\Skybox\\orbital-element\\orbital-element_bk.tga");
	skyboxFaces.push_back("..\\Resources\\textures\\Skybox\\orbital-element\\orbital-element_up.tga");
	skyboxFaces.push_back("..\\Resources\\textures\\Skybox\\orbital-element\\orbital-element_dn.tga");
	skyboxFaces.push_back("..\\Resources\\textures\\Skybox\\orbital-element\\orbital-element_rt.tga"); //have to do in this order
	skyboxFaces.push_back("..\\Resources\\textures\\Skybox\\orbital-element\\orbital-element_lf.tga");

	skybox = Skybox(skyboxFaces); // get ready to draw
	
	skyboxFaces1.push_back("..\\Resources\\textures\\Skybox\\sandcastle\\sandcastle_ft.tga");
	skyboxFaces1.push_back("..\\Resources\\textures\\Skybox\\sandcastle\\sandcastle_bk.tga");
	skyboxFaces1.push_back("..\\Resources\\textures\\Skybox\\sandcastle\\sandcastle_up.tga");
	skyboxFaces1.push_back("..\\Resources\\textures\\Skybox\\sandcastle\\sandcastle_dn.tga");
	skyboxFaces1.push_back("..\\Resources\\textures\\Skybox\\sandcastle\\sandcastle_rt.tga"); //have to do in this order
	skyboxFaces1.push_back("..\\Resources\\textures\\Skybox\\sandcastle\\sandcastle_lf.tga");
	skybox1 = Skybox(skyboxFaces1);

	skyboxFaces2.push_back("..\\Resources\\textures\\Skybox\\hell\\hell_ft.tga");
	skyboxFaces2.push_back("..\\Resources\\textures\\Skybox\\hell\\hell_bk.tga");
	skyboxFaces2.push_back("..\\Resources\\textures\\Skybox\\hell\\hell_up.tga");
	skyboxFaces2.push_back("..\\Resources\\textures\\Skybox\\hell\\hell_dn.tga");
	skyboxFaces2.push_back("..\\Resources\\textures\\Skybox\\hell\\hell_rt.tga"); //have to do in this order
	skyboxFaces2.push_back("..\\Resources\\textures\\Skybox\\hell\\hell_lf.tga");
	skybox2 = Skybox(skyboxFaces2);

	skyboxFaces3.push_back("..\\Resources\\textures\\Skybox\\greenhaze\\greenhaze_ft.tga");
	skyboxFaces3.push_back("..\\Resources\\textures\\Skybox\\greenhaze\\greenhaze_bk.tga");
	skyboxFaces3.push_back("..\\Resources\\textures\\Skybox\\greenhaze\\greenhaze_up.tga");
	skyboxFaces3.push_back("..\\Resources\\textures\\Skybox\\greenhaze\\greenhaze_dn.tga");
	skyboxFaces3.push_back("..\\Resources\\textures\\Skybox\\greenhaze\\greenhaze_rt.tga"); //have to do in this order
	skyboxFaces3.push_back("..\\Resources\\textures\\Skybox\\greenhaze\\greenhaze_lf.tga");
	skybox3 = Skybox(skyboxFaces3);

	skyboxFaces4.push_back("..\\Resources\\textures\\Skybox\\darkcity\\darkcity_ft.tga");
	skyboxFaces4.push_back("..\\Resources\\textures\\Skybox\\darkcity\\darkcity_bk.tga");
	skyboxFaces4.push_back("..\\Resources\\textures\\Skybox\\darkcity\\darkcity_up.tga");
	skyboxFaces4.push_back("..\\Resources\\textures\\Skybox\\darkcity\\darkcity_dn.tga");
	skyboxFaces4.push_back("..\\Resources\\textures\\Skybox\\darkcity\\darkcity_rt.tga"); //have to do in this order
	skyboxFaces4.push_back("..\\Resources\\textures\\Skybox\\darkcity\\darkcity_lf.tga");
	skybox4 = Skybox(skyboxFaces4);
}
void MainGame::initShaders() 
{
	shader.createShader("..\\Resources\\shaders\\shader.vert","..\\Resources\\shaders\\shader.frag"); // create the shader from the file locations given
	
}
void MainGame::run() 
{
	initSystems();
	gameLoop();
}
void MainGame::initInput() 
{
	SDL_SetRelativeMouseMode(SDL_TRUE); // mouse relative to game window

	//all keys are up so set all to false
	for (size_t i = 0; i < 1024; i++)
	{
		keysDown[i] = 0;
	}
}
void MainGame::initLights() 
{
	whiteLight = Light(white, 0.2f, glm::vec3(1.0f, 1.0f, 1.0f), 0.8f, white); // create lights that can be used
	redLight = Light(white, 0.2f, glm::vec3(0.0f, -1.0f, 0.0f), 0.8f, red);
	blueLight = Light(white, 0.2f, glm::vec3(1.0f, 1.0f, 1.0f), 0.8f, blue);
	greenLight = Light(white, 0.2f, glm::vec3(-1.0f, 0.0f, -1.0f), 0.8f, green);
	purpleLight = Light(white, 0.2f, glm::vec3(1.0f, 1.0f, 0.0f), 0.8f, purple);
}
void MainGame::initAudio()
{
	backgroundAudio = audioSource.loadSound("..\\Resources\\audio\\background.wav"); // load in audio from file
	whoosh = audioSource.loadSound("..\\Resources\\audio\\whoosh.wav");
	collision = audioSource.loadSound("..\\Resources\\audio\\collision.wav");
	audioSource.playSound(backgroundAudio); // play background audio on startup
}
void MainGame::initSystems() 
{
	gameWindow.initWindow(); //initalise game window 
	
	initInput();
	initShaders();
	initSkybox();
	initTextures();
	initModels();
	initLights();
	initAudio();

	camera = Camera(glm::vec3(-50.0f, 10.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 45.0f,
		(float)gameWindow.getWidth() / gameWindow.getHeight(), 0.1f, 1000.0f, 0.0f, 0.0f, 20.0f, 0.1f);	 // create the camera



	deltaTime = 0.0f;
	lastTimeCheck = 0.0f;
}
void MainGame::processTime()
{
	// used to calculate delta time
	lastTimeCheck = currentTime; 
	currentTime = SDL_GetPerformanceCounter();
	deltaTime =(double) ((currentTime - lastTimeCheck) /(double) SDL_GetPerformanceFrequency());

}
void MainGame::gameLoop()
{
	while (gameState != GameStates::EXIT) // while gamestate not exit , update these methods
	{
		processTime(); 
		draw();
		processInput();
		camera.cameraControl(deltaTime, keysDown);
		updateModelBounds();
		collisionDetection(spaceShip.GetPos(), spaceShip.GetRadius(), spaceShip2.GetPos(), spaceShip2.GetRadius());
	
	}
}
void MainGame::updateModelBounds() 
{
	spaceShip2.UpdateBounds(*spaceShip2.transform.GetPos(), 5.0f); // update the bouds of these objects
	spaceShip.UpdateBounds(*spaceShip.transform.GetPos(), 5.0f);
}
void MainGame::renderLights() 
{
	lightColour = skyboxNumber;
	uniformAmbientColour = shader.getAmbientColourLocation();
	uniformAmbientIntensity = shader.getAmbientIntensityLocation();
	uniformDiffuseIntensity = shader.getDiffuseIntensityLocation();
	uniformDirection = shader.getDirectionLocation();
	uniformDiffColour = shader.getDiffColourLocation();
	switch (lightColour) {
	case 0:
		whiteLight.useLight(uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection, uniformDiffColour);
		break;
	case 1:
		whiteLight.useLight(uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection, uniformDiffColour);
		
		break;
	case 2:
		redLight.useLight(uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection, uniformDiffColour);

		break;
	case 3:
		greenLight.useLight(uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection, uniformDiffColour);

		break;
	case 4:
		purpleLight.useLight(uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection, uniformDiffColour);

		break;

	}
	


}
void MainGame::draw()
{

	gameWindow.displayCleanup(0.0f, 0.0f, 0.0f, 1.0f);

	switch (skyboxNumber) {
	case 0:
		skybox.renderSkybox(camera);
		break;
	case 1:
		skybox1.renderSkybox(camera);
		break;
	case 2:
		skybox2.renderSkybox(camera);
		break;
	case 3:
		skybox3.renderSkybox(camera);
		break;
	case 4:
		skybox4.renderSkybox(camera);
		break;

	}
	
	modelRenderer();
	renderLights();
	
	glUseProgram(0);

	gameWindow.swapBuffer();
}
void MainGame::modelRenderer() 
{
	uniformModel = shader.getModelLocation();
	uniformProjection = shader.getProjectionLocation();
	uniformView = shader.getViewLocation();
	shader.useShader();

	handleTransformForCollisionTesting();

	zebraTex.useTexture();
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(spaceShip.transform.GetModel()));
	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(camera.getProjection()));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.getView()));
	spaceShip.renderModel();

	redCamoTex.useTexture();
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(spaceShip2.transform.GetModel()));
	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(camera.getProjection()));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.getView()));
	spaceShip2.renderModel();

	marsTex.useTexture();
	mars.transform.rotateOnY(0.05f);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(mars.transform.GetModel()));
	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(camera.getProjection()));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.getView()));
	mars.renderModel();

	donutTex.useTexture();
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(ufo.transform.GetModel()));
	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(camera.getProjection()));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.getView()));
	ufo.renderModel();

	groundTex.useTexture();
	ground.CreateMesh(groundVertices, sizeof(groundVertices), groundIndices,sizeof(groundIndices));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(ground.transform.GetModel()));
	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(camera.getProjection()));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.getView()));

	ground.renderModel();

}
bool MainGame::collisionDetection(glm::vec3 posOne, float radOne, glm::vec3 posTwo, float radTwo)
{
	float distance = sqrt((posTwo.x - posOne.x)*(posTwo.x - posOne.x) + (posTwo.y - posOne.y)
					*(posTwo.y - posOne.y) + (posTwo.z - posOne.z)*(posTwo.z - posOne.z));

	if (distance < (radOne + radTwo))
	{
		std::cout << "COLLISIONNNNNN" << std::endl;
		audioSource.playSound(collision);
		return true;
	}
	else
	{
		false;
	}

}
void MainGame::handleTransformForCollisionTesting()
{
	// Just adding this way to implement quickly to show collision testing. If time rehaul to do properly.
	if (counter >= 0.5f)
		{
			moveUp = false;
			moveRight = false;
		}
		else if (counter <= 0)
		{
			moveUp = true;
			moveRight = true;
		}
		if (moveUp)
		{
			counter += 0.01;
			ufo.transform.SetPos(glm::vec3(ufo.transform.GetPos()->x, ufo.transform.GetPos()->y += 0.1f, ufo.transform.GetPos()->z));
		}
		else
		{
			counter -= 0.01f;
			ufo.transform.SetPos(glm::vec3(ufo.transform.GetPos()->x, ufo.transform.GetPos()->y -= 0.1f, ufo.transform.GetPos()->z));
		}
		ufo.transform.rotateOnY(0.05f);

		if (moveRight)
		{
			spaceShip.transform.SetPos(glm::vec3(spaceShip.transform.GetPos()->x, spaceShip.transform.GetPos()->y, spaceShip.transform.GetPos()->z -= 0.1f));
			spaceShip2.transform.SetPos(glm::vec3(spaceShip2.transform.GetPos()->x, spaceShip2.transform.GetPos()->y, spaceShip2.transform.GetPos()->z += 0.1f));
		}
		else
		{
			spaceShip.transform.SetPos(glm::vec3(spaceShip.transform.GetPos()->x, spaceShip.transform.GetPos()->y, spaceShip.transform.GetPos()->z += 0.1f));
			spaceShip2.transform.SetPos(glm::vec3(spaceShip2.transform.GetPos()->x, spaceShip2.transform.GetPos()->y, spaceShip2.transform.GetPos()->z -= 0.1f));
		}
}
void MainGame::processInput()
{
	SDL_Event event;


	while (SDL_PollEvent(&event) != 0) //get and process events
	{
		if(event.type == SDL_MOUSEMOTION)
		{

			GLfloat x, y;

			x = event.motion.xrel; // x equal to the relative x mouse motion
			y = event.motion.yrel; // y "" """

			if (firstMove) // check if initial move
			{
				lastXpos = x; // last pos = to start x pos
				lastYpos = y; // """ y pos
				firstMove = false; // initalised first move
			}
			changeInX = x - lastXpos; // change in motion is set to the x value minus last position
			changeInY = y - lastYpos;// "" "" y value ""
			camera.mouseMotion(changeInX, changeInY); // send to camera mouse motion to use to rotate the camera relative to the mouse position
		}
		else if (event.type == SDL_KEYDOWN)  // check for when a key event down has occurred
		{
			switch (event.key.keysym.sym) // switch through the keys
			{
			case SDLK_w: // W down
				keysDown[SDLK_w] = true; // set the enum for w in the keydown array to true to allow for cont movement/press down
				break;
			case SDLK_a:
				keysDown[SDLK_a] = true; // ""
				break;
			case SDLK_s:
				keysDown[SDLK_s] = true; // ""
				break;
			case SDLK_d:
				keysDown[SDLK_d] = true;//""
				break;
			case SDLK_RIGHT:
				if (skyboxNumber < 4)  //check the skybox number is below 4
				{
					skyboxNumber++; // condition met increase the number by 1 ( switching the skybox_)
				}
				else 
				{
					skyboxNumber = 0; // else return to the first skybox
				}
				audioSource.playSound(whoosh); // play the whoosh audio clip for key press
				break;
			case SDLK_LEFT:
				if (skyboxNumber > 0) // same as above only above 0
				{
					skyboxNumber--; // if so minus 1 , switching the skybox to previous
				}
				else
				{
					skyboxNumber = 4; // if not wrap round back to the last skybox
				}
				audioSource.playSound(whoosh); // play audio clip
				break;
		
			case SDLK_ESCAPE:
				gameState = GameStates::EXIT; // change the game state to exit which will call SDL QUIT and exit the application
				break;
			}
		}
		else if (event.type == SDL_KEYUP) 
		{
			switch (event.key.keysym.sym) 
			{
			case SDLK_w:
				keysDown[SDLK_w] = false; // same as above but checking for keys been up and returning the bool to false.
				break;
			case SDLK_a:
				keysDown[SDLK_a] = false;
				break;
			case SDLK_s:
				keysDown[SDLK_s] = false;
				break;
			case SDLK_d:
				keysDown[SDLK_d] = false;
				break;
			}

		}
	}
}
MainGame::~MainGame()
{
}
