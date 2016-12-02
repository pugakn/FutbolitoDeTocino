#pragma once
#include <vector>
#include "VECTOR4D.h"
class TriangleMesh
{
public:
	std::vector<VECTOR4D> _cara;
public:
	TriangleMesh();
	~TriangleMesh();
};

