#include "DXUT.h"
#include "Node.h"

Node::Node()
{
	_position = { 0,0 };
	_scale = { 1,1 };
	_pivot = { 0.5f,0.5f };
	_color = 0xffffffff;
	_visible = true;
	_rotation = 0;
	_parent = nullptr;
}

D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	D3DXMatrixTransformation2D(&m, nullptr, 0, &_scale, nullptr, _rotation, &_position);

	if (_parent) //Label -> addchild(Node) µÊ Node->addchild(Label)¾ÈµÊ
	{
		m *= _parent->GetMatrix();
	}

	return m;
}

void Node::AddChild(Node* child)
{
	child->_parent = this;
}
