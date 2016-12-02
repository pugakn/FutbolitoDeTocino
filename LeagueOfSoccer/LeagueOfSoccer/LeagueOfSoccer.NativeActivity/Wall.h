#pragma once
//const vector<VECTOR4D>& vertex
#include "Mesh.h"
#include "Cara.h"

class Stage;

class Wall
{
	friend Stage;
public:
	vector<Cara> _caras;
	vector<Mesh> _meshas;
	vector<VECTOR4D> _colors;
	MATRIX4D _scale;
	MATRIX4D _position;
	VECTOR4D _color;
public:
	void Draw();
	void SetPosition(VECTOR4D pos);
	void SetScale(VECTOR4D scale);
	Wall(vector<Cara> caras) : _caras(caras)
	{
	/*	_position = Translation(0, 0, 0);
		_scale = Scaling(1, 1, 1);
		_meshas.resize(6);
		VECTOR4D colors[6] = {
		VECTOR4D(0, 0, 0, 1),
		VECTOR4D(1, 0, 0, 1),
		VECTOR4D(0, 1, 0, 1),
		VECTOR4D(0, 0, 1, 1),
		VECTOR4D(1, 1, 1, 1),
		VECTOR4D(.5, 0, .5, 1)
		};

		for (int i = 0; i < 6; ++i)
		{
			_meshas[i].SetVertexArray(_caras[i].GetVertex());
			_meshas[i].m_Colors.resize(4);
			for (int w = 0; w < 4; w++) {
				_meshas[i].m_Colors[w] = colors[i];
			}
			_meshas[i].m_sx = 2;
			_meshas[i].m_sy = 2;
			_meshas[i].BuildIndexBuffer();
		}*/
	}
	~Wall();
};

