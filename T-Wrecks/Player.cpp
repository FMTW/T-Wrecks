#include "Player.h"

Player::Player(int x, int y) {
	idleTexture = IMG_LoadTexture(Globals::renderer, "Assets/T-Rex_Idle_V1.png");
	SDL_QueryTexture(idleTexture, NULL, NULL, &frameWidth, &frameHeight);
	idle = new Animation(idleTexture, Globals::renderer, 2, frameWidth/2, frameHeight, 0.7);

	runTexture = IMG_LoadTexture(Globals::renderer, "Assets/T-Rex_Running_V1.png");
	SDL_QueryTexture(runTexture, NULL, NULL, &frameWidth, &frameHeight);
	run = new Animation(runTexture, Globals::renderer, 2, frameWidth/2, frameHeight, 0.1);

	this->pos.x = x;
	this->pos.y = y - frameHeight;
}

Player::~Player() {
	SDL_DestroyTexture(idleTexture);
	SDL_DestroyTexture(runTexture);
	delete idle;
	delete run;
}


void Player::update(float dt) {
	updateMovement(dt);

	setAnimation(dt);
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

	checkPlayerBoundry();
}

void Player::draw(bool) {
	if (vel.x != 0 && vel.y == 0) {
		run->draw(pos.x, pos.y, isFlipped);
	}
	else if (vel.y != 0) {
		run->draw(pos.x, pos.y, isFlipped);
	}
	else
		idle->draw(pos.x, pos.y, isFlipped);
}

void Player::setAnimation(int dt) {
}

void Player::isFlip() {
	if (vel.x > 0)
		isFlipped = false;
	else if (vel.x < 0)
		isFlipped = true;
}

void Player::initialGravity(int dt){
}

void Player::checkPlayerBoundry() {
	if (pos.x < -228)
		pos.x = 1380;
	if (pos.x > 1380)
		pos.x = -228;
}