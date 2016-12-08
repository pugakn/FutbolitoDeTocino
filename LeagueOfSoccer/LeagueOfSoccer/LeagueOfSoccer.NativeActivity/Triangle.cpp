#include "pch.h"
#include "Triangle.h"

Triangle::Triangle(VECTOR4D A, VECTOR4D B, VECTOR4D C)
{
	_vertex[0] = A;
	_vertex[1] = B;
	_vertex[2] = C;
	FOR(c, 3)
	{
		Color[c] = VECTOR4D(1.f, 1.f, 1.f, 1.f);
	}
}

VECTOR4D Triangle::GetNormal()
{
	return Normalize(Cross3(_vertex[1] - _vertex[0], _vertex[2] - _vertex[0]));
}

VECTOR4D Triangle::GetPlane()
{
	VECTOR4D n = GetNormal();
	n.w = -Dot(n, _vertex[0]);
	return n;
}

void Triangle::Move(MATRIX4D & m)
{
	for (int i = 0; i < 3; ++i)
		_vertex[i] = m * _vertex[i];
}

void Triangle::Scale(MATRIX4D & m)
{
	for (int i = 0; i < 3; ++i)
		_vertex[i] = m * _vertex[i];
}

void Triangle::Draw()
{
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &Color[0]);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, _vertex);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Triangle::SetColor(VECTOR4D color) {
	FOR(c, 3)
	{
		Color[c] = color;
	}
}

void Triangle::SetRotation(float phi)
{
	MATRIX4D r = RotationZ(phi);
	FOR(i, 3) {
		_vertex[i] = r * _vertex[i];
	}
}
