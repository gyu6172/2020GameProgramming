#include "stdafx.h"
#include "Player.h"
#include "Scene.h"
using namespace std;

Player::Player(int code){
	isJump = false;
	gravity = 9.8;
	launch = 0;
	playerCode = code;

	up_down = true;

	int jumpNumber = 1;

	playerAnimation = new Animation(3);
	if(playerCode==0){
		playerAnimation->AddFrame("Resources/Images/bird1_2.png");
		playerAnimation->AddFrame("Resources/Images/bird1_3.png");
		playerAnimation->AddFrame("Resources/Images/bird1_2.png");
		playerAnimation->AddFrame("Resources/Images/bird1_1.png");
	}
	else if (playerCode == 1) {
		playerAnimation->AddFrame("Resources/Images/bird2_2.png");
		playerAnimation->AddFrame("Resources/Images/bird2_3.png");
		playerAnimation->AddFrame("Resources/Images/bird2_2.png");
		playerAnimation->AddFrame("Resources/Images/bird2_1.png");
	}
	else if (playerCode == 2) {
		playerAnimation->AddFrame("Resources/Images/bird3_2.png");
		playerAnimation->AddFrame("Resources/Images/bird3_3.png");
		playerAnimation->AddFrame("Resources/Images/bird3_2.png");
		playerAnimation->AddFrame("Resources/Images/bird3_1.png");
	}
	else if (playerCode == 3) {
		playerAnimation->AddFrame("Resources/Images/bird4_2.png");
		playerAnimation->AddFrame("Resources/Images/bird4_3.png");
		playerAnimation->AddFrame("Resources/Images/bird4_2.png");
		playerAnimation->AddFrame("Resources/Images/bird4_1.png");
	}
	
	AddChild(playerAnimation);

	rect = playerAnimation->getRect();

	setScaleCenter(D3DXVECTOR2(playerAnimation->getWidth() / 2, playerAnimation->getHeight() / 2));
}

Player::~Player()
{
}

void Player::Render(){
	Object::Render();
	playerAnimation->Render();
}

void Player::Update(float dTime){
	if (playerCode == 0) {
		gravity += 20.0f;

		setPos(getPosX(), getPosY() + gravity * dTime);

		if (isJump) {
			setPos(getPosX(), getPosY() - 340 * dTime);
		}

		if (inputmanager->GetKeyState(VK_SPACE) == KEY_DOWN) {
			gravity = 0;
			isJump = true;
		}
	}

	else if (playerCode == 1) {
		int gravity = 300;

		if (inputmanager->GetKeyState(VK_SPACE) == KEY_ON) {
			gravity = -300;
		}

		setPos(getPosX(), getPosY() + gravity*dTime);

	}

	else if (playerCode == 2) {
		gravity += 20.0f;
		if (inputmanager->GetKeyState(VK_SPACE) == KEY_DOWN) {
			gravity = 0;
			up_down = !up_down;
		}

		if (up_down) {
			setScale(D3DXVECTOR2(1,1));
			setPos(getPosX(), getPosY() + gravity * dTime);
		}
		else {
			setScale(D3DXVECTOR2(1, -1));
			setPos(getPosX(), getPosY() - gravity * dTime);
		}
	}

	else if (playerCode == 3) {
		gravity += 15.0f;
		
		if (inputmanager->GetKeyState(VK_SPACE) == KEY_ON) {
			launch += 15.0f;
			gravity -= 40.0f;
		}
		else {
			launch -= 25.0f;
		}
		if (launch <= 0) {
			launch = 0;
		}
		if (gravity <= 0) {
			gravity = 0;
		}
		setPos(getPosX(), getPosY() + gravity * dTime - launch*dTime);
	}


	playerAnimation->Update(dTime);
}

int Player::getPlayerHeight()
{
	return playerAnimation->getHeight();
}

int Player::getPlayerWidth() {
	return playerAnimation->getWidth();
}


void Player::setCode(int code){
	playerCode = code;
}

int Player::getCode()
{
	return playerCode;
}
