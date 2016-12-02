#include "pch.h"
#include "Cara.h"
#include "MATRIX4D.h"


Cara::Cara(VECTOR4D vertex[])
{
	Triangle a;
	Triangle b;

	a.A = vertex[1];
	a.B = vertex[0];
	a.C = vertex[3];

	b.A = vertex[3];
	b.B = vertex[2];
	b.C = vertex[1];

	/*test1[0] = VECTOR4D(-1.f, 1.0f, 0.f, 1);
	test1[1] = VECTOR4D(-1.f, -1.0f, 0.f, 1);
	test1[2] = VECTOR4D(1.f, -1.0f, 0.f, 1);

	test1[3] = VECTOR4D(1.f, -1.0f, 0.f, 1);
	test1[4] = VECTOR4D(1.f, 1.0f, 0.f, 1);
	test1[5] = VECTOR4D(-1.f, 1.0f, 0.f, 1);*/

	/*a.A = vertex[0];
	a.B = vertex[1];
	a.C = vertex[2];
	b.A = vertex[0];
	b.B = vertex[2];
	b.C = vertex[3];*/
	_tr[0] = a;
	_tr[1] = b;
	MATRIX4D scale = Identity();
	/*scale = Translation(.3f, .3f, 0);
	scale *= Scaling(0.1f, .1f, 1.f);
	scale *= RotationX(3.1592 /2);*/

	for (int i = 0; i < 2; i++) {
		_tr[i].A = scale * _tr[i].A;
		_tr[i].B = scale * _tr[i].B;
		_tr[i].C = scale * _tr[i].C;

	}

	_normal = Normalize(Cross3(_tr[0].B - _tr[0].A, _tr[0].C - _tr[0].A));
	_plano = _normal;
	_plano.w = -Dot(_normal, _tr[0].A);
}


void Cara::Draw()
{
	//static float theta = 0;
	//MATRIX4D scale = Identity();
	//MATRIX4D rotation = RotationX(-3.141592f /5);
	//rotation *= RotationY(theta);
	//theta +=.001f;
	//local *= const_cast<MATRIX4D&>(W);
	//scale = Scaling(0.1f, .1f, .1f);
	//scale *= rotation;
	/*glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, &.m_Colors[0]);*/
	std::vector<VECTOR4D> copy;

	for (int i = 0; i < 2; i++) {
		copy.push_back(_tr[i].A);
		//copy.back() = scale * copy.back();
		copy.push_back(_tr[i].B);
		//copy.back() = scale * copy.back();
		copy.push_back(_tr[i].C);
		//copy.back() = scale * copy.back();
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, &copy[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	
}

std::vector<VECTOR4D> Cara::GetVertex()
{
	std::vector<VECTOR4D> xd(4);
	xd[0] = _tr[0].A;
	xd[1] = _tr[0].B;
	xd[2] = _tr[0].C;
	xd[3] = _tr[1].C;
	return xd;
}

Cara::~Cara()
{
}
