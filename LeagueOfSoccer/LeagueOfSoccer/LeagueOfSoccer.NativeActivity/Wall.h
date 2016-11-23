#pragma once
#include "Mesh.h"
class Wall
{
private:
	Mesh _mesh;
	VECTOR4D _position;
	VECTOR4D _color;

public:
	bool IsColiding(VECTOR4D posicion);
	Wall();
	~Wall();
};

