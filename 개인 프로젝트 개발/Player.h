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
	bool isJump = false;
	bool doubleJump = false;

	int jumpNumber = 1;


public:
	Player();
	~Player();

	void Render();
	void Update(float dTime);

	int getPlayerHeight();
};

