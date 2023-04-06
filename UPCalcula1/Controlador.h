#pragma once
#include "Circulo.h"
#include <vector>
using namespace std;
class VectorCirculo
{

private:
	vector<Circulo*>* arrC;
	int limX, limy;
public:
	VectorCirculo(int limX, int limy);
	~VectorCirculo();
	void agregarCirculo(int x, int y);
	void animar(Graphics^ gr);


};
VectorCirculo::VectorCirculo(int limX, int limy)
{
	arrC = new vector<Circulo*>();
}

VectorCirculo::~VectorCirculo()
{
	delete[]arrC;
}
void VectorCirculo::agregarCirculo(int x, int y) {
	Random r;
	int diametro = r.Next(30, 60);
	System::Drawing::Rectangle area = System::Drawing::Rectangle(x, y, diametro, diametro);
	this->arrC->push_back(new Circulo(area));
}
void VectorCirculo::animar(Graphics^ gr) {
	for (int i = 0; i < arrC->size(); i++)
	{
		arrC->at(i)->animar(gr, limX, limy);
	}
}


