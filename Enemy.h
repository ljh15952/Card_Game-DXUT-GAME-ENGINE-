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


	enemyState PlayCard(); //ī�� ���� �Լ�
	enemyState AttackCard(Player* player); //�ʵ����� �����Ҽ��մ� ������������ �����ϴ� �Լ�

	void RealPlayCard(card* it);
	Sprite* CardPlace[4];

	void MoveCard();
	void SetAtkPos(card* card, vector2 startPos, vector2 endPos);
	card* AtkCard;
	vector2 startPos;
	vector2 endPos;
	bool CAttack;
};

