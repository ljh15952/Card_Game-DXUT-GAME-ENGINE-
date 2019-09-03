#include "DXUT.h"
#include "CardMaster.h"
void CardMaster::SurffleCard()
{
	player->deck;
}

void CardMaster::GiveEnemyCard()
{
	enemy->hand.push_back(enemy->deck.back());//핸드에 덱 맨위의 카드 추가

	enemy->deck.back()->_position.x = DrawCardPos_Enemy;//덱 맨위의 카드 포지션을 손패로 옮김

	DrawCardPos_Enemy += 100; //손패 포지션 값 조정

	enemy->deck.pop_back();//덱 맨위의 카드 삭제(패로 갔으니깐)

	enemy->cardCount++;// 손패 몇장인지 세는 변수++

	enemy->hand.back()->SetCardnumber(enemy->hand.size() - 1);//방금 추가된 카드의 번호 추가

	enemy->hand.back()->SetCurrentCardState(state::inhand);  //방금 추가된 카드 상태를 손패상태로
}

void CardMaster::GivePlayerCard()
{
	player->deck.back()->Create(player->deck.back()->frontcardpath); //앞면으로

	player->hand.push_back(player->deck.back()); //핸드에 덱 맨위의 카드 추가

	player->deck.back()->_position.x = DrawCardPos_Player; //덱 맨위의 카드 포지션을 손패로 옮김

	DrawCardPos_Player += 100; //손패 포지션 값 조정

	player->deck.pop_back(); //덱 맨위의 카드 삭제(패로 갔으니깐)

	player->cardCount++; // 손패 몇장인지 세는 변수++

	player->hand.back()->SetCardnumber(player->hand.size()-1); //방금 추가된 카드의 번호 추가

	player->hand.back()->SetCurrentCardState(state::inhand); //방금 추가된 카드 상태를 손패상태로

	player->hand.back()->SetVisibleLabel(true); //카드의 라벨 보이게
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
			


		cout << "상대턴으로!!" << endl;
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

		cout << "플레이어턴으로!!" << endl;
	}
}

//카드가 이동하는 코드는 어디에서 짜야할까 
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

