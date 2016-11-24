#include "pch.h"
#include "Ball.h"
#include <math.h>

void(*buildBall(vector<VECTOR4D>& vertexArray, vector<VECTOR4D>& colorArray)) {
	//Construir pelota
	for (int i = 0; i < 1600; i++) {
		vertexArray[i] = VECTOR4D(.5f*(sinf((3.1416/2))/i)* (cosf((2 * 3.1416) / i)), .5f*(sinf((3.1416 / 2)) / i)* (sinf((2 * 3.1416) / i)), 0.5f*cosf((3.1416 / 2)) / i,0);
	}
}

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





