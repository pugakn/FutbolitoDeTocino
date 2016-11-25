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
	float _radio;

	std::vector<Wall>* _walls;
public:
	void Update(); //Para cada pard llamar a función isColiding();
	void Draw(const MATRIX4D& world);
	void Initialize();
	Ball();
	~Ball();
};

