#pragma once
#include "Types.h"
#include "Enemy.h"
#include "Player.h"
class Enemy;
class Player;
class CardMaster : public Singleton<CardMaster> 
{
public:
	void SurffleCard();
	void GivePlayerCard();
	void GiveEnemyCard();

	void EndTurn();
	void GiveFirstCard();
	void PlayCard();

	Turn currentTurn;

	Enemy* enemy;
	Player* player;


	void Init();
	int DrawCardPos_Player;
	int DrawCardPos_Enemy;
	int TurnCount;
};

