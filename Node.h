#pragma once

class Node
{
public:
	Node();
	virtual ~Node() {};
	vector2 _position;
	vector2 _pivot;
	float _rotation;
	vector2 _scale;
	Color _color;
	bool _visible;
	Node * _parent;

	D3DXMATRIX GetMatrix();

	void AddChild(Node* child);

	virtual void Draw() {};
	virtual void Update() {};
};

