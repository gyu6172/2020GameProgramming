#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>

using namespace std;

class Car {
private:
	//��� ���� ����
	int speed;	//�ӵ�
	int gear;		//���
	string color;	//����
	int* p;
	const int MAX_SPEED;

public:
	Car(int s, int g, string c);
	Car() : MAX_SPEED(200) {
		cout << "������ ȣ��" << endl;
		speed = 0;
		gear = 0;
		color = "white";
	}

	~Car() {
		cout << "�Ҹ��� ȣ��" << endl;
		delete p;
	}

	int getSpeed();
	void setSpeed(int s);
	int getGear();
	void setGear(int g);
	string getColor();
	void setColor(string s);

	void speedUp();
	void speedDown();
	void show();
};

Car::Car(int s, int g, string c) : speed(s), gear(g), color(c), MAX_SPEED(2){
	speed = s;
	gear = g;
	color = c;
}





int Car::getSpeed() {
	return speed;
}
void Car::setSpeed(int s) {
	speed = s;
}

int Car::getGear() {
	return gear;
}
void Car::setGear(int g) {
	gear = g;
}

string Car::getColor() {
	return color;
}
void Car::setColor(string c) {
	color = c;
}

//��� �Լ� ����
void Car::speedUp() {	//�ӵ� ���� ����Լ�
	speed += 10;
}
void Car::speedDown() {	//�ӵ� ���� ����Լ�
	speed -= 10;
}

void Car::show() {
	cout << "=====================" << endl;
	cout << "�ӵ� : " << speed << endl;
	cout << "��� : " << gear << endl;
	cout << "���� : " << color << endl;
	cout << "=====================" << endl;
}



int main() {
	srand(time(NULL));
	srand(GetTickCount());

	Car car1(rand() % 200, 1, "red") , car2(rand() % 200, 1, "red");
	Car* a = new Car();
	
	car1.show();
	car2.show();

	if (car1.getSpeed() > car2.getSpeed()) {
		cout << "car1�� �¸���" << endl;
	}

	else {
		cout << "car2�� �¸���" << endl;
	}

	return 0;
}