#pragma once
#include <vector>
#include "Ball.h"
#include "Wall.h"
class Stage
{
public:
	Ball _ball;
	std::vector<Wall> _walls;
public:
	Stage();
	~Stage();
	void Setup();
	void Draw(const MATRIX4D& W);
	void Update();
};
