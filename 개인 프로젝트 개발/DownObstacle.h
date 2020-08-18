#pragma once
#include "Object.h"
#include "Sprite.h"
class DownObstacle :
	public Object
{
private:
	Sprite* downobstacle;
public:
	DownObstacle();
	~DownObstacle();

	void Render();
	void Update(float dTime);
};

