#pragma once
//const vector<VECTOR4D>& vertex
#include "Triangle.h"
#include <vector>

class Stage;

class Wall
{
	friend Stage;
public:
	vector<Triangle> _triangles;
public:
	void Draw();
	void SetPosition(VECTOR4D pos);
	void SetScale(VECTOR4D scale);
	bool OnColliderEnter(VECTOR4D pos);
	void SetRotatation(float phi);
	void SetColor(VECTOR4D color);
	Wall()
	{
		_triangles.push_back(Triangle(VECTOR4D(-1.0f, -1.0f, -1.0f, 1), VECTOR4D(-1.0f, -1.0f, 1.0f, 1), VECTOR4D(-1.0f, 1.0f, 1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(-1.0f, -1.0f, -1.0f, 1), VECTOR4D(-1.0f, 1.0f, 1.0f, 1), VECTOR4D(-1.0f, 1.0f, -1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, 1.0f, -1.0f, 1), VECTOR4D(-1.0f, -1.0f, -1.0f, 1), VECTOR4D(-1.0f, 1.0f, -1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, 1.0f, -1.0f, 1), VECTOR4D(1.0f, -1.0f, -1.0f, 1), VECTOR4D(-1.0f, -1.0f, -1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, -1.0f, 1.0f, 1), VECTOR4D(-1.0f, -1.0f, -1.0f, 1), VECTOR4D(1.0f, -1.0f, -1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, -1.0f, 1.0f, 1), VECTOR4D(-1.0f, -1.0f, 1.0f, 1), VECTOR4D(-1.0f, -1.0f, -1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(-1.0f, 1.0f, 1.0f, 1), VECTOR4D(-1.0f, -1.0f, 1.0f, 1), VECTOR4D(1.0f, -1.0f, 1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, 1.0f, 1.0f, 1), VECTOR4D(-1.0f, 1.0f, 1.0f, 1), VECTOR4D(1.0f, -1.0f, 1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, 1.0f, 1.0f, 1), VECTOR4D(1.0f, -1.0f, -1.0f, 1), VECTOR4D(1.0f, 1.0f, -1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, -1.0f, -1.0f, 1), VECTOR4D(1.0f, 1.0f, 1.0f, 1), VECTOR4D(1.0f, -1.0f, 1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, 1.0f, 1.0f, 1), VECTOR4D(1.0f, 1.0f, -1.0f, 1), VECTOR4D(-1.0f, 1.0f, -1.0f, 1)));
		_triangles.push_back(Triangle(VECTOR4D(1.0f, 1.0f, 1.0f, 1), VECTOR4D(-1.0f, 1.0f, -1.0f, 1), VECTOR4D(-1.0f, 1.0f, 1.0f, 1)));
	}
	~Wall();
};

