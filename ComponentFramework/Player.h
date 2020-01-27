#ifndef OBJECT_H
#define OBJECT_H
#include <glew.h>
#include "Matrix.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "GameObject.h"
#include "PhysicsObject.h"
#include "Window.h"

using namespace MATH;


class Player : public PhysicsObject, public GameObject {	

private:
	Matrix4 modelMatrix;
	GLuint modelMatrixID;
	GLuint normalMatrixID;
	Mesh *mesh;
	Shader *shader;
	Texture *texture;

public:
	Player(Mesh *mesh_, Shader *shader_, Texture *texture_);
	~Player();
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update(const float deltaTime_);
	virtual void Render() const;
	virtual void HandleEvents(const SDL_Event &event);


	inline Shader* getShader() const { return shader; }
	inline void setModelMatrix(const Matrix4 &modelMatrix_) { modelMatrix = modelMatrix_; }
	inline const Matrix4& getModelMatrix() { return modelMatrix; }

	void UpdateInput(Window& window, Vec3& pos);
};

#endif

