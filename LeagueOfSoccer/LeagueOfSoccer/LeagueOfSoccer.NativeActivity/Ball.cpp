#include "pch.h"
#include "Ball.h"


void Ball::Initialize()
{
	_position = VECTOR4D(0,0,0,1);
	_acceleration = VECTOR4D(0, 0, 0, 0);
	_velocity = VECTOR4D(0, 0, 0, 0);
	_color = VECTOR4D(255,255,255,1);

	_mesh.Build(40, 40, buildBall);
	_mesh.BuildIndexBuffer();
}

Ball::Ball()
{
}


Ball::~Ball()
{
}

void(*buildBall(vector<VECTOR4D>& vertexArray, vector<VECTOR4D>& colorArray)) {
	//Construir pelota

}



