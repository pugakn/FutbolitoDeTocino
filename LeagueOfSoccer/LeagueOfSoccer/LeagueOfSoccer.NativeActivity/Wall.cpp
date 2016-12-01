#include "pch.h"
#include "Wall.h"
#include <math.h>
//
//void Wall::BuildWall()
//{	
//	
//
//}

/*bool HitTestTTriangle(TRIANGLE triangle, VECTOR4D point)
{
	VECTOR4D u = triangle.v1 - triangle.v0;
	VECTOR4D p = point - triangle.v0;
	VECTOR4D c1 = Cross3(u, p);

	u = triangle.v2 - triangle.v1;
	p = point - triangle.v1;
	VECTOR4D c2 = Cross3(u, p);

	u = triangle.v0 - triangle.v2;
	p = point - triangle.v2;
	VECTOR4D c3 = Cross3(u, p);
	return (((c1.z < 0) && (c2.z < 0) && (c3.z < 0)) || ((c1.z > 0) && (c2.z > 0) && (c3.z > 0)));
}*/

void Wall::Draw(const MATRIX4D& W)
{
	MATRIX4D local = W;
	local *= _position;
	local *= _scale;
	//local *= const_cast<MATRIX4D&>(W);
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

bool Wall::IsColiding(VECTOR4D S, VECTOR4D V,vector<VECTOR4D> posicion, const MATRIX4D& W, VECTOR4D& N)
{
	MATRIX4D local = W;
	local *= _position;
	local *= _scale;
	vector<VECTOR4D> _TVertexArray;
	VECTOR4D temp;
	temp = VECTOR4D(1.0f, 1.0f, 1.0f, 1);
	temp = local * temp;
	_TVertexArray.push_back( temp );
	temp = VECTOR4D(-1.0f, 1.0f, -1.0f, 1);
	temp = local * temp;
	_TVertexArray.push_back(  temp);


	/***********************************/
	VECTOR4D x0 (-1,0,0,1);
	VECTOR4D Tx0 = local * x0;
	VECTOR4D x1(1, 0, 0, 1);
	VECTOR4D Tx1 = local * x1;
	VECTOR4D y0(0, -1, 0, 1);
	VECTOR4D Ty0 = local * y0;
	VECTOR4D y1(0, 1, 0, 1);
	VECTOR4D Ty1 = local * y1;
	VECTOR4D z0(0, 0, -1, 1);
	VECTOR4D Tz0 = local * z0;
	VECTOR4D z1(0, 0, 1, 1);
	VECTOR4D Tz1 = local * z1;
	float t = 1 / 60;;
	if (V.x != 0) {
		if (V.x > 0) {
			//t = (Tx0.x - S.x) / V.x;
			N = x0;
		}
		else {
			//t = (Tx1.x - S.x) / V.x;
			N = x1;
		}
		if ((Ty0.y <= (S + t*V).y <= Ty1.y) && (Tz0.z <= (S + t*V).z <= Tz1.z)) {
			//if (t < (1 / 60.f) && t> (-1 / 60.f))
			if(Dot(N,S + t*V) < 0)
				return true;
		}
	}

	if (V.y != 0) {
		if (V.y > 0) {
			t = (Tz0.z - S.y) / V.y;
			N = y0;
		}
		else {
			t = (Tz1.z - S.y) / V.y;
			N = y1;
		}
		if ((Tx0.x <= (S + t*V).x <= Tx1.x) && (Ty0.y <= (S + t*V).z <= Ty1.y)) {
			if (t < 1 / 600.f && t> 1 / 600.f);
				//return true;
		}
	}

	if (V.z != 0) {
		if (V.z > 0) {
			t = (Ty0.y - S.z) / V.z;
			N = z0;
		}
		else {
			t = (Ty1.y - S.z) / V.z;
			N = z1;
		}
		if ((Tz0.z <= (S + t*V).y <= Tz1.z) && (Tx0.x <= (S + t*V).x <= Tx1.x)) {
			if (t < 1 / 600.f && t> 1 / 600.f);
				//return true;
		}
	}

	

	/*if (V.x == 0) {
		no x = 0 || x = r.x;
	}
	if (V.x > 0) {
		no x = r.x;
	}
	if (V.z < 0) {
		no x = 0;
	}*/

	//P(t) = S+ tV

	//t = (r.x - s.x)/v.x Con plano x = rx
	//0<= pty <=ry
	//0<= ptz <= r<  true;
	/***********************************/

	/*for (int i = 0; i < posicion.size(); i++) {
		if (posicion[i].x > _TVertexArray[1].x && posicion[i].x < _TVertexArray[0].x &&
			posicion[i].y > _TVertexArray[1].z && posicion[i].y < _TVertexArray[0].z)
			return true;
	}*/

	return false;
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
	//Cara Top 27 - 32
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, -1.0f, 1));

	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, -1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, 1.0f, 1));
	//*********
	_vertexArray.push_back(VECTOR4D(1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(-1.0f, 1.0f, 1.0f, 1));
	_vertexArray.push_back(VECTOR4D(1.0f, -1.0f, 1.0f, 1));
	
	for (int i = 0; i < (int)_vertexArray.size(); ++i)
		_colors.push_back(VECTOR4D(1,0,0, 1));
		//_colors.push_back(VECTOR4D(0.45f,0.45f,0.45f,1));

	/***************  Crear planos *****************/
	/*VECTOR4D plane;
	VECTOR4D R, S;
	VECTOR4D RXS;
	R = _scale * _vertexArray[1] - _scale *_vertexArray[0];
	S = _scale *_vertexArray[2] - _scale *_vertexArray[0];

	for (int i = 0; i < 12 * 3; i += 3)
	{
		R = _scale *_vertexArray[i + 1] - _scale *_vertexArray[i];
		S = _scale *_vertexArray[i + 2] - _scale *_vertexArray[i];
		RXS = Cross3(R, S);
		plane = VECTOR4D(RXS.x, RXS.y, RXS.z, -Dot(RXS, _scale *_vertexArray[i]));
		_planes.push_back(plane);

		TRIANGLE triangle;
		triangle.v0 = _scale *_vertexArray[i];
		triangle.v1 = _scale *_vertexArray[i + 1];
		triangle.v2 = _scale *_vertexArray[i + 2];
		_triangles.push_back(triangle);
	}*/
	/***********************************************/
}


Wall::~Wall()
{
}
