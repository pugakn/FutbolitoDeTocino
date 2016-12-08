#pragma once
#include <vector>
#include "Ball.h"
#include "Wall.h"
#include "fondo.h"
class Stage
{

	void CreateFaces();
public:
	Ball *_ball;
	std::vector<Wall> _walls;
	std::vector<fondo> _fondo;
public:
	Stage();
	~Stage();
	
	void Setup(int32_t w, int32_t h);
	void Draw(int32_t w, int32_t h);
	void Update();
};
