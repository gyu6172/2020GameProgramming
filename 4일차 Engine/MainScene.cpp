#include "stdafx.h"
#include "MainScene.h"

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

	exitButton = new Sprite("Resources/Images/out.png");
	AddObject(exitButton);
	exitButton->setPos(SCREEN_WIDTH / 2, 500);
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
