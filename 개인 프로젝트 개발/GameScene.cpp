#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene(){
	score = 0;
	backgroundInstatics = false;
	bridgeInstatics = false;

	Background* background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	//--------------------------------------------------------------------------
	//促府 积己
	Bridge* bridge = new Bridge();
	bridge->setPos(0, 805);
	bridgeList.push_back(bridge);
	AddObject(bridge);

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
	//for (auto& obstacle : obstacleList) {
	//	obstacle->Render();
	//}
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

	//int coinRandNum = rand() % 10 + 1;
	//if (coinRandNum == 1) {
	//	Sprite* tmpCoin = new Sprite("Resources/Images/coin-yellow.png");
	//	tmpCoin->setPos(SCREEN_WIDTH + 70, 350);
	//	coinList.push_back(tmpCoin);
	//}
	//int obstacleRandNum = rand() % 200 + 1;
	//if (obstacleRandNum == 1) {
	//	Sprite* tmpObstacle = new Sprite("Resources/Images/Drop.png");
	//	tmpObstacle->setPos(SCREEN_WIDTH, 400);
	//	obstacleList.push_back(tmpObstacle);
	//}
	//numArray[0].setNum(score / 1000);
	//numArray[1].setNum(score % 1000 / 100);
	//numArray[2].setNum(score % 100 / 10);
	//numArray[3].setNum(score % 10);

	player->Update(dTime);

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

			if (iter == bridgeList.end()) {
				break;
			}
		}
	}
	if (!bridgeInstatics) {
		Bridge* bridge= new Bridge();
		bridge->setPos(SCREEN_WIDTH - 10, 805);
		bridgeList.push_back(bridge);
		AddObject(bridge);
		bridgeInstatics = true;
	}

	//---------------------------------------------------------------

	//for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {

	//	(*iter)->setPos((*iter)->getPosX() - diff,
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
