#pragma once
#include "Node.h"
class Label :
	public Node
{
public:
	Label();
	~Label();

	LPD3DXFONT _font;
	wstring _text;

	int _width, _height;

	void Init(wstring text, int width, int height, wstring font);
	void Draw() override;
};

