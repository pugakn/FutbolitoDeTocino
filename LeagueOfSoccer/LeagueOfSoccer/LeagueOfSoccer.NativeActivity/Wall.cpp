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

Wall::~Wall()
{
}
