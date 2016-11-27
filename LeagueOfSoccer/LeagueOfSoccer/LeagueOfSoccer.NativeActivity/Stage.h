#pragma once
#include <vector>
#include "Ball.h"
#include "Wall.h"
class Stage
{
	Ball _ball;
	std::vector<Wall> _walls;
public:
	Stage();
	~Stage();
	void Setup();
	void Draw(const MATRIX4D& W);
};
