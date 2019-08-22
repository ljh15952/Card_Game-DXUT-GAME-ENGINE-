#include "DXUT.h"
#include "Renderer.h"

void Renderer::Render()
{
	for (auto it : _rendertargets)
	{
		it->Draw();
		it->Update();
	}
}

void Renderer::AddRenderTargrt(Node* node)
{
	if (find(_rendertargets.begin(), _rendertargets.end(), node) != _rendertargets.end())
		return;
	_rendertargets.push_back(node);
}

void Renderer::RemoveRenderTarget(Node* node)
{
	_rendertargets.remove(node);
}
