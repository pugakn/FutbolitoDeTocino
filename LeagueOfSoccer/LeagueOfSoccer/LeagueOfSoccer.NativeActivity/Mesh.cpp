#include "pch.h"
#include "Mesh.h"
#include <math.h>


void Mesh::BuildIndexBuffer()
{
	m_Indices.clear();
	m_Indices.resize((m_sx - 1)*(m_sy - 1) * 6);
	int x;
	int index = 0;

	for (int j = 0; j < m_sy - 1; j++) {
		x = j * m_sx;
		for (int i = 0; i < m_sx - 1; i++)
		{
			m_Indices[index] = x;
			x += m_sx;
			index++;
			m_Indices[index] = x;
			index++;
			x -= (m_sx - 1);
			m_Indices[index] = x;
			index++;
			m_Indices[index] = x;
			x += (m_sx - 1);
			index++;
			m_Indices[index] = x;
			x += 1;
			index++;
			m_Indices[index] = x;
			x -= m_sx;
			index++;
		}
	}
	//producir la secuencia de indices para graficar la superficie
}

void Mesh::Build(int sx, int sy, void(*func)(vector<VECTOR4D>& vertexArray, vector<VECTOR4D>& colorArray, int sx, int sy))
{
	//m_Vertices.clear();
	m_sx = sx;
	m_sy = sy;
	//m_Vertices.resize(sx*sy);
	//m_Colors.clear();
	//m_Colors.resize(sx*sy);

	func(m_Vertices,m_Colors,m_sx,m_sy);

}

void Mesh::SetVertexArray(const std::vector<VECTOR4D>& vec)
{
	m_Vertices.clear();
	m_Vertices = vec;
}


Mesh::Mesh()
{
	m_sy = 0;
	m_sx = 0;
}


Mesh::~Mesh()
{
}
