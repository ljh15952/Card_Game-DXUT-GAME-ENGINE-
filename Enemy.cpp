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
}

enemyState Enemy::PlayCard()
{
	if (feild.size() >= 4)
		return enemyState::CardAttack;

	for (auto it : hand)
	{
		if (it->GetCost() <= mana)
		{
			//it ��ȯ!
			RealPlayCard(it);
			return enemyState::PlayCard;
		}
		else
		{
			cout << "ī�峾�Ծ����!!" << endl;
			return enemyState::CardAttack;
		}
	}
}
void Enemy::RealPlayCard(card * it)
{
	cout << "��ȯ!!" << endl;

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

enemyState Enemy::AttackCard(Player* player)
{
	if (feild.size() == 0)
	{
		cout << "���ʵ����� �ƹ��͵� �����!!" << endl;
		return enemyState::EndTurn;
	}
	if (player->feild.size() > 0) //��� �ʵ����� �ϳ��� ������
	{
		for (auto it : feild)
		{
			if (it->isAttack)
			{
				it->Attack(player->feild[0]);
				wcout << it->GetName() << "�� " << player->feild[0]->GetName() << "�� ������!!" << endl;
				it->isAttack = false;
				return enemyState::CardAttack;
			}
		}
	}
	else if (player->feild.size() == 0 )//��ġ�� �߿�!! ������� �����ϴ� ���� ������ ������ ������ �����ٸ� ������!
	{
		for (auto it : feild)
		{
			if (it->isAttack)
			{
				cout << "��ġ���� ����" << endl;
				it->isAttack = false;
				if(feild.back() == it)
					return enemyState::EndTurn;
				else
					return enemyState::CardAttack;
			}
		}
	}
}



