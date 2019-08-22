#include "DXUT.h"
#include "Player.h"

void Player::Init()
{
	Shiled_Hp = 5;
	mana = 1;
	cardCount = 0;

	PlayerManeLabel = new Label;
	PlayerManeLabel->Init(to_wstring(Player::GetInstance()->mana), 30, 60, L"ReadMDL2.ttf");
	PlayerManeLabel->_position = { 50,450 };

	for (int i = 0; i < 4; i++)
	{
		CardPlace[i] = new Sprite;
		CardPlace[i]->Create(L"card_place.png");
		CardPlace[i]->_position = { (float)340 + (200 * i),450 };
	}

	for (int i = 0; i < 4; i++)
	{
		playcard[i] = false;
	}
}


void Player::ReducePlayerMana(int _mana)
{
	mana -= _mana;
	PlayerManeLabel->_text = to_wstring(mana);
}

void Player::ClickCard()
{
	for (auto it : Player::GetInstance()->hand)
	{
		if (PtInRect(&it->GetRect(), Director::GetInstance()->p))
		{
			ClickObj = it;
			returnpos = ClickObj->_position;
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
		if (num != -1)
		{
			ClickObj->_position = CardPlace[num]->_position;
			Player::GetInstance()->hand.remove(ClickObj);
			playcard[num] = true;
			num = -1;
		}
		else
		{
			ClickObj->_position = returnpos;
		}
		ClickObj = nullptr;
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
