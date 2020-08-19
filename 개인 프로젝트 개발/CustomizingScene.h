#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "MainScene.h"

class CustomizingScene:
	public Scene
{
public:

	Sprite* background;
	Sprite* nextButton;
	Sprite* previousButton;

	CustomizingScene();
	~CustomizingScene();

	void Render();
	void Update(float dTime);
};

