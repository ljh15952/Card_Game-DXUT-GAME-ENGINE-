#include "DXUT.h"
#include "card.h"

void card::Update()
{
	if (_scale.x >= 1.1f)
	{
		_HpLabel->_position = { this->_position.x + 69,this->_position.y + 75 };
		_CostLabel->_position = { this->_position.x - 67,this->_position.y - 95 };
		_AtkpowerLabel->_position = { this->_position.x -60,this->_position.y + 75 };
	}
	else
	{
		_HpLabel->_position = { this->_position.x + 64,this->_position.y + 70 };
		_CostLabel->_position = { this->_position.x - 62,this->_position.y - 90 };
		_AtkpowerLabel->_position = { this->_position.x - 55,this->_position.y + 70 };
	}

	if (currentstate == state::inhand)
	{
		if (PtInRect(&this->GetRect(), Director::GetInstance()->p))
			this->_scale = { 1.1f,1.1f };
		else
			this->_scale = { 1,1 };
	}
	if (currentstate == state::infeild)
		this->_scale = { 1,1 };

}

void card::SetVisibleLabel(bool b)
{
	_AtkpowerLabel->_visible = b;
	_CostLabel->_visible = b;
	_HpLabel->_visible = b;
}
