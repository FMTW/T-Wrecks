#include "Player.h"

Player::Player(int x, int y) {
	animatedSurface = IMG_Load("Assets/T-Rex_Idle.png");
	
	playerTexture = SDL_CreateTextureFromSurface(Globals::renderer, animatedSurface);
	SDL_FreeSurface(animatedSurface);

	idle = new Animation(playerTexture, Globals::renderer, 2, frameWidth, frameHeight, 0.7);

	animatedSurface = IMG_Load("Assets/T-Rex_Running.png");

	playerTexture = SDL_CreateTextureFromSurface(Globals::renderer, animatedSurface);
	SDL_FreeSurface(animatedSurface);

	run = new Animation(playerTexture, Globals::renderer, 2, frameWidth, frameHeight, 0.1);

	this->pos.x = x;
	this->pos.y = y;
}

Player::~Player() {
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
	if (pos.y < 560) {
		vel.y += gravity * dt;
		isGround = false;
	}
	else if (pos.y >= 560 && !isGround) {
		isGround = true;
		vel.y = 0;
		pos.y = 560;
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