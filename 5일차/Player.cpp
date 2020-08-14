#include "stdafx.h"
#include "Player.h"

Player::Player(){
	isJump = false;
	doubleJump = false;
	gravity = 9.8;

	playerAnimation = new Animation(2);
	playerAnimation->AddFrame("Resources/Images/player-run.png");
	playerAnimation->AddFrame("Resources/Images/player-stop.png");
	AddChild(playerAnimation);

	rect = playerAnimation->getRect();
}

Player::~Player()
{
}

void Player::Render(){
	Object::Render();
	playerAnimation->Render();
}

void Player::Update(float dTime){
	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);

	if (isJump) {
		setPos(getPosX(), getPosY() - 350 * dTime);

		if (doubleJump) {
			setPos(getPosX(), getPosY() - 350 * dTime);
		}

		if (inputmanager->GetKeyState(VK_SPACE) == KEY_DOWN) {
			doubleJump = true;
		}
	}

	if (getPosY() > 320) {
		setPos(getPosX(), 320);
		doubleJump = false;
		isJump = false;
	}

	if (inputmanager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		if (getPosY() == 320) {
			isJump = true;
			gravity = 0;
		}
	}

	playerAnimation->Update(dTime);
}
