#include "pch.h"
#include "Wall.h"
#include <math.h>
//
//void Wall::BuildWall()
//{	
//	
//
//}

void Wall::Draw()
{

	for (int i = 0; i < 6; i++) {
		_caras[i].Draw();
	}

	//MATRIX4D local = Identity();
	//for (int i = 0; i < _meshas[0].m_Vertices.size(); i++) {
	//	_meshas[5].m_Vertices[i] = scale * _meshas[5].m_Vertices[i];
	//	_meshas[4].m_Vertices[i] = scale * _meshas[4].m_Vertices[i];
	//	_meshas[3].m_Vertices[i] = scale * _meshas[3].m_Vertices[i];
	//	_meshas[2].m_Vertices[i] = scale * _meshas[2].m_Vertices[i];
	//	_meshas[1].m_Vertices[i] = scale * _meshas[1].m_Vertices[i];
	//	_meshas[0].m_Vertices[i] = scale * _meshas[0].m_Vertices[i];
	//}
	//glEnableClientState(GL_VERTEX_ARRAY);
	//for (int i = 0; i < 6; ++i) {
	//	glEnableClientState(GL_COLOR_ARRAY);
	//	glColorPointer(4, GL_FLOAT, 0, &_meshas[i].m_Colors[0]);
	//	glVertexPointer(4, GL_FLOAT, 0, &_meshas[i].m_Vertices[0]);
	//	glDrawElements(GL_TRIANGLES, _meshas[i].m_Indices.size(), GL_UNSIGNED_SHORT, &_meshas[i].m_Indices[0]);
	//}

	//
	////glEnableClientState(GL_COLOR_ARRAY);
	////glColorPointer(4, GL_FLOAT, 0, &_colors[0]);
	////for (int i = 0; i < 6; ++i)
		

}

void Wall::SetPosition(VECTOR4D pos)
{
	_position = Translation(pos.x,pos.y,pos.z);
}

void Wall::SetScale(VECTOR4D scale)
{
	_scale = Scaling(scale.x, scale.y, scale.z);
}

Wall::~Wall()
{
}
