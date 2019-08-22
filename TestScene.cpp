#include "DXUT.h"
#include "TestScene.h"

void TestScene::OnInit()
{
	cout << "INIT" << endl;

	for (int i = 0; i < 30; i++)
	{
		s1[i] = new BingleBingle;
	}

	_human_1 = new Human_1;
	_human_1->_position = { 400,400 };
	
	_human_2 = new Human_1;
	_human_2->_position = { 800,400 };

	cards.push_back(_human_1);
	cards.push_back(_human_2);


	ClickObj = nullptr;
}


void TestScene::Update()
{
	static int count= 0;
	if (DXUTWasKeyPressed('A'))
		Director::GetInstance()->ChangeScene(new TestScene);

	

	for (auto it : cards)
	{
		if (PtInRect(&it->GetRect(), Director::GetInstance()->p))
			it->_scale = { 1.2f,1.2f };
		else
			it->_scale = { 1,1 };
	}
	if (DXUTIsKeyDown('Z'))
		_human_2->_position.x += 1;

	if (Director::GetInstance()->OnMouseDown())
	{
		//s1[count++]->SetMe(Director::GetInstance()->GetMousePos());
		for (auto it : cards)
			if (PtInRect(&it->GetRect(), Director::GetInstance()->p))
				ClickObj = it;
	}
	if (Director::GetInstance()->OnMouse())
	{
		if (ClickObj)
		{
			ClickObj->_position = Director::GetInstance()->GetMousePos();
			ClickObj->_scale = { 1.0f,1.0f };
		}
	}
	if (Director::GetInstance()->OnMouseUp())
	{
		if (ClickObj)
			ClickObj = nullptr;
	}

}

void TestScene::OnExit()
{
	cout << "ONEXIT" << endl;
}
  