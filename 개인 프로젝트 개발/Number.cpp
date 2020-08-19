#include "stdafx.h"
#include "Number.h"

Number::Number() {
	currentNum = 0;

	num[0] = new Sprite("Resources/Images/num0.png");
	num[1] = new Sprite("Resources/Images/num1.png");
	num[2] = new Sprite("Resources/Images/num2.png");
	num[3] = new Sprite("Resources/Images/num3.png");
	num[4] = new Sprite("Resources/Images/num4.png");
	num[5] = new Sprite("Resources/Images/num5.png");
	num[6] = new Sprite("Resources/Images/num6.png");
	num[7] = new Sprite("Resources/Images/num7.png");
	num[8] = new Sprite("Resources/Images/num8.png");
	num[9] = new Sprite("Resources/Images/num9.png");

	for (int i = 0; i < 10; i++) {
		AddChild(num[i]);
	}
}

Number::~Number(){
	for (int i = 0; i < 10; i++) {
		SAFE_DELETE(num[i]);
	}
}

void Number::Update(float dTime){
	Object::Update(dTime);
}

void Number::Render(){
	Object::Render();
	num[currentNum]->Render();
}

void Number::setNum(int num){
	currentNum = num;
}

int Number::getNum(){
	return currentNum;
}

int Number::getWidth(int index) {
	return num[index]->getWidth();
}
