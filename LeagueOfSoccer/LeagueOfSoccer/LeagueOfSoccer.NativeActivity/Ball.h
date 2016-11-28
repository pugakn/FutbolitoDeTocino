#pragma once
#include "Mesh.h"
#include "Wall.h"
#include <vector>
class Ball
{
public:
	Mesh _mesh;
	int _sx;
	int _sy;
	VECTOR4D _position;
	VECTOR4D _color;
	VECTOR4D _velocity;
	VECTOR4D _acceleration;
	MATRIX4D traslationMTRX;
	float _radio;

	std::vector<Wall>* _walls;
public:
	void Update();
	void Move(VECTOR4D& acceleration);
	void Draw(const MATRIX4D& world);
	void Initialize();
	Ball();
	~Ball();
};

