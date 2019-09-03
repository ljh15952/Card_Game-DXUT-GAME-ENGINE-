#include "DXUT.h"
#include "Sprite.h"

Sprite::Sprite()
{
	texture = nullptr;
	Aninum = 0;
	Timer = 0;
	NowFrame = 0;
}

Sprite::~Sprite()
{
	Renderer::GetInstance()->RemoveRenderTarget(this);
}

void Sprite::Create(wstring filename)
{
	texture = TextureManager::GetInstance()->LoadTexture(filename);
	AddRenderTarget();
}

void Sprite::AddRenderTarget()
{
	Renderer::GetInstance()->AddRenderTargrt(this);
}

bool Sprite::Animaion(wstring path, int frame, float delay, int Aninum)
{
	//일단보류
	return false;
}


RECT Sprite::GetRect()
{
	RECT r = { 0,0,0,0 };

	r.left = _position.x - texture->_info.Width /2 * _scale.x;
	r.right = _position.x + texture->_info.Width /2 * _scale.x;
	r.top = _position.y - texture->_info.Height / 2 * _scale.y;
	r.bottom = _position.y + texture->_info.Height / 2 * _scale.y;

	return r;
}

vector2 Sprite::GoTo(vector2 endPos, float speed)
{
	vector2 dif = endPos - _position;
	float l = sqrt(dif.x * dif.x + dif.y * dif.y);
	dif.x /= l;
	dif.y /= l;
	//_rotation = atan2(dif.y, dif.x);

	return dif * Time::deltaTime * speed;
}

void Sprite::Draw()
{
	if (!_visible)
		return;
	if (texture == nullptr)
		return;

	Director::GetInstance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Director::GetInstance()->GetSprite()->SetTransform(&GetMatrix());
	D3DXVECTOR3 center = { texture->_info.Width * _pivot.x,texture->_info.Height * _pivot.y,0 };
	Director::GetInstance()->GetSprite()->Draw(texture->_texture, nullptr, &center, nullptr, _color);
	Director::GetInstance()->GetSprite()->End();
}
