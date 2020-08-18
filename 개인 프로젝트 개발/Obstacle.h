#pragma once
#include "Object.h"
#include "Sprite.h"

class Obstacle :
	public Object
{
private:
	Sprite* obstacle;
public:
	Obstacle(char code);
	~Obstacle();

	void Render();
	void Update(float dTime);
};

