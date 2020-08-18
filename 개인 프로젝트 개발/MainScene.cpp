#include "stdafx.h"
#include "MainScene.h"

D3DXVECTOR2 MainScene::Lerp(D3DXVECTOR2 p1, D3DXVECTOR2 p2, float power) {
	return p1 + (p2 - p1) * power;
}

MainScene::MainScene(){
	background = new Sprite("Resources/Images/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/Images/bg_title.png");
	AddObject(title);
	title->setScaleCenter(D3DXVECTOR2(title->getWidth() / 2, title->getHeight() / 2));
	title->setPos(SCREEN_WIDTH/2, 100);

	startButton = new Sprite("Resources/Images/start_button.png");
	AddObject(startButton);
	startButton->setScaleCenter(D3DXVECTOR2(startButton->getWidth()/2, startButton->getHeight() / 2));
	startButton->setPos(SCREEN_WIDTH/2, 350);
	

}

MainScene::~MainScene(){
	/*SAFE_DELETE(background);*/
	//안해도 되는 이유 : 생성자에서 AddObject를 했기 때문에
}

void MainScene::Render(){
	background->Render();
	title->Render();
	startButton->Render();
}

void MainScene::Update(float dTime){
	Scene::Update(dTime);
	
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