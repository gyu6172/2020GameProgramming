#include "stdafx.h"
#include "MainScene.h"

D3DXVECTOR2 Lerp(D3DXVECTOR2 p1, D3DXVECTOR2 p2, float power) {
	return p1 + (p2 - p1) * power;
}

MainScene::MainScene(){
	background = new Sprite("Resources/Images/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/Images/mainname.png");
	AddObject(title);
	title->setPos(275, 0);

	startButton = new Sprite("Resources/Images/in.png");
	AddObject(startButton);
	startButton->setCenter(300,120, startButton);
	startButton->setPos(SCREEN_WIDTH / 2, 350);
	startButton->setScaleCenter(D3DXVECTOR2(startButton->getRect().right, startButton->getRect().bottom) / 2);

	exitButton = new Sprite("Resources/Images/out.png");
	AddObject(exitButton);
	exitButton->setCenter(300, 120, exitButton);
	exitButton->setPos(SCREEN_WIDTH / 2, 500);
	exitButton->setScaleCenter(D3DXVECTOR2(exitButton->getRect().right, exitButton->getRect().bottom) / 2);
}

MainScene::~MainScene(){
	/*SAFE_DELETE(background);*/
	//안해도 되는 이유 : 생성자에서 AddObject를 했기 때문에
}

void MainScene::Render(){
	background->Render();
	title->Render();
	startButton->Render();
	exitButton->Render();
}

void MainScene::Update(float dTime){
	Scene::Update(dTime);
	
	if (startButton->IsPointInRect(inputmanager->GetMousePos())) {
		startButton->setScale(Lerp(startButton->getScale(), D3DXVECTOR2(1.3f, 1.3f), 5 * dTime));
	}
	else {
		startButton->setScale(Lerp(startButton->getScale(), D3DXVECTOR2(1.0f, 1.0f), 5 * dTime));
	}
	if (exitButton->IsPointInRect(inputmanager->GetMousePos())) {
		exitButton->setScale(Lerp(exitButton->getScale(), D3DXVECTOR2(1.3f, 1.3f), 5 * dTime));
	}
	else {
		exitButton->setScale(Lerp(exitButton->getScale(), D3DXVECTOR2(1.0f, 1.0f), 5 * dTime));
	}

	if (inputmanager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (startButton->IsPointInRect(inputmanager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}
		if (exitButton->IsPointInRect(inputmanager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}
	}
}