#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "GameScene.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

	Sprite* background;
	Sprite* startButton;
	Sprite* title;

	void Render();
	void Update(float dTime);

	D3DXVECTOR2 Lerp(D3DXVECTOR2 p1, D3DXVECTOR2 p2, float power);

};

