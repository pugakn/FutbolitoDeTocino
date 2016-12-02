#include "pch.h"
#include "Porteria.h"


Porteria::Porteria()
{
}


Porteria::~Porteria()
{
}

bool Porteria::ChechTriggerEnter(std::vector<VECTOR4D>& point)
{
	for (int i = 0; i < point.size(); i++) {
		if (_vertexB.y > point[i].y && _vertexB.x < point[i].x && _vertexA.y > point[i].y && _vertexA.x > point[i].x) return true;
	}
	return false;
}
