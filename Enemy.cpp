#include "DXUT.h"
#include "Enemy.h"


Enemy::Enemy()
{
	Shiled_Hp = 5;
	mana = CardMaster::GetInstance()->TurnCount;
	cardCount = 0;

	for (int i = 0; i < 4; i++)
	{
		cout << "ASDASDASDDAS" << endl;
		CardPlace[i] = new Sprite;
		CardPlace[i]->Create(L"card_place.png");
		CardPlace[i]->_position = { (float)340 + (200 * i),250 };
	}

	CAttack = false;
}

enemyState Enemy::PlayCard()
{
	if (feild.size() >= 4)
		return enemyState::CardAttack;

	for (auto it : hand)
	{
		if (it->GetCost() <= mana)
		{
			//it 소환!
			RealPlayCard(it);
			return enemyState::PlayCard;
		}
		else
		{
			cout << "카드낼게없어요!!" << endl;
			return enemyState::CardAttack;
		}
	}
}
void Enemy::RealPlayCard(card * it)
{
	cout << "소환!!" << endl;

	mana -= it->GetCost();
	it->Create(it->frontcardpath);
	feild.push_back(it);
	it->_position = CardPlace[feild.size()-1]->_position;
	it->SetVisibleLabel(true);
	hand.erase(hand.begin() + it->GetCardnumber());
	CardMaster::GetInstance()->DrawCardPos_Enemy -= 100;

	
	it->SetCurrentCardState(state::infeild);

	for (int i = it->GetCardnumber(); i < hand.size(); i++)
	{
		hand[i]->_position -= {100, 0};
		hand[i]->SetCardnumber(hand[i]->GetCardnumber() - 1);
	}
	if (it->GetAbilityType() == Ability_Type::battlecry)
	{
		it->CardBattleCry();
	}
}

void Enemy::MoveCard()
{
	static bool b = true;
	if (b)
	{
		if (AtkCard->GoTo(endPos, 1500))
		{
			b = !b;
		}
	}
	else
	{
		if (AtkCard->GoTo(startPos, 1500))
		{
			b = !b;
			CAttack = false;
		}
	}
}

void Enemy::SetAtkPos(card* card, vector2 _startPos, vector2 _endPos)
{
	AtkCard = card;
	startPos = _startPos;
	endPos = _endPos;
	CAttack = true;
}

enemyState Enemy::AttackCard(Player* player)
{
	if (feild.size() == 0)
	{
		cout << "내필드위에 아무것도 없어요!!" << endl;
		return enemyState::EndTurn;
	}
	if (player->feild.size() > 0) //상대 필드위에 하나라도 있을때
	{
		for (auto it : feild)
		{
			if (it->isAttack)
			{
				it->Attack(player->feild[0]);
				SetAtkPos(it, it->_position, player->feild[0]->_position);
				wcout << it->GetName() << "이 " << player->feild[0]->GetName() << "을 공격함!!" << endl;
				it->isAttack = false;
				return enemyState::CardAttack;
			}
		}
	}
	else if (player->feild.size() == 0 )//명치다 중요!! 순서대로 공격하니 제일 마지막 선수가 공격이 끝났다면 엔드턴!
	{
		for (auto it : feild)
		{
			if (it->isAttack)
			{
				cout << "명치떄려 슈발" << endl;
				SetAtkPos(it, it->_position, { 500,500 });
				it->isAttack = false;
				if(feild.back() == it)
					return enemyState::EndTurn;
				else
					return enemyState::CardAttack;
			}
		}
	}
}



