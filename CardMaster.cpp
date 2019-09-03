#include "DXUT.h"
#include "CardMaster.h"
void CardMaster::SurffleCard()
{
	player->deck;
}

void CardMaster::GiveEnemyCard()
{
	enemy->hand.push_back(enemy->deck.back());//�ڵ忡 �� ������ ī�� �߰�

	enemy->deck.back()->_position.x = DrawCardPos_Enemy;//�� ������ ī�� �������� ���з� �ű�

	DrawCardPos_Enemy += 100; //���� ������ �� ����

	enemy->deck.pop_back();//�� ������ ī�� ����(�з� �����ϱ�)

	enemy->cardCount++;// ���� �������� ���� ����++

	enemy->hand.back()->SetCardnumber(enemy->hand.size() - 1);//��� �߰��� ī���� ��ȣ �߰�

	enemy->hand.back()->SetCurrentCardState(state::inhand);  //��� �߰��� ī�� ���¸� ���л��·�
}

void CardMaster::GivePlayerCard()
{
	player->deck.back()->Create(player->deck.back()->frontcardpath); //�ո�����

	player->hand.push_back(player->deck.back()); //�ڵ忡 �� ������ ī�� �߰�

	player->deck.back()->_position.x = DrawCardPos_Player; //�� ������ ī�� �������� ���з� �ű�

	DrawCardPos_Player += 100; //���� ������ �� ����

	player->deck.pop_back(); //�� ������ ī�� ����(�з� �����ϱ�)

	player->cardCount++; // ���� �������� ���� ����++

	player->hand.back()->SetCardnumber(player->hand.size()-1); //��� �߰��� ī���� ��ȣ �߰�

	player->hand.back()->SetCurrentCardState(state::inhand); //��� �߰��� ī�� ���¸� ���л��·�

	player->hand.back()->SetVisibleLabel(true); //ī���� �� ���̰�
}
   
void CardMaster::EndTurn()
{
	if(currentTurn == Turn::PlayerTurn)
	{
		//enemy mana = current turn
		//increase Enemy mana
		enemy->mana = TurnCount;
		GiveEnemyCard();
		currentTurn = Turn::EnemyTurn;


		for (auto it : enemy->feild)
		{
			if (it->isAttack == false)
			{
				it->isAttack = true;
			}
		}
			


		cout << "���������!!" << endl;
	}
	else if(currentTurn == Turn::EnemyTurn)
	{
		TurnCount++;
		player->mana = TurnCount;
		player->PlayerManeLabel->_text = to_wstring(player->mana);
		GivePlayerCard();
		currentTurn = Turn::PlayerTurn;

		for (auto it : player->feild)
		{
			if (it->isAttack == false)
				it->isAttack = true;
		}

		cout << "�÷��̾�������!!" << endl;
	}
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
	DrawCardPos_Player = 100;
	DrawCardPos_Enemy = 100;

	TurnCount = 1;
	currentTurn = Turn::PlayerTurn;


	enemy = new Enemy;
	player = new Player;
}

