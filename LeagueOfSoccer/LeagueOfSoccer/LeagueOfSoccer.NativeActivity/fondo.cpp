#include "pch.h"
#include "fondo.h"
#include "Triangle.h"


fondo::fondo()
{
	_triangulo.push_back(Triangle(VECTOR4D(-1.0f, 1.0f, -1.f, 1), VECTOR4D(-1.0f, -1.0f, -1.f, 1), VECTOR4D(1.0f, -1.0f, -1.f, 1)));
	_triangulo.push_back(Triangle(VECTOR4D(1.0f, 1.0f, -1.f, 1), VECTOR4D(-1.0f, 1.0f, -1.f, 1), VECTOR4D(1.0f, -1.0f, -1.f, 1)));
}


fondo::~fondo()
{
}

void fondo::Inicializar()
{
	

}
void fondo::SetPosition(VECTOR4D pos)
{
	MATRIX4D Fak = Translation(pos.x, pos.y, pos.z);
	FOR(x, 2) _triangulo[x].Move(Fak);
}

void fondo::SetScale(VECTOR4D scale)
{
	MATRIX4D Fak = Scaling(scale.x, scale.y, scale.z);
	FOR(x, 2) _triangulo[x].Scale(Fak);
}

void fondo::SetColor(VECTOR4D color)
{
	for (int i = 0; i < 2; i++) {
		_triangulo[i].SetColor(color);
	}
}

void fondo::Draw()
{
	for (int i = 0; i < 2; i++) {
		_triangulo[i].Draw();
	}
}
