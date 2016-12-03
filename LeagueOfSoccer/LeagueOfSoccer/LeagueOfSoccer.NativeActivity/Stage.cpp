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
	_walls[0].SetScale(VECTOR4D(0.1,0.1,1,1));
	_walls[0].SetPosition(VECTOR4D(0.3f,0.3f,0,1));
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
					}
				}
			}
		}
	}

	//std::map<float, Cara*> colisiones;
	//_ball->_acceleration; // velocidad
	//_ball->_velocity; //Posicion
	//VECTOR4D v = Normalize(_ball->_acceleration);
	//for (int i = 0; i < _walls.size(); ++i)
	//{
	//	for (int j = 0; j < 6; ++j)
	//	{
	//		Cara& actual = _walls[i]._caras[j];
	//		VECTOR4D inter;
	//		if (RayCastOnPlane(_ball->_velocity, v, actual._plano, inter))
	//		{
	//			float w, w2;
	//			if (PtInTriangle(actual._tr[0].A, actual._tr[0].B, actual._tr[0].C, inter, w, w2))
	//			{
	//				VECTOR4D l = inter - _ball->_velocity;
	//				float d = sqrtf(Dot(l, l));
	//				colisiones[d] = &actual;
	//			}
	//			else if(PtInTriangle(actual._tr[1].A, actual._tr[1].B, actual._tr[1].C, inter, w, w2))
	//			{
	//				VECTOR4D l = inter - _ball->_velocity;
	//				float d = sqrtf(Dot(l, l));
	//				colisiones[d] = &actual;
	//			}
	//		}
	//	}
	//}

	//if (colisiones.empty()) return;
	//std::map<float, Cara*>::iterator it = colisiones.begin();
	//std::pair<const float, Cara*> *best = &(*it);
	//while (++it != colisiones.end()) {
	//	if (it->first < best->first)
	//		best = &(*it);
	//}

	//VECTOR4D point = _ball->_mesh.m_Vertices[0];
	//VECTOR4D dist = point - _ball->_velocity;
	//float r = Magnity(dist);
	//if (best->first <= r)
	//{
	//	VECTOR4D vel = _ball->_acceleration - 2 * best->second->_normal * Dot(best->second->_normal, _ball->_acceleration);
	//	_ball->_acceleration = vel;
	//}
}
