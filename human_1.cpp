#include "DXUT.h"
#include "human_1.h"

Human_1::Human_1()
{
	Create(L"card_back.png");
	_hp = 2;
	_atkpower = 3;
	_cost = 1;
	_country = Country::KOREA;
	_type = Type::human;
	_ability_type = Ability_Type::battlecry;
	_name = L"human_1";
	isAttack = false;
	frontcardpath = L"pigman.png";

	_HpLabel = new Label;
	_HpLabel->Init(to_wstring(_hp), 15, 25, L"ReadMDL2.ttf");
	_HpLabel->_position = { 300,200 };

	_CostLabel = new Label;
	_CostLabel->Init(to_wstring(_cost), 15, 25, L"ReadMDL2.ttf");
	_CostLabel->_position = { 300,200 };

	_AtkpowerLabel = new Label;
	_AtkpowerLabel->Init(to_wstring(_atkpower), 15, 25, L"ReadMDL2.ttf");
	_AtkpowerLabel->_position = { 300,200 };
}

void Human_1::Attack(card * _card)
{
	wcout << "human_1 ATTACK!!!!" << _card->GetName() << endl;
}

void Human_1::Ability()
{
	cout << "HE HAS NO ABILLTY" << endl;
}

void Human_1::CardBattleCry() //if (card->_ability_type == battlecrt)
{
	cout << "SAY HELLO TO YOU" << endl;
}

void Human_1::DeathCardEvent() //if (card->Deathrattle == battlecrt)
{
	cout << "HE HAS NO DEATH RATTLE" << endl;
}

void Human_1::DeleteCard()
{
	cout << "A ";
	delete _CostLabel;
	delete _AtkpowerLabel;
	delete _HpLabel;
}

