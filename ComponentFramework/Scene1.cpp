#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene1.h"
#include "Camera.h"
#include "Spaceship.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Debug.h"
#include "Physics.h"

Scene1::Scene1() : camera(nullptr), spaceship(nullptr), meshPtr(nullptr), shaderPtr(nullptr), texturePtr(nullptr) {
	Debug::Info("Created Scene1: ", __FILE__, __LINE__);
}

Scene1::~Scene1() {}

bool Scene1::OnCreate() {
	camera = new Camera();
	lightSource1 = Vec3(0.0, -5.0, -5.0);
	lightSource2 = Vec3(0.0, 5.0, 5.0);

	if (ObjLoader::loadOBJ("meshes/F-16C.obj") == false) {
		return false;
	}
	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("multiPhongVert.glsl", "multiPhongFrag.glsl");
	texturePtr = new Texture();
	if (meshPtr == nullptr || shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}


	/*if (texturePtr->LoadImage("textures/mario_main.png") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}*/

	spaceship = new Spaceship(meshPtr, shaderPtr, nullptr);
	if (spaceship == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	spaceship->setPos(Vec3(-5.0, 0.0, 0.0));
	spaceship->setModelMatrix(MMath::translate(spaceship->getPos()) * MMath::rotate(100.0f, Vec3(0.0f, 1.0f, 0.0f)));

	return true;
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent) {

}

void Scene1::Update(const float deltaTime) {
	spaceship->Update(deltaTime);
	


}

void Scene1::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = spaceship->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(spaceship->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(spaceship->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(spaceship->getShader()->getUniformID("lightPos"), 1, lightSource1);
	glUniform3fv(spaceship->getShader()->getUniformID("lightPos2"), 1, lightSource2);

	spaceship->Render();

	glUseProgram(0);
}


void Scene1::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (spaceship) delete spaceship, spaceship = nullptr;
}
