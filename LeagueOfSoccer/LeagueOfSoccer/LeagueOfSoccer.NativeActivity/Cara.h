#pragma once
#include "VECTOR4D.h"
#include <vector>
struct Triangle
{
	VECTOR4D A, B, C;
};
class Cara
{
public:
	Triangle _tr[2];
	VECTOR4D _normal;
	VECTOR4D _plano;
public:
	std::vector<VECTOR4D> GetVertex();
	Cara(VECTOR4D vertex[]);
	void Draw();
	~Cara();
};

