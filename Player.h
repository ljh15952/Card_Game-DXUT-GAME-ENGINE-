#pragma once
#include "card.h"
#include "cards.h"
#include "Types.h"
#include "CardMaster.h"
class Player
{
public:

	Player();

	list<card*> deck;
	vector<card*> hand;
	vector<card*> feild;

	int Shiled_Hp;
	int mana;
	int cardCount;

	Label* PlayerManeLabel;

	void ReducePlayerMana(int _mana);


	void ClickCard();
	void MoveCard();
	void MouseUpCard();
	card* ClickObj;
	vector2 returnpos;

	void ClickEndTurnButton_Up();
	void ClickEndTurnButton_Down_ing();
	
	void HandReSetCardPos(int num);

	Sprite* EndTurnBt;
	Sprite* CardPlace[4];

	bool playcard[4];

	int currentcardnum;

	void DeletePlayer();
};

