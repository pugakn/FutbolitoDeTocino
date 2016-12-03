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
		FOR(j, 12)
		{
			VECTOR4D plane = _walls[i]._triangles[j].GetPlane();
			VECTOR4D normal = _walls[i]._triangles[j].GetNormal();
			VECTOR4D hitPos;
			if (RayCastOnPlane(_ball->_position, dir, plane, hitPos)) 
			{
				if (PtInTriangle(_walls[i]._triangles[j], hitPos))
				{
					VECTOR4D d = hitPos - _ball->_position;
					float dist = Magnity(d);
					VECTOR4D rad = _ball->_mesh.m_Vertices[0] - _ball->_position;
					float radius = Magnity(rad);
					if (dist <= radius) 
					{
						_ball->_velocity = _ball->_velocity - 2 * normal * Dot(normal, _ball->_velocity);
						_ball->_velocity = _ball->_velocity * 0.5f;
						_ball->_velocity.z = 0;
						VECTOR4D hit, n = normal * -1;
						RayCastOnPlane(_ball->_position, n, plane, hit);
						VECTOR4D nDis = hit - _ball->_position + n* radius;
						float Desplazamiento = Magnity(nDis);
						FOR(i, _ball->_mesh.m_Vertices.size())
							_ball->_mesh.m_Vertices[i] = _ball->_mesh.m_Vertices[i] + normal * Desplazamiento;
						_ball->_position = _ball->_position + normal * Desplazamiento;
					}
				}
			}
		}
	}

}
