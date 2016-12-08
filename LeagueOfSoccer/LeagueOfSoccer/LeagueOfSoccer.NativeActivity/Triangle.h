#pragma once
#include "MATRIX4D.h"

class Triangle
{
public:
	Triangle(VECTOR4D A, VECTOR4D B, VECTOR4D C);
	VECTOR4D GetNormal();
	VECTOR4D GetPlane();
	void Move(MATRIX4D& m);
	void Scale(MATRIX4D& m);
	void Draw();
	void SetColor(VECTOR4D Color);
	void SetRotation(float phi);
public:
	VECTOR4D _vertex[3];
	VECTOR4D Color[3];
private:
};
