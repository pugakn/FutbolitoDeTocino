#include "pch.h"
#include "Stage.h"
#include "math.h"
#include "map"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::CreateFaces()
{

}


void Stage::Setup(int32_t w, int32_t h) // Inicializa el Stage
{
	_ball = new Ball;
	_ball->Initialize(w, h);
	_walls.push_back(Wall());
	_walls.push_back(Wall());
	_walls.push_back(Wall());
	_walls.push_back(Wall());

	_walls[0].SetScale(VECTOR4D(1,0.05f,1,1));
	_walls[0].SetPosition(VECTOR4D(0.f,0.95f,0,1));
	_walls[1].SetScale(VECTOR4D(1, 0.05f, 1, 1));
	_walls[1].SetPosition(VECTOR4D(0.f, -0.95f, 0, 1));

	_walls[2].SetScale(VECTOR4D(0.05f, 1, 1, 1));
	_walls[2].SetPosition(VECTOR4D(-0.95f, 0, 0, 1));
	_walls[3].SetScale(VECTOR4D(0.05, 1, 1, 1));
	_walls[3].SetPosition(VECTOR4D(0.95f, 0, 0, 1));
	
}


void Stage::Draw(int32_t w, int32_t h)
{
	for (int i = 0; i < (int)_walls.size(); ++i)
		_walls[i].Draw();


	_ball->Draw(w, h);
}

void Stage::Update()
{

	VECTOR4D dir = Normalize(_ball->_velocity);
	FOR(i, _walls.size())
	{
		FOR(j, _walls[i]._triangles.size())
		{
			VECTOR4D plano = _walls[i]._triangles[j].GetPlane();
			VECTOR4D planoMod(plano);
			VECTOR4D rad = _ball->_mesh.m_Vertices[0] - _ball->_position;
			float radius = Magnity(rad);
			planoMod.w -= radius;
			VECTOR4D nuevaPos = _ball->_position + _ball->_velocity;
			if ((Dot(_ball->_position - (0.005* dir), planoMod) > 0) && (Dot(nuevaPos + (0.005* dir), planoMod) < 0)) {
				float denom = Dot(planoMod, dir);
				if (denom == 0) continue;
				float t = (Dot(planoMod, _ball->_position)) / denom;
				VECTOR4D pDeTe = _ball->_position + t*dir;
				VECTOR4D C = pDeTe + radius * _walls[i]._triangles[j].GetNormal();
				C.z = 0;
				VECTOR4D dist = pDeTe - _ball->_position + (_walls[i]._triangles[j].GetNormal()* 0.003f);
				_ball->_position = _ball->_position + dist;
				FOR(i, _ball->_mesh.m_Vertices.size())
					_ball->_mesh.m_Vertices[i] = _ball->_mesh.m_Vertices[i] + dist;

				_ball->_velocity = _ball->_velocity - 2* _walls[i]._triangles[j].GetNormal() * Dot(_walls[i]._triangles[j].GetNormal(), _ball->_velocity);
				_ball->_velocity = _ball->_velocity * 0.55f;
			}
		}
	}

}
