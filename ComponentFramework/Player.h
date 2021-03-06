#ifndef PLAYER_H
#define PLAYER_H
#include <glew.h>
#include <SDL.h>
#include "Matrix.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "GameObject.h"
#include "PhysicsObject.h"

using namespace MATH;


class Player : public PhysicsObject {

private:
	Matrix4 modelMatrix;
	GLuint modelMatrixID;
	GLuint normalMatrixID;
	Mesh* mesh;
	Shader* shader;
	Texture* texture;

	Vec3 pos, vel, accel;
	float mass;
	Sphere boundingSphere;

public:
	Player(Mesh* mesh_, Shader* shader_, Texture* texture_);
	~Player();
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update(const float deltaTime_);
	virtual void Render() const;
	virtual void HandleEvents(SDL_Event& event);


	inline Shader* getShader() const { return shader; }
	inline void setModelMatrix(const Matrix4& modelMatrix_) { modelMatrix = modelMatrix_; }
	inline Matrix4& getModelMatrix() { return modelMatrix; }
	
	inline void setPos(Vec3& pos_) { pos = pos_; }
	inline Vec3 getPos() { return pos; }
	inline void setVel(Vec3& vel_) { vel = vel_; }
	inline Vec3 getVel() { return vel; }
	inline void setAccel(Vec3& accel_) { accel = accel_; }
	inline Vec3 getAccel() { return accel; }

	inline void setMass(float mass_) { mass = mass_; }
	inline float getMass() { return mass; }
};

#endif


