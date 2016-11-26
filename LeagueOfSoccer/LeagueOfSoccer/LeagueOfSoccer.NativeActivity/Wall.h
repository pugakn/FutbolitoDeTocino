#pragma once
//const vector<VECTOR4D>& vertex
#include "Mesh.h"
class Wall
{
private:
	vector<VECTOR4D> _vertexArray;
	vector<VECTOR4D> _colors;
	//Mesh _mesh;
	VECTOR4D _position;
	VECTOR4D _color;
public:
	//void BuildWall();
	void Draw(const MATRIX4D& W);
	bool IsColiding(VECTOR4D posicion);
	Wall();
	~Wall();
};

