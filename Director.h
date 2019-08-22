#pragma once
#include "Scene.h"
#include "Types.h"
#include "Renderer.h"
class Director : public Singleton<Director>
{
public:
	Director();

	void ChangeScene(Scene * scene);

	int ClickNum;
	void Init();

	bool OnMouseDown();
	bool OnMouse();
	bool OnMouseUp();

	void UpdateGame();

	LPD3DXSPRITE GetSprite() { return _sprite; };
	vector2 GetMousePos();
	POINT p;
private:
	Scene* _currentScene;
	static LPD3DXSPRITE _sprite;
};

