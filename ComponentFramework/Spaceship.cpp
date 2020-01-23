#include "Spaceship.h"
#include "MMath.h"
#include "Physics.h"

Spaceship::Spaceship(Mesh* mesh_, Shader* shader_, Texture* texture_) :
	mesh(mesh_), shader(shader_), texture(texture_) {

	modelMatrixID = shader->getUniformID("modelMatrix");
	normalMatrixID = shader->getUniformID("normalMatrix");
}

Spaceship::~Spaceship() {}

bool Spaceship::OnCreate() { return true; } /// Just a stub
void Spaceship::OnDestroy() {}				  /// Just a stub

void Spaceship::Update(float deltaTime_) {
	spaceTime += deltaTime_;

	if (spaceTime <= 1.0f) {
		this->applyForce(Vec3(0.5f, 0.0f, 0.0f));
		Physics::SimpleNewtonMotion(*this, deltaTime_);
		this->setModelMatrix(MMath::translate(pos));
	}
	else if (spaceTime >= 1.0f) {
		
		this->ApplyTorque(10.0f);
		this->applyForce(MMath::rotate(angle, Vec3(0.0f, 0.5f, 0.0f)) * Vec3(0.5f, 0.0f, 0.0f));

		Physics::SimpleNewtonMotion(*this, deltaTime_);
		this->setModelMatrix(MMath::translate(pos) * MMath::rotate(angle, Vec3(0.0f, 0.5f, 0.5f)));
		Physics::RigidbodyRotation(*this, deltaTime_);
	}
	else if (spaceTime > 1.5f) {
		this->setModelMatrix(MMath::rotate(angle, Vec3(0.0f, 1.0, 0.0f)));
		this->ApplyTorque(0.0f);

		this->setAngularAccel(0.0f);
		this->setAngularVel(0.0f);

		Physics::SimpleNewtonMotion(*this, deltaTime_);
		Physics::RigidbodyRotation(*this, deltaTime_);
		
	}

} /// Just a stub

void Spaceship::Render() const {

	/// This is some fancy code.  Assigning a 4x4 matrix to a 3x3 matrix
	/// just steals the upper 3x3 of the 4x4 and assigns thoses values 
	/// to the 3x3.  
	Matrix3 normalMatrix = MMath::transpose(MMath::inverse(modelMatrix));

	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, modelMatrix);
	glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);
	if (texture) {
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	}

	mesh->Render();

	/// Unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Spaceship::HandleEvents(const SDL_Event& event) {} /// Just a stub