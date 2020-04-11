#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <glew.h>
#include "Matrix.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "GameObject.h"
#include "PhysicsObject.h"

using namespace MATH;


class Obstacle : public PhysicsObject, public GameObject {

private:
	Vec3 pos, vel, accel;
	float mass;

	Matrix4 modelMatrix;
	GLuint modelMatrixID;
	GLuint normalMatrixID;
	Mesh* mesh;
	Shader* shader;
	Texture* texture;

public:
	Obstacle(Mesh* mesh_, Shader* shader_, Texture* texture_);
	~Obstacle();
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update(const float deltaTime_);
	virtual void Render() const;
	virtual void HandleEvents(const SDL_Event& event);


	inline Shader* getShader() const { return shader; }
	inline void setModelMatrix(const Matrix4& modelMatrix_) { modelMatrix = modelMatrix_; }
	inline const Matrix4& getModelMatrix() { return modelMatrix; }

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

