#include "pch.h"
#include "Ball.h"
#include <math.h>
//#define PI 3.141592f
//#define radio .01f

void buildBall(vector<VECTOR4D>& vertexArray, vector<VECTOR4D>& colorArray,int sx, int sy) {
	//Construir pelota
	float const R = 1.f / (float)(sx - 1);
	float const S = 1.f / (float)(sy - 1);
	float radio = .05f;
	for (int r = 0; r < sx; ++r) {
		for (int s = 0; s < sy; ++s) {
			float const z = radio * cos(-M_PI_2 + M_PI * r * R *2);
			float const x = radio * cos(2 * M_PI * s * S) * sin(-M_PI_2 + M_PI * r * R * 2);
			float const y = radio *sin(2 * M_PI * s * S) * sin(-M_PI_2 + M_PI * r * R * 2);
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
	acceleration.z = 0;
	//if (!_coliding)
		_acceleration = -1 * acceleration;

	float k = 5;
	_velocity = (_acceleration / k) + (_velocity - (_acceleration / k)*exp(-k / 60));
	_velocity.z = 0;
	_position = _position + (_acceleration / k) / 60.f + ((k * _velocity - (_acceleration)) / (k*k))*(1 - exp(-k / 60.f));
	//traslationMTRX = Translation(_position.x * 0.01f, _position.y * 0.01f, 0);
	//FOR(i, _mesh.m_Vertices.size()) _mesh.m_Vertices[i] = traslationMTRX * _mesh.m_Vertices[i];

	/*_velocity = _velocity + acceleration * -0.1f;
	_velocity.z = 0;*/
	FOR(i, _mesh.m_Vertices.size()) _mesh.m_Vertices[i] = _mesh.m_Vertices[i] + (_acceleration / k) / 60.f + ((k * _velocity - (_acceleration)) / (k*k))*(1 - exp(-k / 60.f));
	//_position = _position + _velocity * 0.0007f;
}


void Ball::Draw(int32_t w, int32_t h)
{	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, &_mesh.m_Vertices[0]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &_mesh.m_Colors[0]);
	glDrawElements(GL_TRIANGLES, _mesh.m_Indices.size(), GL_UNSIGNED_SHORT, &_mesh.m_Indices[0]);
}

void Ball::Initialize(int32_t w, int32_t h)
{
	_position = VECTOR4D(0, 0, 0, 1);
	_sx = 40;
	_sy = 40;
	_acceleration = VECTOR4D(0, 0, 0, 0);
	_velocity.x = 0;
	_velocity = VECTOR4D(0, 0, 0, 0);
	_color = VECTOR4D(255,255,255,1);
	_mesh.Build(_sx, _sy, buildBall);
	_mesh.BuildIndexBuffer();
	MATRIX4D SAspect = Scaling(h / (float)w, 1, 1);
	FOR(i, _mesh.m_Vertices.size()) _mesh.m_Vertices[i] = SAspect * _mesh.m_Vertices[i];
}

Ball::Ball()
{
	_velocity = VECTOR4D(0, 0, 0, 0);
}


Ball::~Ball()
{
}





