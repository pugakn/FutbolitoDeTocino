#pragma once
#include <vector>
#include "Ball.h"
#include "Wall.h"
class Stage
{

	void CreateFaces();
public:
	Ball *_ball;
	std::vector<Wall> _walls;
public:
	Stage();
	~Stage();
	
	void Setup(int32_t w, int32_t h);
	void Draw(int32_t w, int32_t h);
	void Update();
};
