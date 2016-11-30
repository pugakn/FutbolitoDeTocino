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
	bool _coliding;
	vector<VECTOR4D> _positions;
	std::vector<Wall> _walls;
	VECTOR4D _color;
	VECTOR4D _velocity;
	VECTOR4D _acceleration;
	VECTOR4D _position;
	MATRIX4D traslationMTRX;
	float _radio;

public:
	void Update(const MATRIX4D W);
	void Move(VECTOR4D& acceleration);
	void Draw(const MATRIX4D& world);
	void Initialize(vector<Wall> _walls);
	Ball();
	~Ball();
};

