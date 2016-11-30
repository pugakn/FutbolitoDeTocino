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
	//FACK PLANTEAR METODO PARA QUE SE VEA IGUAL EN TODOS LOS CELULARES
	_ball = new Ball;
	//_ball->_position = VECTOR4D(10,10,10, 1);
	_walls.resize(8);
	/*********************BORDES*******************/
	_walls[0].SetScale(VECTOR4D(0.2f, 1, 10, 0));
	_walls[0].SetPosition(VECTOR4D(-5.9f,0,0,1));
	_walls[1].SetScale(VECTOR4D(7, 1, 0.2f, 0));
	_walls[1].SetPosition(VECTOR4D(0, 0, 9.8f, 1));
	_walls[2].SetScale(VECTOR4D(0.2f, 1, 10, 0));
	_walls[2].SetPosition(VECTOR4D(5.9f, 0, 0, 1));
	_walls[3].SetScale(VECTOR4D(7, 1, 0.2f, 0));
	_walls[3].SetPosition(VECTOR4D(0, 0, -8.95f, 1));
	/**********************************************/
	/*******************PORTERIAS******************/
	_walls[4].SetScale(VECTOR4D(0.2f, 1 , 1.f, 0));
	_walls[4].SetPosition(VECTOR4D(-2.f,0,-7.75f,1));
	_walls[5].SetScale(VECTOR4D(0.2f, 1, 1.f, 0));
	_walls[5].SetPosition(VECTOR4D(2.f,0, -7.75f,1));
	_walls[6].SetScale(VECTOR4D(0.2f, 1, 1.f, 0));
	_walls[6].SetPosition(VECTOR4D(2.f, 0, 8.6f, 1));
	_walls[7].SetScale(VECTOR4D(0.2f, 1, 1.f, 0));
	_walls[7].SetPosition(VECTOR4D(-2.f, 0, 8.6f, 1));
	/**********************************************/
	_ball->Initialize(_walls);
}

void Stage::Draw(const MATRIX4D& W)
{
	for (int i = 0; i < (int)_walls.size(); ++i)
		_walls[i].Draw(W);
	_ball->Draw(W);
}

void Stage::Update(const MATRIX4D& W)
{
	_ball->Update(W);
	/*for (int i = 0; i < (int)_walls.size(); ++i)
		if (_walls[i].IsColiding(_ball->_positions, W)) {
			_walls.clear();
		}*/
}
