#include "stdafx.h"
#include "Background.h"

Background::Background(){
	background = new Sprite("Resources/Images/Background.png");
	AddChild(background);
}

Background::~Background(){

}

void Background::Render() {
	Object::Render();
	background->Render();
}

void Background::Update(float dTime){
	Object::Update(dTime);
	
	setPos(getPosX()- 3, getPosY());
}


