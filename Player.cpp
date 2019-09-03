#include "DXUT.h"
#include "Player.h"

Player::Player()
{
	Shiled_Hp = 5;
	mana = CardMaster::GetInstance()->TurnCount;
	cardCount = 0;

	PlayerManeLabel = new Label;
	PlayerManeLabel->Init(to_wstring(mana), 30, 60, L"ReadMDL2.ttf");
	PlayerManeLabel->_position = { 50,450 };

	for (int i = 0; i < 4; i++)
	{
		CardPlace[i] = new Sprite;
		CardPlace[i]->Create(L"card_place.png");
		CardPlace[i]->_position = { (float)340 + (200 * i),500 };
	}

	for (int i = 0; i < 4; i++)
	{
		playcard[i] = false;
	}

	EndTurnBt = new Sprite;
	EndTurnBt->Create(L"EndTurnBt.png");
	EndTurnBt->_position = { 1150,360 };
	ClickObj = nullptr;

}


void Player::ReducePlayerMana(int _mana)
{
	mana -= _mana;
	PlayerManeLabel->_text = to_wstring(mana);
}

void Player::ClickCard()
{
	for (auto it : hand)
	{
		if (PtInRect(&it->GetRect(), Director::GetInstance()->p))
		{
			ClickObj = it;
			returnpos = ClickObj->_position;
			currentcardnum = it->GetCardnumber();
		}
	}
}

void Player::MoveCard()
{
	if (ClickObj)
	{
		ClickObj->_position = Director::GetInstance()->GetMousePos();
		ClickObj->_scale = { 1.0f,1.0f };
	}
}

void Player::MouseUpCard()
{
	if (ClickObj)
	{
		RECT temp;
		int num = -1;
		for (int i = 0; i < 4; i++)
		{
			if (IntersectRect(&temp, &ClickObj->GetRect(), &CardPlace[i]->GetRect()) && playcard[i] == false)
			{
				num = i;
			}
		}
		if (num != -1 && mana >= ClickObj->GetCost())
		{
			feild.push_back(ClickObj);
			ClickObj->_position = CardPlace[num]->_position;
			hand.erase(hand.begin() + ClickObj->GetCardnumber());
			ReducePlayerMana(ClickObj->GetCost());
			HandReSetCardPos(currentcardnum); 
			playcard[num] = true;
			num = -1;
			CardMaster::GetInstance()->DrawCardPos_Player -= 100;
			ClickObj->SetCurrentCardState(state::infeild);
			if (ClickObj->GetAbilityType() == Ability_Type::battlecry)
			{
				ClickObj->CardBattleCry();
			}
		}
		else
		{
			ClickObj->_position = returnpos;
		}
		ClickObj = nullptr;
	}
}

void Player::ClickEndTurnButton_Up()
{
	if (PtInRect(&EndTurnBt->GetRect(), Director::GetInstance()->p))
	{
		EndTurnBt->_scale = { 1,1 };
		CardMaster::GetInstance()->EndTurn();
	}
}

void Player::ClickEndTurnButton_Down_ing()
{
	if (PtInRect(&EndTurnBt->GetRect(), Director::GetInstance()->p))
	{
		EndTurnBt->_scale = { 1.1f,1.1f };
	}
	else
		EndTurnBt->_scale = { 1,1 };
}

void Player::HandReSetCardPos(int num)
{
	for (int i = num; i < hand.size(); i++)
	{
		hand[i]->_position -= {100, 0};
		hand[i]->SetCardnumber(hand[i]->GetCardnumber() - 1);
	}
}

void Player::DeletePlayer()
{
	deck.clear();
	hand.clear();

	delete PlayerManeLabel;

	for (int i = 0; i < 4; i++)
	{
		delete CardPlace[i];
	}
}
