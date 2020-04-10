#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene0.h"
#include "Camera.h"
#include "Player.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Debug.h"
#include "Physics.h"
#include "Spaceship.h"


Scene0::Scene0(): camera(nullptr), player(nullptr), meshPtr(nullptr), shaderPtr(nullptr), texturePtr(nullptr) {
	Debug::Info("Created Scene0: ", __FILE__, __LINE__);
}

Scene0::~Scene0() {}

bool Scene0::OnCreate() {
	camera = new Camera();
	lightSource = Vec3(0.0, 0.0, 10.0);

	if (ObjLoader::loadOBJ("meshes/Mario.obj") == false) {
		return false;
	}
	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("textureVert.glsl", "textureFrag.glsl");
	texturePtr = new Texture();
	if (meshPtr == nullptr|| shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}


	if (texturePtr->LoadImage("textures/mario_main.png") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}

	player = new Player(meshPtr, shaderPtr, texturePtr);

	if (player == nullptr) {
		Debug::FatalError("Player cannot be created!", __FILE__, __LINE__);
		return false;
	}
	return true;
}

void Scene0::HandleEvents(const SDL_Event &sdlEvent) {
	//player->HandleEvents(sdlEvent);

}

void Scene0::Update(const float deltaTime) {
	player->Update(deltaTime); 
	
	
}

void Scene0::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = player->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(player->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(player->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(player->getShader()->getUniformID("lightPos"), 1, lightSource);

	player->Render();

	glUseProgram(0);
}


void Scene0::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (player) delete player, player = nullptr;
}
