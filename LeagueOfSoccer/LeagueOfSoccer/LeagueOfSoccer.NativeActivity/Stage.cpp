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
std::vector<Cara> Stage::CreateBox(VECTOR4D up[], VECTOR4D down[]) { 
	//SI los armadillos comienzan a volar podemos intuir por eliminacion 
	//geografica que los dinosaurios no tuviron vida social porque eran muy 
	//gordos y se la pasaban comiendo champis en la choza de don pepe.
	std::vector<Cara> temp;
	temp.push_back(Cara(up));
	temp.push_back(Cara(down));
	VECTOR4D sideR[4];
	sideR[0] = down[3];
	sideR[1] = up[3];
	sideR[2] = up[2];
	sideR[3] = down[2];
	temp.push_back(Cara(sideR));
	VECTOR4D sideL[4];
	sideL[0] = down[1];
	sideL[1] = up[1];
	sideL[2] = up[0];
	sideL[3] = down[0];
	temp.push_back(Cara(sideL));
	VECTOR4D sideD[4];
	sideD[0] = down[0];
	sideD[1] = up[0];
	sideD[2] = up[3];
	sideD[3] = down[3];
	temp.push_back(Cara(sideD));
	VECTOR4D sideU[4];
	sideU[0] = down[2];
	sideU[1] = up[2];
	sideU[2] = up[1];
	sideU[3] = down[1];
	temp.push_back(Cara(sideU));
	
	return temp;
}
void Stage::Setup() // Inicializa el Stage
{
	//FACK PLANTEAR METODO PARA QUE SE VEA IGUAL EN TODOS LOS CELULARES
	_ball = new Ball;
	_ball->Initialize();
	//_ball->_position = VECTOR4D(10,10,10, 1);
	VECTOR4D up[4];
	up[0] = VECTOR4D(-1,1,1,1);
	up[1] = VECTOR4D(-1,1,-1,1);
	up[2] = VECTOR4D(1,1,-1,1);
	up[3] = VECTOR4D(1,1,1,1);
	VECTOR4D down[4];
	down[0] = VECTOR4D(-1,-1,1,1);
	down[1] = VECTOR4D(-1,-1,-1,1);
	down[2] = VECTOR4D(1,-1,-1,1);
	down[3] = VECTOR4D(1,-1,1,1);
	_walls.push_back(Wall(CreateBox(up,down)));



	///*_walls.resize(8);*/
	///*********************BORDES*******************/
	///*_walls[0].SetScale(VECTOR4D(0.2f, 1, 10, 0));
	//_walls[0].SetPosition(VECTOR4D(-5.9f,0,0,1));
	//_walls[1].SetScale(VECTOR4D(7, 1, 0.2f, 0));
	//_walls[1].SetPosition(VECTOR4D(0, 0, 9.8f, 1));
	//_walls[2].SetScale(VECTOR4D(0.2f, 1, 10, 0));
	//_walls[2].SetPosition(VECTOR4D(5.9f, 0, 0, 1));
	//_walls[3].SetScale(VECTOR4D(7, 1, 0.2f, 0));
	//_walls[3].SetPosition(VECTOR4D(0, 0, -8.95f, 1));*/
	///**********************************************/
	///*******************PORTERIAS******************/
	///*_walls[4].SetScale(VECTOR4D(0.2f, 1 , 1.f, 0));
	//_walls[4].SetPosition(VECTOR4D(-2.f,0,-7.75f,1));
	//_walls[5].SetScale(VECTOR4D(0.2f, 1, 1.f, 0));
	//_walls[5].SetPosition(VECTOR4D(2.f,0, -7.75f,1));
	//_walls[6].SetScale(VECTOR4D(0.2f, 1, 1.f, 0));
	//_walls[6].SetPosition(VECTOR4D(2.f, 0, 8.6f, 1));
	//_walls[7].SetScale(VECTOR4D(0.2f, 1, 1.f, 0));
	//_walls[7].SetPosition(VECTOR4D(-2.f, 0, 8.6f, 1));*/
	///**********************************************/
}


void Stage::Draw(int32_t w, int32_t h)
{
	for (int i = 0; i < (int)_walls.size(); ++i)
		_walls[i].Draw();

	//vector<VECTOR4D> test1(6);

	//test1[0] = VECTOR4D(-1.f, 1.0f, 0.f, 1);
	//test1[1] = VECTOR4D(-1.f, -1.0f, 0.f, 1);
	//test1[2] = VECTOR4D(1.f, -1.0f, 0.f, 1);
	//
	//test1[3] = VECTOR4D(1.f, -1.0f, 0.f, 1);
	//test1[4] = VECTOR4D(1.f, 1.0f, 0.f, 1);
	//test1[5] = VECTOR4D(-1.f, 1.0f, 0.f, 1);


	//glEnableClientState(GL_VERTEX_ARRAY);
	//glVertexPointer(4, GL_FLOAT, 0, &test1[0]);
	//glDrawArrays(GL_TRIANGLES, 0, 6);


	_ball->Draw(w, h);
}

void Stage::Update()
{
	std::map<float, Cara*> colisiones;
	_ball->_acceleration; // velocidad
	_ball->_velocity; //Posicion
	VECTOR4D v = Normalize(_ball->_acceleration);
	for (int i = 0; i < _walls.size(); ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			Cara& actual = _walls[i]._caras[j];
			VECTOR4D inter;
			if (RayCastOnPlane(_ball->_velocity, v, actual._plano, inter))
			{
				float w, w2;
				if (PtInTriangle(actual._tr[0].A, actual._tr[0].B, actual._tr[0].C, inter, w, w2))
				{
					VECTOR4D l = inter - _ball->_velocity;
					float d = sqrtf(Dot(l, l));
					colisiones[d] = &actual;
				}
				else if(PtInTriangle(actual._tr[1].A, actual._tr[1].B, actual._tr[1].C, inter, w, w2))
				{
					VECTOR4D l = inter - _ball->_velocity;
					float d = sqrtf(Dot(l, l));
					colisiones[d] = &actual;
				}
			}
		}
	}

	if (colisiones.empty()) return;
	std::map<float, Cara*>::iterator it = colisiones.begin();
	std::pair<const float, Cara*> *best = &(*it);
	while (++it != colisiones.end()) {
		if (it->first < best->first)
			best = &(*it);
	}

	VECTOR4D point = _ball->_mesh.m_Vertices[0];
	VECTOR4D dist = point - _ball->_velocity;
	float r = Magnity(dist);
	if (best->first <= r)
	{
		VECTOR4D vel = _ball->_acceleration - 2 * best->second->_normal * Dot(best->second->_normal, _ball->_acceleration);
		_ball->_acceleration = vel;
	}
}
