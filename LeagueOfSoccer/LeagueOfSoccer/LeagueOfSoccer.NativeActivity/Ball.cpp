#include "pch.h"
#include "Ball.h"
#include <math.h>
//#define PI 3.141592f
//#define radio .01f

void buildBall(vector<VECTOR4D>& vertexArray, vector<VECTOR4D>& colorArray,int sx, int sy) {
	//Construir pelota
	float const R = 1.f / (float)(sx - 1);
	float const S = 1.f / (float)(sy - 1);

	for (int r = 0; r < sx; ++r) {
		for (int s = 0; s < sy; ++s) {
			float const z = cos(-M_PI_2 + M_PI * r * R *2);
			float const x = cos(2 * M_PI * s * S) * sin(-M_PI_2 + M_PI * r * R * 2);
			float const y = sin(2 * M_PI * s * S) * sin(-M_PI_2 + M_PI * r * R * 2);
			/*float const y = sin(-M_PI_2 + M_PI * r * R);
			float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
			float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);*/
			VECTOR4D color(0, 0, 0, 1);
			colorArray.push_back(color);
			vertexArray.push_back(VECTOR4D(x,y,z,1));
		}
	}
}

void Ball::Move(VECTOR4D& acceleration)
{
	_acceleration = acceleration;
	_velocity = _velocity + (acceleration * 1/120 );
	traslationMTRX = Translation(-_velocity.x, -_velocity.y,0);
}

void Ball::Draw(const MATRIX4D& W)
{
	vector<VECTOR4D> transformed(_mesh.m_Vertices);
	for (int i = 0; i < (int)transformed.size(); ++i) {
		transformed[i] = const_cast<MATRIX4D&>(W) * transformed[i];
		transformed[i] = traslationMTRX * transformed[i];
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, &transformed[0]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &_mesh.m_Colors[0]);
	glDrawElements(GL_TRIANGLES, _mesh.m_Indices.size(), GL_UNSIGNED_SHORT, &_mesh.m_Indices[0]);
}

void Ball::Initialize()
{
	traslationMTRX = Translation(.2, .2, .2);
	_sx = 40;
	_sy = 40;
	_position = VECTOR4D(0,0,0,1);
	_acceleration = VECTOR4D(0, 0, 0, 0);
	_velocity.x = 0;
	_velocity = VECTOR4D(0, 0, 0, 0);
	_color = VECTOR4D(255,255,255,1);
	_mesh.Build(_sx, _sy, buildBall);
	_mesh.BuildIndexBuffer();
}

Ball::Ball()
{
	_velocity = VECTOR4D(0, 0, 0, 0);
}


Ball::~Ball()
{
}





