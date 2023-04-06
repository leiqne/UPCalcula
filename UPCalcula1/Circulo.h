#pragma once
#include "Ctime"
#include <stdlib.h>
using namespace System;
using namespace System::Drawing;
class Circulo
{
public:
	Circulo(System::Drawing::Rectangle areaDibujo);
	~Circulo();
	void animar(Graphics^ gr, int limX, int limY);
	System::Drawing::Rectangle getArea();
	void mover(Graphics^ gr);
	void dibujar(Graphics^ gr);

private:
	int dx, dy, rojo, verde, azul;
	System::Drawing::Rectangle areaDibujo;//x,y,ancho, alto
};

Circulo::Circulo(System::Drawing::Rectangle areaDibujo)
{
	this->areaDibujo = areaDibujo;
	this->dx = 4;
	this->dy = 4;
	rojo = rand() % +256;
	for (int i = 0; i < 1; i++)
	{
		verde = rand() % +256;
	}
	for (int i = 0; i < 1; i++)
	{
		azul = rand() % +256;
	}
}

Circulo::~Circulo()
{
}
void Circulo::animar(Graphics^ gr, int limX, int limY) {
	this->dibujar(gr);
	this->mover(gr);
}
System::Drawing::Rectangle Circulo::getArea() {
	return this->areaDibujo;
}
void Circulo::mover(Graphics^ gr) {
	int x = this->areaDibujo.X;
	int y = this->areaDibujo.Y;
	int ancho = this->areaDibujo.Width;
	int alto = this->areaDibujo.Height;
	//establecemos limites
	if (x + dx<0 || x + dx + ancho>gr->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y + dy<0 || y + dy + alto>gr->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	//movimiento 
	this->areaDibujo.X += dx;
	this->areaDibujo.Y += dy;
}
void Circulo::dibujar(Graphics^ gr) {
	Color color = Color::FromArgb(rojo, verde, azul);
	SolidBrush^ brocha = gcnew SolidBrush(color);
	gr->FillEllipse(brocha, this->areaDibujo);
}



