#pragma once
#include "Player.h"
#include "Types.h"
#include "card.h"
class CardMaster : public Singleton<CardMaster> 
{
public:
	void SurffleCard();
	void GiveCard();
	void EndTurn();
	void GiveFirstCard();
	void PlayCard();

	void Init();
	int a;


};

