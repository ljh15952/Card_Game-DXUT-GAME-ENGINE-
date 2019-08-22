#pragma once
#include "Sprite.h"
#include "Label.h"
class card : public Sprite
{
protected:
	int _hp;
	int _atkpower;
	int _cost;
	Country _country;
	Type _type;
	Ability_Type _ability_type;
	string _name;

	Label* _AtkpowerLabel;
	Label* _CostLabel;
	Label* _HpLabel;
public:
	virtual void Ability() {};
	virtual void Attack() {};
	virtual void PlayCardEvent() {};
	virtual void DeathCardEvent() {};
	void Update() override;
	virtual void DeleteCard() {};

};

