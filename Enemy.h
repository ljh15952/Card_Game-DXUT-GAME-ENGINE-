#pragma once
#include "card.h"
#include "Types.h"
#include "Player.h"

class Player;

class Enemy 
{
public:
	Enemy();

	list<card*> deck;
	vector<card*> hand;
	vector <card*> feild;

	int Shiled_Hp;
	int mana;
	int cardCount;


	enemyState PlayCard(); //카드 놓는 함수
	enemyState AttackCard(Player* player); //필드위에 공격할수잇는 선수가있으면 공격하는 함수

	void RealPlayCard(card* it);
	Sprite* CardPlace[4];
};

