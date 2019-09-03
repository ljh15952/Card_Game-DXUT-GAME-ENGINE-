#pragma once
#include "card.h"
class Human_1 :
	public card
{
public:
	Human_1();

	void Attack(card * _card) override;
	void Ability() override;
	void CardBattleCry() override;
	void DeathCardEvent() override;

	void DeleteCard() override;
	wstring GetName() override { return _name; };
};

