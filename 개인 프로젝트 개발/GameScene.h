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
#include "Obstacle.h"
#include <list>

class GameScene :
	public Scene
{
private:

	int score;
	bool canScore;
	bool backgroundInstatics;
	bool bridgeInstatics;
	bool obstacleInstatics;

	float timer;
	
	std::list<Background*> backgroundList;
	std::list<Bridge*> bridgeList;
	std::list<Obstacle*> downObstacleList;
	std::list<Obstacle*> upObstacleList;

	Number scoreArray[3];
	Player* player;

public:
	GameScene();
	~GameScene();

	void Render();
	void Update(float dTime);
};

