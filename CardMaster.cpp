#include "DXUT.h"
#include "CardMaster.h"

void CardMaster::SurffleCard()
{
	Player::GetInstance()->deck;
}

void CardMaster::GiveCard()
{
	Player::GetInstance()->hand.push_back(Player::GetInstance()->deck.back());
	Player::GetInstance()->deck.back()->_position.x = a;
	a += 100;
	Player::GetInstance()->deck.pop_back();
	Player::GetInstance()->cardCount++;
}
   
void CardMaster::EndTurn()
{
	//if(Turn::Player)
	//{
	//enemy mana = current turn
	//increase Enemy mana
	//}
	//if(Turn::enemy)
	//{
	//player mana = current turn
	//increase player mana
	//}
}

//ī�尡 �̵��ϴ� �ڵ�� ��𿡼� ¥���ұ� 
void CardMaster::GiveFirstCard()
{
	
}

void CardMaster::PlayCard()
{

}

void CardMaster::Init()
{
	a = 100;
}

