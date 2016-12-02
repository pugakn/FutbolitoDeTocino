#pragma once
#include <vector>
#include "Ball.h"
#include "Wall.h"
class Stage
{
public:
	Ball *_ball;
	std::vector<Wall> _walls;
public:
	Stage();
	~Stage();
	void Setup();
	void Draw(int32_t w, int32_t h);
	void Update();
};
