#pragma once
//const vector<VECTOR4D>& vertex
#include "Mesh.h"
struct TRIANGLE
{
	VECTOR4D v0;
	VECTOR4D v1;
	VECTOR4D v2;
};

class Wall
{
private:
	vector<VECTOR4D> _vertexArray;
	vector<VECTOR4D> _colors;
	MATRIX4D _scale;
	MATRIX4D _position;
	VECTOR4D _color;
	vector <VECTOR4D> _planes;
	vector <TRIANGLE> _triangles;
public:
	//void BuildWall();
	void Draw();
	void SetPosition(VECTOR4D pos);
	void SetScale(VECTOR4D scale);
	Wall();
	~Wall();
};

