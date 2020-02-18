#include "Player.h"

#include "MMath.h"

Player::Player(Mesh *mesh_, Shader *shader_, Texture *texture_): 
	mesh(mesh_), shader(shader_), texture(texture_) {

	modelMatrixID = shader->getUniformID("modelMatrix");
	normalMatrixID = shader->getUniformID("normalMatrix");
}

Player::~Player() {}

bool Player::OnCreate() { return true;  } /// Just a stub
void Player::OnDestroy() {}				  /// Just a stub
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

void Player::HandleEvents(SDL_Event& sdlEvent) {
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
			//get the pressed key of the player
		case SDL_KEYDOWN:
			switch (sdlEvent.key.keysym.sym) {
			case SDLK_a:
				//move player according to keys pressed, so something like:
				//player.vel -= 1;
				break;
			case SDLK_d:
				//player.vel += 1;
				break;
			case SDLK_w:
				//player.vel -= 1;
				break;
			case SDLK_s:
				//player.vel += 1;
				break;
			case SDLK_SPACE:
				//set jump code here
				break;
			case SDLK_LCTRL:
				//set crouch code here if we want to crouch 
				break;
			default:
				break;
			}
			break;

			// we wann use key up to set the velocity to zero so the player stops moving when we let go of the key.
		case SDL_KEYUP:
			switch (sdlEvent.key.keysym.sym) {
			case SDLK_a:
				//move player according to keys pressed, so something like:
				//player.vel = 0;
				break;
			case SDLK_d:
				//player.vel = 0;
				break;
			case SDLK_w:
				//player.vel = 0;
				break;
			case SDLK_s:
				//player.vel = 0;
				break;
			case SDLK_SPACE:
				//set jump code here
				break;
			case SDLK_LCTRL:
				//set crouch code here if we want to crouch 
				break;
			default:
				break;
			}
		}
	}
}
