#pragma once
#include <vector>
#include "VECTOR4D.h"
class fondo
{
public:
	fondo();
	~fondo();
	std::vector<Triangle> _triangulo;
	void Inicializar();
	void Draw();
	void SetPosition(VECTOR4D posicion);
	void SetScale(VECTOR4D scale);
	void SetColor(VECTOR4D color);

};

