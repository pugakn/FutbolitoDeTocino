#include "pch.h"
#include "Wall.h"
#include <math.h>

void Wall::Draw()
{

}

void Wall::SetPosition(VECTOR4D pos)
{
	_position = Translation(pos.x,pos.y,pos.z);
}

void Wall::SetScale(VECTOR4D scale)
{
	_scale = Scaling(scale.x, scale.y, scale.z);
}

Wall::~Wall()
{
}
