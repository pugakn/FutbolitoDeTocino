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
	bool _coliding;
public:
	void Move(VECTOR4D& acceleration);
	void Draw(int32_t w, int32_t h);
	void Initialize(int32_t w, int32_t h);
	Ball();
	~Ball();
};

