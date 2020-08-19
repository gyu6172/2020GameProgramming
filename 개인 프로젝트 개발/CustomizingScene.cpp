#include "stdafx.h"
#include "CustomizingScene.h"
#include "MainScene.h"

CustomizingScene::CustomizingScene(){
	background = new Sprite("Resources/Images/Background.png");
	AddObject(background);
	background->setPos(0, 0);

}

CustomizingScene::~CustomizingScene(){

}

void CustomizingScene::Render(){
	background->Render();
}

void CustomizingScene::Update(float dTime){
	Scene::Update(dTime);
}
