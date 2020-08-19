#include "stdafx.h"
#include "Bridge.h"

Bridge::Bridge(){
	bridge = new Sprite("Resources/Images/bg_bridge.png");
	AddChild(bridge);
}

Bridge::~Bridge(){

}

void Bridge::Render() {
	Object::Render();
	bridge->Render();
}

void Bridge::Update(float dTime){
	Object::Update(dTime);
	setPos(getPosX() - 3.5, getPosY());
}


