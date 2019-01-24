#include "Player.h"

Player::Player(int x, int y, bool state) {
	idleTexture = IMG_LoadTexture(Globals::renderer, "Assets/T-Rex_Idle_V1.png");
	SDL_QueryTexture(idleTexture, NULL, NULL, &frameWidth, &frameHeight);
	idle = new Animation(idleTexture, Globals::renderer, 2, frameWidth/2, frameHeight, 0.7);

	runTexture = IMG_LoadTexture(Globals::renderer, "Assets/T-Rex_Running_V1.png");
	SDL_QueryTexture(runTexture, NULL, NULL, &frameWidth, &frameHeight);
	run = new Animation(runTexture, Globals::renderer, 2, frameWidth/2, frameHeight, 0.1);

	this->pos.x = x;
	this->pos.y = y - frameHeight;
	inGame = state;
	gravity = 5000;
}

Player::~Player() {
	SDL_DestroyTexture(idleTexture);
	SDL_DestroyTexture(runTexture);
	delete idle;
	delete run;
}


void Player::update(float dt) {
	updateMovement(dt);

	if (inGame) {
		run->update(dt);
		if (vel.y == 0) {
			run->frameDuration = 0.1;
		}
		else if (vel.y != 0) {
			run->frameDuration = 1;
		}
	}
	else {
		if (vel.x != 0 && vel.y == 0) {
			run->frameDuration = 0.1;
			run->update(dt);
		}
		else if (vel.y != 0) {
			run->frameDuration = 1;
			run->update(dt);
		}
		else
			idle->update(dt);

		isFlip();
		checkPlayerBoundry();
	}

	initialGravity(dt);
	if (pos.y < 600) {
		vel.y += gravity * dt;
		isGround = false;
	}
	else if (pos.y >= 600 && !isGround) {
		isGround = true;
		vel.y = 0;
		pos.y = 600;
	}
}

void Player::draw(bool) {
	if (inGame) {
		run->draw(pos.x, pos.y);
	}
	else {
		if (vel.x != 0) {
			run->draw(pos.x, pos.y, faceLeft);
		}
		else
			idle->draw(pos.x, pos.y, faceLeft);
	}
}

void Player::setupSprite(int dt) {
}

// Check if the player need to be flip
void Player::isFlip() {
	if (vel.x > 0)
		faceLeft = false;
	else if (vel.x < 0)
		faceLeft = true;
}

void Player::initialGravity(int dt){
}

// Reset Player position if move out of the screen
void Player::checkPlayerBoundry() {
	if (pos.x < -228)
		pos.x = 1380;
	if (pos.x > 1380)
		pos.x = -228;
}