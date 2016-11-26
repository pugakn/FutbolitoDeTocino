#include "pch.h"
#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Setup()
{
	_ball.Initialize();
	_walls.resize(4);
	_walls[0].SetScale(VECTOR4D(1,1,2,0));
	_walls[1].SetScale(VECTOR4D(2,1,1,0));
}

void Stage::Draw(const MATRIX4D& W)
{
	for (int i = 0; i < (int)_walls.size(); ++i)
		_walls[i].Draw(W);
	//_ball.Draw(W);
}
