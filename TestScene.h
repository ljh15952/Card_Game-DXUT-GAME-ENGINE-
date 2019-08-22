#pragma once
#include "Scene.h"
#include "Director.h"
#include "Sprite.h"
#include "cards.h"
#include "Player.h"
#include "CardMaster.h"
class TestScene : public Scene
{
public:
	void OnInit() override;
	void Update() override;
	void OnExit() override;

	card * _human_1[10];

	void GiveFirstCard();

	int ct;
	float timer;
};

