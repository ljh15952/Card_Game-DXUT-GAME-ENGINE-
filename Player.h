#pragma once
#include "card.h"
#include "cards.h"
#include "Types.h"
class Player : public Singleton<Player>
{
public:
	void Init();

	list<card*> deck;
	list<card*> hand;

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

	Sprite* CardPlace[4];

	bool playcard[4];

	void DeletePlayer();
};

