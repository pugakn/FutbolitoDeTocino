#include "pch.h"
#include "Stage.h"
#include "math.h"
#include "map"
#define P 3.141592

#define FORA(a, b , c , d) for(int a = b; a < c; a+= d)

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

	_walls[0].SetScale(VECTOR4D(1,0.01f,1,1));
	_walls[0].SetPosition(VECTOR4D(0.f,0.99f,0,1));
	_walls[1].SetScale(VECTOR4D(1, 0.01f, 1, 1));
	_walls[1].SetPosition(VECTOR4D(0.f, -0.99f, 0, 1));

	_walls[2].SetScale(VECTOR4D(0.01f, 1, 1, 1));
	_walls[2].SetPosition(VECTOR4D(-0.99f, 0, 0, 1));

	_walls[3].SetScale(VECTOR4D(0.01, 1, 1, 1));
	_walls[3].SetPosition(VECTOR4D(0.99f, 0, 0, 1));

	FORA(i, -1, 2, 2) {
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02406f, 0.03938f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.07812f, 0.94812f, 0, 1));
		
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02f, 0.1f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.216f, 0.886f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.0821f, 0.01442f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.1539f, 0.7985f, 0, 1));
		
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.017f, 0.0525f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.35138f, 0.9375f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.12625f, 0.01281f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.46313f, 0.89657f, 0, 1));
		
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02188f, 0.06219f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.35626f, 0.75219f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.06563f, 0.01219f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.27939f, 0.70219f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01700f, 0.05250f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.35138f, 0.93750f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.12625f, 0.01281f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.46375f, 0.89781f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02700f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.06630f, 0.70004f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02653f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.02653f, 0.47210f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02700f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.17094f, 0.47374f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.05356f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.36374f, 0.47250f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.16156f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.68906f, 0.65594f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.12969f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.82750f, 0.60563f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01262f, 0.01396f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.01262f, 0.22446f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.18304f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.18304f, 0.33942f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02731f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.47553f, 0.34118f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.0f, 0.01438f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.65312f, 0.33656f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.16156f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.690f, 0.25374f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.12969f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.82764f, 0.27845f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.14825f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.26969f, 0.22098f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02731f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.54605f, 0.22624f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.05544f, 0.01438f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.65312f, 0.33656f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.04662f, 0.01127f, 1, 1));
		_walls.back().SetRotatation(i*3*P / 8.f);
		_walls.back().SetPosition(VECTOR4D(i*0.20572f, 0.66049f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.04662f, 0.01157f, 1, 1));
		_walls.back().SetRotatation(i * P / 16.f);
		_walls.back().SetPosition(VECTOR4D(i*0.14452f, 0.611327f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.03521f, 0.01281f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.71859f, 0.89803f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.03521f, 0.01281f, 1, 1));
		_walls.back().SetRotatation(i * P / -6.f);
		_walls.back().SetPosition(VECTOR4D(i*0.77445f, 0.88345f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01291f, 0.03525f, 1, 1));
		_walls.back().SetRotatation(i * P / 8.f);
		_walls.back().SetPosition(VECTOR4D(i*0.81793f, 0.83879f, 0, 1));
		
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.22f, 0.00892f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.49126f, 0.00892f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.06995f, 0.00892f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.89121f, 0.00892f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02011f, 0.01392f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.06871f, 0.11808f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01392f, 0.02011f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.14406f, 0.04343f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.04935f, 0.01392f, 1, 1));
		_walls.back().SetRotatation(i * P / -4.f);
		_walls.back().SetPosition(VECTOR4D(i*0.11355f, 0.08698f, 0, 1));



		
		//////////////////////////////////////////
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02406f, 0.03938f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.07812f, -0.94812f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02f, 0.1f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.216f, -0.886f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.0821f, 0.01442f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.1539f, -0.7985f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.017f, 0.0525f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.35138f, -0.9375f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.12625f, 0.01281f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.46313f, -0.89657f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02188f, 0.06219f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.35626f, -0.75219f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.06563f, 0.01219f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.27939f, -0.70219f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01700f, 0.05250f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.35138f, -0.93750f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.12625f, 0.01281f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.46375f, -0.89781f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02700f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.06630f, -0.70004f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02653f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.02653f, -0.47210f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02700f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.17094f, -0.47374f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.05356f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.36374f, -0.47250f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.16156f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.68906f, -0.65594f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.12969f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.82750f, -0.60563f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01262f, 0.01396f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.01262f, -0.22446f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.18304f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.18304f, -0.33942f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02731f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.47553f, -0.34118f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.0f, 0.01438f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.65312f, -0.33656f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.16156f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.690f, -0.25374f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01856f, 0.12969f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.82764f, -0.27845f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.14825f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.26969f, -0.22098f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02731f, 0.01750f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.54605f, -0.22624f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.05544f, 0.01438f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.65312f, -0.33656f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.04662f, 0.01127f, 1, 1));
		_walls.back().SetRotatation(-i * 3 * P / 8.f);
		_walls.back().SetPosition(VECTOR4D(i*0.20572f, -0.66049f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.04662f, 0.01157f, 1, 1));
		_walls.back().SetRotatation(-i * P / 16.f);
		_walls.back().SetPosition(VECTOR4D(i*0.14452f, -0.611327f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.03521f, 0.01281f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.71859f, -0.89803f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.03521f, 0.01281f, 1, 1));
		_walls.back().SetRotatation(-i * P / -6.f);
		_walls.back().SetPosition(VECTOR4D(i*0.77445f, -0.88345f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01291f, 0.03525f, 1, 1));
		_walls.back().SetRotatation(-i * P / 8.f);
		_walls.back().SetPosition(VECTOR4D(i*0.81793f, -0.83879f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.22f, 0.00892f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.49126f, -0.00892f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.06995f, 0.00892f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.89121f, -0.00892f, 0, 1));

		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.02011f, 0.01392f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.06871f, -0.11808f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.01392f, 0.02011f, 1, 1));
		_walls.back().SetPosition(VECTOR4D(i*0.14406f, -0.04343f, 0, 1));
		_walls.push_back(Wall());
		_walls.back().SetScale(VECTOR4D(0.04935f, 0.01392f, 1, 1));
		_walls.back().SetRotatation(-i * P / -4.f);
		_walls.back().SetPosition(VECTOR4D(i*0.11355f, -0.08698f, 0, 1));
	}
	FOR(j, _walls.size()) {
		_walls[j].SetColor(VECTOR4D(1.f, 1.f, 1.f, 0.f));
	}
	// Porterias
	_porterias.push_back(Wall());
	_porterias.back().SetScale(VECTOR4D(0.06109f, 0.02672f, 1, 1));
	_porterias.back().SetPosition(VECTOR4D(-0.00797f, -0.95954f, 0, 1));
	_porterias.push_back(Wall());
	_porterias.back().SetScale(VECTOR4D(0.06109f, 0.02672f, 1, 1));
	_porterias.back().SetPosition(VECTOR4D(-0.00797f, 0.95954f, 0, 1));
	////////////////////////////
	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, -7 / 8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, .5f, 0.f, 1));

	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, -3 / 8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, .5f, 0.f, 1));

	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, 1/8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, .5f, 0.f, 1));

	_fondo.push_back(fondo());
	_fondo.back().SetScale(VECTOR4D(1.f, 1 / 8.f, 1.f, 1.f));
	_fondo.back().SetPosition(VECTOR4D(0.f, 5 / 8.f, 0.f, 1.f));
	_fondo.back().SetColor(VECTOR4D(0.f, .5f, 0.f, 1));

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
