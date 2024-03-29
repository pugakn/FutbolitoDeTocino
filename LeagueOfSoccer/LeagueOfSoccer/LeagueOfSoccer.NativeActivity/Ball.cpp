#include "pch.h"
#include "Ball.h"
#include <math.h>
//#define PI 3.141592f
//#define radio .01f

void buildBall(vector<VECTOR4D>& vertexArray, vector<VECTOR4D>& colorArray,int sx, int sy) {
	//Construir pelota
	float PI = 3.14;
	float radio = 1;
	float increRad = PI / sx;
	for (float teta = 0; teta <= PI; teta += increRad) {
		for (float phi = 0; phi <= (2 * PI); phi += increRad) {
			VECTOR4D temp;
			temp.x = (radio)*((float)sinf(teta))*((float)cosf(phi));
			temp.y = (radio)*((float)sinf(teta))*((float)sinf(phi));
			temp.z = (radio)*((float)cosf(teta));
			temp.w = 1;
			VECTOR4D color(0,0,0, 1);
			colorArray.push_back(color);
			vertexArray.push_back(temp);
		}
	}
}

void Ball::Draw(const MATRIX4D& W)
{
	vector<VECTOR4D> transformed(_mesh.m_Vertices);
	for (int i = 0; i < (int)transformed.size(); ++i)
		transformed[i] = const_cast<MATRIX4D&>(W) * transformed[i];
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, &transformed[0]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &_mesh.m_Colors[0]);
	glDrawElements(GL_TRIANGLES, _mesh.m_Indices.size(), GL_UNSIGNED_SHORT, &_mesh.m_Indices[0]);
}

void Ball::Initialize()
{
	_sx = 40;
	_sy = 40;
	_position = VECTOR4D(0,0,0,1);
	_acceleration = VECTOR4D(0, 0, 0, 0);
	_velocity = VECTOR4D(0, 0, 0, 0);
	_color = VECTOR4D(255,255,255,1);
	_mesh.Build(_sx, _sy, buildBall);
	_mesh.BuildIndexBuffer();
}

Ball::Ball()
{
}


Ball::~Ball()
{
}





