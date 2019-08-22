#pragma once
#include "Director.h"
#include "Texture.h"
#include "Renderer.h"
#include "Node.h"

class Sprite : public Node
{
public:
	Sprite();
	~Sprite();

	void Create(wstring filename);
	void AddRenderTarget();

	bool Animaion(wstring path, int frame, float delay, int Aninum);
	int NowFrame;
	float Timer;
	int Aninum;

	RECT GetRect();
	
	Texture2D* texture;

	void Draw() override;

};      

