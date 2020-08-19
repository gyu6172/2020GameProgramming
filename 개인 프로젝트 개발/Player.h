#pragma once
#include "Object.h"
#include "Animation.h"
#include "EndScene.h"
class Player :
	public Object
{
private:
	Animation* playerAnimation;
	float gravity = 0;
	float launch = 0;
	bool isJump = false;
	bool up_down;

	int playerCode;
	int jumpNumber = 1;


public:
	Player(int code);
	~Player();

	void Render();
	void Update(float dTime);

	int getPlayerHeight();
	int getPlayerWidth();

	void setCode(int code);
	int getCode();
};

