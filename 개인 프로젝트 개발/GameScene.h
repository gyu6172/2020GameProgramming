#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include "EndScene.h"
#include "Number.h"
#include "Player.h"
#include "Background.h"
#include "Bridge.h"
#include <list>

class GameScene :
	public Scene
{
private:

	int score;
	float playtime;
	bool backgroundInstatics;
	bool bridgeInstatics;

	std::list<Background*> backgroundList;
	std::list<Bridge*> bridgeList;
	std::list<Sprite*> obstacleList;
	std::list<Sprite*> coinList;

	Number numArray[4];
	Player* player;

public:
	GameScene();
	~GameScene();

	void Render();
	void Update(float dTime);


};

