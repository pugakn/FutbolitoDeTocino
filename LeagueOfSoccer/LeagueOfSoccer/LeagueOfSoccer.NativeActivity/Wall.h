#pragma once
#include "Mesh.h"
class Wall
{
private:
	Mesh _mesh;
	VECTOR4D _position;
	VECTOR4D _color;
public:
	void BuildWall(const vector<VECTOR4D>& vertex);
	void Draw(const MATRIX4D& W);
	bool IsColiding(VECTOR4D posicion);
	Wall();
	~Wall();
};

