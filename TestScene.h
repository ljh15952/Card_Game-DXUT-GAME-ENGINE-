#pragma once
#include "Scene.h"
#include "Director.h"
#include "Sprite.h"
#include "BingleBingle.h"
#include "cards.h"
class TestScene : public Scene
{
public:
	void OnInit() override;
	void Update() override;
	void OnExit() override;

	card * _human_1;
	card* _human_2;
	card * ClickObj;

	list<card*> cards;

	BingleBingle * s1[30];
};

