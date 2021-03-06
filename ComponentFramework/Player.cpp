#include "Player.h"
#include "MMath.h"
#include "Physics.h"

Player::Player(Mesh* mesh_, Shader* shader_, Texture* texture_) :
	mesh(mesh_), shader(shader_), texture(texture_) {

	modelMatrixID = shader->getUniformID("modelMatrix");
	normalMatrixID = shader->getUniformID("normalMatrix");

	Vec3 pos(0, 0, 0);
	Vec3 vel(0, 0, 0);
	Vec3 accel(0, 0, 0);
	mass = 100.0f;
}

Player::~Player() {}

bool Player::OnCreate() { return true; } /// Just a stub
void Player::OnDestroy() {}  /// Just a stub

void Player::Update(float deltaTime_) {} /// Just a stub

void Player::Render() const {

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

void Player::HandleEvents(SDL_Event& event) {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			//get the pressed key of the player
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_w:
				vel.y += 1;
				if (vel.y >= 5) { vel.y -= 1; }
				break;
			case SDLK_a:
				vel.x -= 1;
				break;
			case SDLK_s:
				vel.y -= 1;
				if (vel.y <= 0) { vel.y = 0; }
				break;
			case SDLK_d:
				vel.x += 1;
				break;
			default:
				break;
			}
			break;

			// we wann use key up to set the velocity to zero so the player stops moving when we let go of the key.
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_w:
				vel.y = 0;
				break;
			case SDLK_a:
				vel.x = 0;
				break;
			case SDLK_s:
				vel.y = 0;
				break;
			case SDLK_d:
				vel.x = 0;
				break;
			default:
				break;
			}
		}
	}
	pos.x += vel.x;
	pos.y += vel.y;

} /// Just a stub