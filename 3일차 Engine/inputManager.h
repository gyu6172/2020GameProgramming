#pragma once
#include <d3dx9.h>

class inputManager
{
private:
	bool beforeKey[256], currentKey[256];

public:
	inputManager();
	~inputManager();

	void UpdateKeyState();
	int GetKeyState(int vk);
	D3DXVECTOR2 GetMousePos();

};

