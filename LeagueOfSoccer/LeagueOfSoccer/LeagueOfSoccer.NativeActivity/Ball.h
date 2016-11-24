#pragma once
#include "Mesh.h"
#include "Wall.h"
#include <vector>
class Ball
{
public:
	Mesh _mesh;
	VECTOR4D _position;
	VECTOR4D _color;
	VECTOR4D _velocity;
	VECTOR4D _acceleration;

	std::vector<Wall>* _walls;
public:
	void Update(); //Para cada pard llamar a función isColiding();
	void Initialize();
	Ball();
	~Ball();
};

