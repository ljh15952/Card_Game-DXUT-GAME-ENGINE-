#pragma once
#include "Types.h"
class Texture2D
{
public:
	D3DXIMAGE_INFO _info;
	LPDIRECT3DTEXTURE9 _texture;
	wstring _filename;
};

class TextureManager : public Singleton<TextureManager>
{
public:
	Texture2D* LoadTexture(wstring path);
private:
	list <Texture2D*> _texturePool;
};

