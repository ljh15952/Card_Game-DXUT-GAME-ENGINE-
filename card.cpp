#include "DXUT.h"
#include "card.h"

void card::Update()
{
	if (_scale.x >= 1.2f)
	{
		_HpLabel->_position = { this->_position.x - 60,this->_position.y + 75 };
		_CostLabel->_position = { this->_position.x - 62,this->_position.y - 107 };
		_AtkpowerLabel->_position = { this->_position.x + 55,this->_position.y + 75 };
	}
	else
	{
		_HpLabel->_position = { this->_position.x - 50,this->_position.y + 65 };
		_CostLabel->_position = { this->_position.x - 52,this->_position.y - 87 };
		_AtkpowerLabel->_position = { this->_position.x + 45,this->_position.y + 65 };
	}

	if (PtInRect(&this->GetRect(), Director::GetInstance()->p))
		this->_scale = { 1.2f,1.2f };
	else
		this->_scale = { 1,1 };
}
