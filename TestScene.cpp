#include "DXUT.h"
#include "TestScene.h"

void TestScene::OnInit()
{
	Player::GetInstance()->Init();

	for (int i = 0; i < 10; i++)
	{
		_human_1[i] = new Human_1;
		_human_1[i] ->_position = { (float)1100 + (10*i),630 };
		Player::GetInstance()->deck.push_back(_human_1[i]);

	}


	timer = 0.3f;
	ct = 0;

	CardMaster::GetInstance()->Init();
}


void TestScene::Update()
{
	GiveFirstCard();

	if (Director::GetInstance()->OnMouseDown())
	{
		Player::GetInstance()->ClickCard();
	}
	if (Director::GetInstance()->OnMouse())
	{
		Player::GetInstance()->MoveCard();
	}
	if (Director::GetInstance()->OnMouseUp())
	{
		Player::GetInstance()->MouseUpCard();
	}

	if (DXUTWasKeyPressed('A'))
		Director::GetInstance()->ChangeScene(new TestScene);

}

void TestScene::OnExit()
{
	cout << "ONEXIT" << endl;
	for (auto it : Player::GetInstance()->deck)
	{
		it->DeleteCard();
	}
	for (auto it : Player::GetInstance()->hand)
	{
		it->DeleteCard();
	}
	for (int i = 0; i < 10; i++)
	{
		delete _human_1[i];
	}
	
	Player::GetInstance()->DeletePlayer();

	
}

void TestScene::GiveFirstCard()
{
	if (ct < 4)
	{
		timer -= Time::deltaTime;
		if (timer < 0)
		{
			CardMaster::GetInstance()->GiveCard();
			ct++;
			timer = 0.5f;
		}
	}

}
  