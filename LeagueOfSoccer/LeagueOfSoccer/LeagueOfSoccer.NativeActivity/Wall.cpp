#include "pch.h"
#include "Wall.h"
#include <math.h>

void Wall::Draw()
{
	FOR(x, 12) _triangles[x].Draw();
}

void Wall::SetPosition(VECTOR4D pos)
{
	MATRIX4D Fak = Translation(pos.x, pos.y, pos.z);
	FOR(x, 12) _triangles[x].Move(Fak);
}

void Wall::SetScale(VECTOR4D scale)
{
	MATRIX4D Fak = Scaling(scale.x, scale.y, scale.z);
	FOR(x, 12) _triangles[x].Scale(Fak);
}

bool Wall::OnColliderEnter(VECTOR4D pos)
{
	VECTOR4D* esquina1 = (VECTOR4D*)&_triangles.front()._vertex[0].x;
	VECTOR4D* esquina2 = (VECTOR4D*)&_triangles.back()._vertex[0].x;
	return pos.x > esquina1->x && pos.x < esquina2->x && pos.y > esquina1->y && pos.y < esquina2->y;
}

void Wall::SetRotatation(float phi)
{
	MATRIX4D Fak = RotationZ(phi);
	FOR(x, 12) _triangles[x].SetRotation(phi);
}

void Wall::SetColor(VECTOR4D color)
{
	FOR(x, 12) _triangles[x].SetColor(color);
}

Wall::~Wall()
{
}
