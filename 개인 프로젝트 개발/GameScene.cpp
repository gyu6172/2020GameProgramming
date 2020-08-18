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
	int random = rand() % 566 + 30;

	Obstacle* upObstacle = new Obstacle('u');
	upObstacle->setPos(SCREEN_WIDTH, random-900);
	upObstacleList.push_back(upObstacle);
	AddObject(upObstacle);

	Obstacle* downObstacle = new Obstacle('d');
	downObstacle->setPos(SCREEN_WIDTH, random+180);
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
		scoreArray[i].setPos((SCREEN_WIDTH / 2) + i * 80, 10);
	}


	/*Sprite* tempBridge = new Sprite("Resources/Images/bg_bridge.png");
	tempBridge->setPos(SCREEN_WIDTH, 805);
	bridgeList.push_back(tempBridge);*/

	////---------------------------------------------------------------------------
	////内牢 积己
	//Sprite* tmpCoin = new Sprite("Resources/Images/coin-yellow.png");
	//tmpCoin->setPos(SCREEN_WIDTH + 70, 350);
	//coinList.push_back(tmpCoin);
	////---------------------------------------------------------------------------
	////厘局拱 积己
	//Sprite* tmpObstacle = new Sprite("Resources/Images/Drop.png");
	//tmpObstacle->setPos(SCREEN_WIDTH, 400);
	//obstacleList.push_back(tmpObstacle);
	////-----------------------------------------------------------------	
	////痢荐魄
	//for (int i = 0; i < 4; i++) {
	//	numArray[i].setPos(60 * i, 10);
	//}
	////-------------------------------------------------------------
	//敲饭捞绢 积己
	player = new Player();
	player->setPos(200, 0);
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
	//for (auto& coin : coinList) {
	//	coin->Render();
	//}
	//for (int i = 0; i < 4; i++) {
	//	numArray[i].Render();
	//}

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

		int random = rand() % 566 + 30;

		Obstacle* upObstacle = new Obstacle('u');
		upObstacle->setPos(SCREEN_WIDTH, random - 900);
		upObstacleList.push_back(upObstacle);
		AddObject(upObstacle);

		Obstacle* downObstacle = new Obstacle('d');
		downObstacle->setPos(SCREEN_WIDTH, random + 180);
		downObstacleList.push_back(downObstacle);
		AddObject(downObstacle);
	}
	//---------------------------------------------------------------------------------
	//厘局拱 昏力
	for (auto iter = upObstacleList.begin(); iter != upObstacleList.end(); iter++) {
		if (player->getPosX() == (*iter)->getPosX()+120) {
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



	//for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {

	//	(*iter)->setPos((*iter)->getPosX(),
	//		(*iter)->getPosY());

	//	if ((*iter)->IsCollisionRect(player)) {
	//		sceneManager->ChangeScene(new MainScene());
	//		return;
	//	}


	//	if ((*iter)->getPosX() < -SCREEN_WIDTH) {
	//		SAFE_DELETE(*iter);
	//		iter = obstacleList.erase(iter);


	//		if (iter == obstacleList.end()) {
	//			break;
	//		}
	//	}
	//}

	//---------------------------------------------------------------

	//for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {

	//	(*iter)->setPos((*iter)->getPosX() - diff,
	//		(*iter)->getPosY());

	//	if ((*iter)->getPosX() < -SCREEN_WIDTH) {
	//		SAFE_DELETE(*iter);
	//		iter = coinList.erase(iter);

	//		if (iter == coinList.end()) {
	//			break;
	//		}
	//	}

	//}

	//for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {

	//	if (player->IsCollisionRect((*iter))) {
	//		score += 1;
	//		SAFE_DELETE(*iter);
	//		iter = coinList.erase(iter);

	//		if (iter == coinList.end()) {
	//			break;
	//		}
	//	}
	//}
}

