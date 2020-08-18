#include "stdafx.h"
#include "EndScene.h"
#include "MainScene.h"

D3DXVECTOR2 EndScene::Lerp(D3DXVECTOR2 p1, D3DXVECTOR2 p2, float power)
{
	return p1 + (p2 - p1) * power;
}
EndScene::EndScene(){
	score = 0;
	playtime = 0;

	background = new Sprite("Resources/Images/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	gameoverTitle = new Sprite("Resources/Images/GameOverTitle.png");
	AddObject(gameoverTitle);
	gameoverTitle->setPos(SCREEN_WIDTH / 2, 100);

	startButton = new Sprite("Resources/Images/start_button.png");
	AddObject(startButton);
	startButton->setScaleCenter(D3DXVECTOR2(startButton->getWidth() / 2, startButton->getHeight() / 2));
	startButton->setPos(SCREEN_WIDTH / 2, 400);

	for (int i = 0; i < 3; i++) {
		playtimeArray[i].setPos((SCREEN_WIDTH / 2) + (i*70), 250);
	}
}

EndScene::~EndScene(){

}

void EndScene::Render(){
	background->Render();
	gameoverTitle->Render();
	startButton->Render();
	for (int i = 0; i < 3; i++) {
		playtimeArray[i].Render();
	}
}

void EndScene::Update(float dTime){
	Scene::Update(dTime);

	int ran = rand() % 10;

	for (int i = 0; i < 3; i++) {
		playtimeArray[i].setNum(ran);
	}

	if (startButton->IsPointInRect(inputmanager->GetMousePos())) {
		startButton->setScale(Lerp(startButton->getScale(), D3DXVECTOR2(1.3f, 1.3f), 5 * dTime));
	}
	else {
		startButton->setScale(Lerp(startButton->getScale(), D3DXVECTOR2(1.0f, 1.0f), 5 * dTime));
	}

	if (inputmanager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (startButton->IsPointInRect(inputmanager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}
	}
}


