#pragma once
#include "Object.h"
#include "Animation.h"

class Player :
	public Object
{
private:
	Animation* playerAnimation;
	float gravity = 0;
	bool isJump = false;
	bool doubleJump = false;

public:
	Player();
	~Player();

	void Render();
	void Update(float dTime);
};

