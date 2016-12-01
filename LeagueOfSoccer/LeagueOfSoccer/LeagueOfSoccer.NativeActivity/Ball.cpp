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

void Ball::Update(const MATRIX4D W)
{
	VECTOR4D N;
	for (int i = 0; i < (int)_walls.size(); ++i)
		if (_walls[i].IsColiding(_position,_velocity,_positions, W, N)) {
			VECTOR4D V;
			//VECTOR4D N;
			//N = VECTOR4D(1, 0,0, 0);
			//_velocity = ((_velocity - 2 * N*Dot(N, _velocity) )) / 1.2f;//
			//_velocity = (N * 2 * N*Dot(N, _velocity)-_velocity ) / 1.2f;
			//_velocity = _velocity + (_acceleration * 1 / 60);
			//_velocity = _velocity/2 ;
			//_position = _position + _velocity / 60.f + _acceleration * ((1 / 60)*(1 / 60)) / 2;


			float k = 2.f;
			_velocity = -1 * _velocity;
			//_velocity = (_acceleration / k) + (_velocity - (_acceleration / k)*exp(-k / 60));
			_position = _position + (_acceleration / k) / 60.f + ((k * _velocity - (_acceleration)) / (k*k))*(1 - exp(-k / 60.f));
			traslationMTRX = Translation(-_position.x, -_position.y, 0);

			_coliding = true;
			return;
		}
		else {
			_coliding = false;
		}

}

void Ball::Move(VECTOR4D& acceleration)
{
	if (!_coliding)
		_acceleration =   acceleration;
	//_velocity = _velocity + (_acceleration * 1/60 );
	//_position =  _position +_velocity/60.f + acceleration * ((1 / 60)*(1 / 60)) / 2;
	//Movimiento Resistido
	float k = 1.2;
	_velocity = (_acceleration / k) + (_velocity - (_acceleration / k)*exp(-k / 60));
	_position = _position + (_acceleration / k) / 60.f + ((k * _velocity - (_acceleration)) / (k*k))*(1 - exp(-k / 60.f));
	traslationMTRX = Translation( -_position.x , -_position.y ,0);



}

void Ball::Draw(const MATRIX4D& W)
{
	vector<VECTOR4D> transformed(_mesh.m_Vertices);
	for (int i = 0; i < (int)transformed.size(); ++i) {
		transformed[i] = const_cast<MATRIX4D&>(W) * transformed[i];
		transformed[i] = traslationMTRX * transformed[i];
		_positions[i] = transformed[i];
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, &transformed[0]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &_mesh.m_Colors[0]);
	glDrawElements(GL_TRIANGLES, _mesh.m_Indices.size(), GL_UNSIGNED_SHORT, &_mesh.m_Indices[0]);
}

void Ball::Initialize(vector<Wall> walls)
{
	_walls = walls;
	traslationMTRX = Translation(.2, .2, .2);
	_sx = 40;
	_sy = 40;
	_acceleration = VECTOR4D(0, 0, 0, 0);
	_velocity.x = 0;
	_velocity = VECTOR4D(0, 0, 0, 0);
	_position = VECTOR4D(0,0,0,1);
	_color = VECTOR4D(255,255,255,1);
	_mesh.Build(_sx, _sy, buildBall);
	_mesh.BuildIndexBuffer();
	_positions = (_mesh.m_Vertices);
}

Ball::Ball()
{
	_velocity = VECTOR4D(0, 0, 0, 0);
}


Ball::~Ball()
{
}





