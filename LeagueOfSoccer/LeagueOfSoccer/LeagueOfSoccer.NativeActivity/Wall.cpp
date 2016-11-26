#include "pch.h"
#include "Wall.h"
#include <math.h>
//
//void Wall::BuildWall()
//{	
//	
//
//}

void Wall::Draw(const MATRIX4D& W)
{
	MATRIX4D local = Identity();
	
	local *= _scale;
	local *= _position;
	local *= const_cast<MATRIX4D&>(W);
	vector<VECTOR4D> transformed(_vertexArray);
	for (int i = 0; i < (int)transformed.size(); ++i)
		transformed[i] = local * transformed[i];

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, &transformed[0]);
	
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &_colors[0]);
	
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 12*3 indices starting at 0 -> 12 triangles -> 6 squares

}

void Wall::SetPosition(VECTOR4D pos)
{
	_position = Translation(pos.x,pos.y,pos.z);
}

void Wall::SetScale(VECTOR4D scale)
{
	_scale = Scaling(scale.x, scale.y, scale.z);
}

Wall::Wall()
{
	_position = Translation(0, 0, 0);
	_scale = Scaling(1, 1, 1);

	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, 1.0f, 1)); 
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, -1.0f, 1)); 
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, -1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, 1.0f, 1));
	
	for (int i = 0; i < (int)_vertexArray.size(); ++i)
		_colors.push_back(VECTOR4D((sinf(i) + 1) / 2, (cosf(i) + 1)/2, (sinf(i)*cosf(i) +  1) / 2, 1));

}


Wall::~Wall()
{
}
