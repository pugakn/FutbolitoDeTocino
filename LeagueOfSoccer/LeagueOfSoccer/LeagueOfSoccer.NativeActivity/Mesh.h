#pragma once
#include <vector>
#include "MATRIX4D.h"
#include <functional>
using namespace std;
class Mesh
{
public:
	friend class Ball;
	friend class Wall;
	vector<unsigned short> m_Indices;
	int m_sx;
	int m_sy;
public:
	vector<VECTOR4D> m_Vertices;
	vector<VECTOR4D> m_Colors;
	//Genera la secuencia de indices de la mesh de sx y sy vertices
	void BuildIndexBuffer();
	void Build(int sx, int sy, void(*func(vector<VECTOR4D>& vertexArray, vector<VECTOR4D>& colorArray)));

	Mesh();
	~Mesh();
};
