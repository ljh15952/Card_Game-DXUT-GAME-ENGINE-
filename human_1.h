#pragma once
#include "card.h"
class Human_1 :
	public card
{
public:
	Human_1();

	void Attack() override;
	void Ability() override;
	void PlayCardEvent() override;
	void DeathCardEvent() override;

	void DeleteCard() override;
};

