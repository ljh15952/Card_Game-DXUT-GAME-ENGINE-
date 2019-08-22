#include "DXUT.h"
#include "BingleBingle.h"


BingleBingle::BingleBingle()
{
	Create(L"s.jpg");
	_position = { 100,100 };
	_visible = false;
	_scale = { 0.5f,0.5f };
	timer = 1;
	Speed = 70;
}

void BingleBingle::SetMe(vector2 Pos)
{
	_position = Pos;
	_visible = true;
}

void BingleBingle::Update()
{
	if (!_visible || timer < 0)
		return;

	if (timer > 0)
	{
		timer -= Time::deltaTime;
		Speed -= Time::deltaTime;
		_rotation += 0.5f * Speed * Time::deltaTime;
	}
}
