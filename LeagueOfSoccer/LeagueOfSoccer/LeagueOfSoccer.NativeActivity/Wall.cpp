#include "pch.h"
#include "Wall.h"

void Wall::BuildWall(const vector<VECTOR4D>& vertex)
{
	_mesh.SetVertexArray(vertex);
	_mesh.m_sx = 2;
	_mesh.m_sy = 2;
	//Hacer la muralla de color rojo
	_mesh.m_Colors.clear();
	for (int i = 0; i < (int)_mesh.m_Vertices.size(); ++i)
		_mesh.m_Colors.push_back(VECTOR4D(1,0,0,1));

	_mesh.BuildIndexBuffer();
}

void Wall::Draw(const MATRIX4D& W)
{
	vector<VECTOR4D> transformed(_mesh.m_Vertices);
	for (int i = 0; i < (int)transformed.size(); ++i)
		transformed[i] = const_cast<MATRIX4D&>(W) * transformed[i];

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, &transformed[0]);
	
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &_mesh.m_Colors[0]);

	glDrawElements(GL_TRIANGLES, _mesh.m_Indices.size(), GL_UNSIGNED_SHORT, &_mesh.m_Indices[0]);
}

Wall::Wall()
{
}


Wall::~Wall()
{
}
