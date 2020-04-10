#include "Obstacle.h"

#include "MMath.h"

Obstacle::Obstacle() {
	Vec3 pos(0, 0, 0);
	Vec3 vel(0, 0, 0);
	Vec3 accel(0, 0, 0);

	mass = 500.0f;
}
Obstacle::Obstacle(Mesh* mesh_, Shader* shader_, Texture* texture_) :
	mesh(mesh_), shader(shader_), texture(texture_) {

	modelMatrixID = shader->getUniformID("modelMatrix");
	normalMatrixID = shader->getUniformID("normalMatrix");
}

Obstacle::~Obstacle() {}

bool Obstacle::OnCreate() { return true; } /// Just a stub
void Obstacle::OnDestroy() {}				  /// Just a stub
void Obstacle::Update(float deltaTime_) {} /// Just a stub

void Obstacle::Render() const {

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

void Obstacle::HandleEvents(const SDL_Event& event) {} /// Just a stub