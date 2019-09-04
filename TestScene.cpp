#include "DXUT.h"
#include "TestScene.h"

void TestScene::OnInit()
{
	CardMaster::GetInstance()->Init();


	for (int i = 0; i < 10; i++)
	{
		_human_1[i] = new Human_1;
		_human_1[i]->_position = { (float)1100 + (10 * i),630 };
		_human_1[i]->SetCurrentCardState(state::indeck);
		_human_1[i]->SetVisibleLabel(false);
		CardMaster::GetInstance()->player->deck.push_back(_human_1[i]);

		_human_2[i] = new Human_1;
		_human_2[i]->_position = { (float)1100 + (10 * i),100 };
		_human_2[i]->SetCurrentCardState(state::indeck);
		_human_2[i]->SetVisibleLabel(false);
		CardMaster::GetInstance()->enemy->deck.push_back(_human_2[i]);
	}

	timer = 0.3f;
	enemytimer = 0.5f;
	ct = 0;
	EnemyState = enemyState::PlayCard;
}


void TestScene::Update()
{
	GiveFirstCard();

	if (CardMaster::GetInstance()->currentTurn == Turn::PlayerTurn)
	{
		if (Director::GetInstance()->OnMouseDown())
		{
			CardMaster::GetInstance()->player->ClickCard();
		}
		if (Director::GetInstance()->OnMouse())
		{
			CardMaster::GetInstance()->player->MoveCard();
			CardMaster::GetInstance()->player->ClickEndTurnButton_Down_ing();
		}
		if (Director::GetInstance()->OnMouseUp())
		{
			CardMaster::GetInstance()->player->MouseUpCard();
			CardMaster::GetInstance()->player->ClickEndTurnButton_Up();
		}
	}
	else if (CardMaster::GetInstance()->currentTurn == Turn::EnemyTurn)
	{
		if (CardMaster::GetInstance()->enemy->CAttack)
		{
			CardMaster::GetInstance()->enemy->MoveCard();
		}

		enemytimer -= Time::deltaTime;
		if (enemytimer < 0)
		{
			if (CardMaster::GetInstance()->enemy->CAttack)
				return;

			if (EnemyState == enemyState::PlayCard)
			{
				EnemyState = CardMaster::GetInstance()->enemy->PlayCard();
			}
			else if (EnemyState == enemyState::CardAttack)
			{
				EnemyState = CardMaster::GetInstance()->enemy->AttackCard(CardMaster::GetInstance()->player);
			}
			else
			{
				EnemyState = enemyState::PlayCard;
				cout << "턴을 종료한다!" << endl;
				CardMaster::GetInstance()->EndTurn();
			}
			enemytimer = 0.5f;

		}

	}
	if (DXUTWasKeyPressed('A'))
		Director::GetInstance()->ChangeScene(new TestScene);
}
//TODO : 1.적 카드 소환이되야됨 손패 포지션 조정도되야함 OK
//		 2.공격이 되야함(체력깎이고 죽고) NO 
//		 3.영웅 체력이 보이고 깎여야함 NO
//       4.아니 카드가 움직이는 애니메이션 어케해줘야됨? 줫나어렵네 OK

void TestScene::OnExit()
{
	for (auto it : CardMaster::GetInstance()->player->deck)
	{
		it->DeleteCard();
	}
	for (auto it : CardMaster::GetInstance()->player->hand)
	{
		it->DeleteCard();
	}
	for (int i = 0; i < 10; i++)
	{
		delete _human_1[i];
	}

	CardMaster::GetInstance()->player->DeletePlayer();
}

void TestScene::GiveFirstCard()
{
	if (ct < 4)
	{
		timer -= Time::deltaTime;
		if (timer < 0)
		{
			CardMaster::GetInstance()->GivePlayerCard();
			CardMaster::GetInstance()->GiveEnemyCard();
			ct++;
			timer = 0.5f;
		}
	}

}
