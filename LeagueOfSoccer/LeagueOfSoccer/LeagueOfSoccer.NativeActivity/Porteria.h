#pragma once
#include "VECTOR4D.h"
#include <vector>
class Porteria
{
private:
	VECTOR4D _vertexA, _vertexB;
public:
	Porteria();
	~Porteria();
	bool ChechTriggerEnter(std::vector<VECTOR4D> &point);
};

