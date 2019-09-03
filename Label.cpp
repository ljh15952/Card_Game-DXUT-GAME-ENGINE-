#include "DXUT.h"
#include "Label.h"
#include "Renderer.h"

Label::Label()
{
	_width = 0;
	_height = 0;
	_text = L"";
	_font = nullptr;
}


Label::~Label()
{
	Renderer::GetInstance()->RemoveRenderTarget(this);
}

void Label::Init(wstring text, int width, int height, wstring fontpath)
{
	_width = width;
	_height = height;
	_text = text;
	wstring route = L"res/" + fontpath;
	//wcout << route << endl;
	AddFontResourceEx(route.c_str(), FR_PRIVATE, 0);
	D3DXCreateFont(DXUTGetD3D9Device(), height, width, static_cast<int>(FW_DONTCARE), 1, false, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, static_cast<int>(DEFAULT_CHARSET), FF_DONTCARE, fontpath.c_str(), &_font);
	Renderer::GetInstance()->AddRenderTargrt(this);
}

void Label::Draw()
{
	if (!_visible)
		return;

	RECT r = { 0,0,0,0 };
	_font->DrawText(NULL, _text.c_str(), _text.size(), &r, DT_CENTER | DT_CALCRECT, 0xffffffff);
	r.left += _position.x;
	r.right += _position.x;
	r.bottom += _position.y;
	r.top += _position.y;
	_font->DrawText(NULL, _text.c_str(), _text.size(), &r, DT_CENTER, 0xffffffff);
	//cout << _position.x << endl;
}
