#pragma once  
#include "Types.h"
#include "Node.h"
class Renderer : public Singleton<Renderer>
{
public:
	void Render();
	void AddRenderTargrt(Node * node);
	void RemoveRenderTarget(Node* node);
private:
	list<Node*>  _rendertargets;
};

