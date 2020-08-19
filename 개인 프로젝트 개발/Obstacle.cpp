#include "stdafx.h"
#include "Obstacle.h"

Obstacle::Obstacle(char code){
	if (code == 'd') {
		obstacle = new Sprite("Resources/Images/down_obstacle.png");
	}
	else {
		obstacle = new Sprite("Resources/Images/up_obstacle.png");
	}
	AddChild(obstacle);
	rect = obstacle->getRect();
}

Obstacle::~Obstacle(){

}

void Obstacle::Render(){
	Object::Render();
	obstacle->Render();
}

void Obstacle::Update(float dTime){
	Object::Update(dTime);
	setPos(getPosX()- 3.5, getPosY());

}
