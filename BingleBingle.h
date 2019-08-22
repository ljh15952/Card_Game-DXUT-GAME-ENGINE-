#pragma once
#include "Sprite.h"

class BingleBingle : public Sprite
{
public:
	BingleBingle();
	void SetMe(vector2 Pos);
	void Update() override;
	float timer;
	int Speed;
};
