#include "stdafx.h"
#include "GameScene.h"

using namespace std;

GameScene::GameScene(){
	score = 0;
	timer = 0;
	canScore = false;
	backgroundInstatics = false;
	bridgeInstatics = false;
	obstacleInstatics = false;

	Background* background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);
	//--------------------------------------------------------------------
	//厘局拱 积己
	int heightRand = rand() % 566 + 30;
	int diffRand = rand() % 61 + 140;

	Obstacle* upObstacle = new Obstacle('u');
	upObstacle->setPos(SCREEN_WIDTH, heightRand-900);
	upObstacleList.push_back(upObstacle);
	AddObject(upObstacle);

	Obstacle* downObstacle = new Obstacle('d');
	downObstacle->setPos(SCREEN_WIDTH, heightRand+diffRand);
	downObstacleList.push_back(downObstacle);
	AddObject(downObstacle);
	//--------------------------------------------------------------------------
	//促府 积己
	Bridge* bridge = new Bridge();
	bridge->setPos(0, 805);
	bridgeList.push_back(bridge);
	AddObject(bridge);
	//----------------------------------------------------------------------------
	//痢荐 积己
	for (int i = 0; i < 3; i++) {
		scoreArray[i].setPos(SCREEN_WIDTH / 2 - 80 - (scoreArray[i].getWidth(i)) + i * 80, 10);
	}

	////-------------------------------------------------------------
	//敲饭捞绢 积己
	int playerRand = rand() % 4;
	player = new Player(playerRand);
	player->setPos(200, 100);
}

GameScene::~GameScene(){

}

void GameScene::Render(){
	for (auto& background : backgroundList) {
		background->Render();
	}
	for (auto& bridge : bridgeList) {
		bridge->Render();
	}
	for (auto& downobstacle : downObstacleList) {
		downobstacle->Render();
	}
	for (auto& upobstacle : upObstacleList) {
		upobstacle->Render();
	}
	for (int i = 0; i < 3; i++) {
		scoreArray[i].Render();
	}

	player->Render();


}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);
	player->Update(dTime);

	scoreArray[0].setNum(score % 1000 / 100);
	scoreArray[1].setNum(score % 100 / 10);
	scoreArray[2].setNum(score % 10);

	//------------------------------硅版 积己----------------------------------------------
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {

			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			backgroundInstatics = false;

			if (iter == backgroundList.end()) {
				break;
			}
		}

	}
	if (!backgroundInstatics) {
		Background* background = new Background();
		background->setPos(SCREEN_WIDTH-10, 0);
		backgroundList.push_back(background);
		AddObject(background);
		backgroundInstatics = true;
	}

	//-----------------------------------促府 积己-----------------------------------------
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);
			bridgeInstatics = false;
		}
	}
	if (!bridgeInstatics) {
		Bridge* bridge= new Bridge();
		bridge->setPos(SCREEN_WIDTH - 10, 805);
		bridgeList.push_back(bridge);
		AddObject(bridge);
		bridgeInstatics = true;
	}

	//------------------------厘局拱 积己-------------------------------------------------
	timer += dTime;
	if (timer > 2.5) {
		timer = 0;

		int heightRand = rand() % 566 + 30;
		int diffRand = rand() % 61 + 140;

		Obstacle* upObstacle = new Obstacle('u');
		upObstacle->setPos(SCREEN_WIDTH, heightRand - 900);
		upObstacleList.push_back(upObstacle);
		AddObject(upObstacle);

		Obstacle* downObstacle = new Obstacle('d');
		downObstacle->setPos(SCREEN_WIDTH, heightRand + diffRand);
		downObstacleList.push_back(downObstacle);
		AddObject(downObstacle);
	}
	//---------------------------------------------------------------------------------
	//厘局拱 昏力
	for (auto iter = upObstacleList.begin(); iter != upObstacleList.end(); iter++) {
		
		if (player->getPosX()-1 <= int((*iter)->getPosX()+120) && int((*iter)->getPosX() + 120) <= player->getPosX()+1) {
			score++;
		}

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = upObstacleList.erase(iter);
		}
	}
	for (auto iter = downObstacleList.begin(); iter != downObstacleList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = downObstacleList.erase(iter);
		}
	}
	//---------------------------------------------------------------
	//面倒眉农
	int playerHeight = player->getPlayerHeight();
	if ((player->getPosY() < 0) || (player->getPosY()+playerHeight > 805)) {
		sceneManager->ChangeScene(new EndScene(score));
		return;
	}
	for (auto check = upObstacleList.begin(); check != upObstacleList.end(); check++) {
		if (player->IsCollisionRect((*check))) {
			sceneManager->ChangeScene(new EndScene(score));
			return;
		}
	}
	for (auto check = downObstacleList.begin(); check != downObstacleList.end(); check++) {
		if (player->IsCollisionRect((*check))) {
			sceneManager->ChangeScene(new EndScene(score));
			return;
		}
	}
	//---------------------------------------------------------
}

