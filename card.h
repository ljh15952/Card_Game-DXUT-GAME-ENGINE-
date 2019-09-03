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
	wstring _name;
	state currentstate;
	Label* _AtkpowerLabel;
	Label* _CostLabel;
	Label* _HpLabel;
	
	int cardnumber;

public:
	virtual void Ability() {};
	virtual void Attack(card * _card) {};
	virtual void CardBattleCry() {};
	virtual void DeathCardEvent() {};
	void Update() override;
	virtual void DeleteCard() {};
	virtual wstring GetName() { return _name; };

	Ability_Type GetAbilityType() { return _ability_type; };

	int GetCost() { return _cost; };	
	int GetCardnumber() { return cardnumber; };
	void SetCardnumber(int num) { cardnumber = num; };
	void SetVisibleLabel(bool b);
	
	state GetCurrentCardState() { return currentstate; };
	void SetCurrentCardState(state s) { currentstate = s; };

	bool isAttack;
	wstring frontcardpath;

};

