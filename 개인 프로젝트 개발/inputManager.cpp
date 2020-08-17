#include "stdafx.h"
#include "inputManager.h"

inputManager::inputManager() {
	for (int i = 0; i < 256; i++) {
		beforeKey[i] = false;
		currentKey[i] = false;
	}
}

inputManager::~inputManager() {

}

void inputManager::UpdateKeyState() {
	for (int i = 0; i < 256; i++) {
		beforeKey[i] = currentKey[i];
		currentKey[i] = GetAsyncKeyState(i) & 0x8000;
	}
}

int inputManager::GetKeyState(int vk) {
	if (beforeKey[vk] && currentKey[vk]) {
		return KEY_ON;
	}
	else if (!beforeKey[vk] && currentKey[vk]) {
		return KEY_DOWN;
	}
	else if (!beforeKey[vk] && !currentKey[vk]) {
		return KEY_UP;
	}
	else {
		return KEY_NONE;
	}
}

D3DXVECTOR2 inputManager::GetMousePos() {
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hWnd, &p);

	return D3DXVECTOR2(p.x, p.y);
}
