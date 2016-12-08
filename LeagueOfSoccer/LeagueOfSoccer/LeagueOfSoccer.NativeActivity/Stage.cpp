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

	_walls[4].SetScale(VECTOR4D(0.03f, 0.20f, 1, 1));
	_walls[4].SetPosition(VECTOR4D(-0.8,-.65f,0,1));
	_walls[5].SetScale(VECTOR4D(0.03f, 0.20f, 1, 1));
	_walls[5].SetPosition(VECTOR4D(0.8, -.65f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.30f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.8, 0, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.30f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.8, 0, 0, 1));


	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.20f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.8, 0.65f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.20f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.8, 0.65f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.25f, 0.03f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.35f, 0, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.25f, 0.03f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.35f, 0, 0, 1));

	//Porteria bot
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.15f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.1f, -0.95f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.15f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.1f, -0.95f, 0, 1));
	//Porteria Top
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.15f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.1f, 0.95f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.03f, 0.15f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.1f, 0.95f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.01f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.3f, -0.95f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.01f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.3f, -0.95f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.01f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.3f, 0.95f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.01f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.3f, 0.95f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.2f, 0.01f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.25f, -0.65f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.2f, 0.01f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.25f, -0.65f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.2f, 0.01f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.25f, 0.65f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.2f, 0.01f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.25f, 0.65f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.2f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.45f, -0.65f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.2f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.45f, -0.65f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.2f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.45f, 0.65f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.2f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.45f, 0.65f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.7f, 0.007f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0, -0.20f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.7f, 0.007f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0, 0.20f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.55f, 0.5f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.55f, 0.5f, 0, 1));

	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(0.55f, -0.5f, 0, 1));
	_walls.push_back(Wall());
	_walls.back().SetScale(VECTOR4D(0.005f, 0.3f, 1, 1));
	_walls.back().SetPosition(VECTOR4D(-0.55f, -0.5f, 0, 1));
	
	// Porterias
	_porterias.push_back(Wall());
	_porterias.back().SetScale(VECTOR4D(0.1f, 0.05f, 1, 1));
	_porterias.back().SetPosition(VECTOR4D(0.0f, -0.9f, 0, 1));
	_porterias.push_back(Wall());
	_porterias.back().SetScale(VECTOR4D(0.1f, 0.05f, 1, 1));
	_porterias.back().SetPosition(VECTOR4D(.0f, .9f, 0, 1));
	////////////////////////////
	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, -7 / 8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, 1.f, .2f, 1));

	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, -3 / 8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, 1.f, .2f, 1));

	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, 1/8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, 1.f, .2f, 1));

	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, 5 / 8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, 1.f, .2f, 1));

}


void Stage::Draw(int32_t w, int32_t h)
{
	FOR(u, _fondo.size())
		_fondo[u].Draw();
	for (int i = 0; i < (int)_walls.size(); ++i)
		_walls[i].Draw();
	
	_ball->Draw(w, h);
}

void Stage::Update(int32_t w, int32_t h)
{

	VECTOR4D dir = Normalize(_ball->_velocity);
	FOR(i, _walls.size())
	{
		FOR(j, _walls[i]._triangles.size())
		{
			VECTOR4D plano = _walls[i]._triangles[j].GetPlane();
			VECTOR4D planoMod(plano);
			VECTOR4D rad = _ball->_mesh.m_Vertices[0] - _ball->_position;
			float radius = 0.02f;//Magnity(rad);
			planoMod.w -= radius;
			VECTOR4D nuevaPos = _ball->_position + _ball->_velocity;
			if ((Dot(_ball->_position - (0.005f* dir), planoMod) > 0) && (Dot(nuevaPos + (0.005f* dir), planoMod) < 0)) {
				float denom = Dot(planoMod, dir);
				if (denom == 0) continue;
				float t = (Dot(planoMod, _ball->_position)) / denom;
				VECTOR4D pDeTe = _ball->_position + t*dir;
				if (!PtInTriangle(_walls[i]._triangles[j], pDeTe)) continue;
				VECTOR4D C = pDeTe - radius * _walls[i]._triangles[j].GetNormal();
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
	FOR(i, _porterias.size()) 
	{
		if (_porterias[i].OnColliderEnter(_ball->_position))
		{
			sleep(1);
			delete _ball;
			_ball = new Ball();
			_ball->Initialize(w, h);

		}
	}
}
