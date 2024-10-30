#pragma once

#include <iostream>
#include <array>

using namespace System;
using namespace System::Drawing;

class CCarro {
private:
	float x, y,
		dx, dy,
		width, height,
		vx, vy,
		red, gree, blue;
	int tipo;
	bool colisionado;
public:
	//Para el juego 1 que necesita valores predeterminados de x y y
	CCarro(Graphics^ g, float posx, float posy, float sred, float sgreen, float sblue) {
		Random r;
		this->x = posx;
		this->y = posy;
		this->dx = 1;
		this->dy = 0;
		this->height = 31;
		this->width = 53;
		this->red = sred;
		this->gree = sgreen;
		this->blue = sblue;
		this->vx = r.Next(5, 10);
		this->colisionado = false;

	}
	CCarro(Graphics^ g, int tip) {
		Random r;
		this->vx = r.Next(5, 10);

		int posx = r.Next(100, 1000);

		this->x = posx;

		int posy = r.Next(100, 400);
		this->y = posy;


		this->dx = (r.Next(0, 2) ? 1 : -1);
		this->dy = (r.Next(0, 2) ? 1 : -1);
		this->height = 31;
		this->width = 58;
		this->tipo = tip;
		this->vy = r.Next(5, 10);
		switch (tipo)
		{
		case 1: //carro neggro
			this->red = 0;
			this->gree = 0;
			this->blue = 0;
			break;
		case 2: //carro azul
			this->red = 0;
			this->gree = 0;
			this->blue = 255;
			break;
		case 3:
			this->red = r.Next(0, 255);
			this->gree = r.Next(0, 255);
			this->blue = r.Next(0, 255);
			break;
		default:
			break;
		}
		this->colisionado = false;

	}
	~CCarro() {};
	void moverEnX(int meta) {
		if(x + width < meta)
		x += vx;
	}
	void mover(Graphics^ g) {
		int anchoPantalla = g->VisibleClipBounds.Width;
		int altoPantalla = g->VisibleClipBounds.Height;
		if (x + width > anchoPantalla || x < 0)
			dx *= -1;
		if (y > altoPantalla - height || y < 0)
			dy *= -1;
		x += (dx * vx);
		y += (dy * vy);
	}
	void dibujar(Graphics^ g) {
		SolidBrush^ sColor = gcnew SolidBrush(Color::FromArgb(red, gree, blue));
		SolidBrush^ sWhite = gcnew SolidBrush(Color::White);
		//5 cuadrados de en medio a la izquierda
		for (int i = 0; i < 5; ++i)
			g->FillRectangle(sColor, x + 6 * i, y + 12.5, 5.0, 5.0);
		//rectangulo de en medio
		g->FillRectangle(sColor, x + 30, y + 12.5, 5.0, 11.0);
		//rectangulos de abajo
		g->FillRectangle(sColor, x, y + 18.5, 23.0, 5.0);
		g->FillRectangle(sColor, x, y + 24.5, 35.0, 5.0);
		g->FillRectangle(sColor, x + 24, y + 18.5, 5.0, 5.0);
		g->FillRectangle(sColor, x + 30, y, 5.0, 11.5);
		g->FillRectangle(sColor, x + 36, y + 12.5, 10.0, 5.0);
		for (int i = 0; i < 2; ++i) {
			g->FillRectangle(sColor, x + 36, y + 18.5 + 6 * i, 20.0, 5.0);
			g->FillRectangle(sColor, x + 47 + 6 * i, y + 12.5, 5.0, 5.0);
			g->FillEllipse(sWhite, x + 5 + 36 * i, y + 21, 12.0, 12.0);
			g->FillEllipse(sColor, x + 6 + 36 * i, y + 22, 10.0, 10.0);
		}
		cli::array <Point>^ pointsP1 = {
		Point(x+5, y+11.5),
		Point(x+7.5, y+ 11.5),
		Point(x + 10, y + 7.5),
		Point(x + 7, y + 7.5),
		};

		cli::array <Point>^ pointsP2 = {
		Point(x + 5 + 3.5, y + 11.5 - 5),
		Point(x + 7.5 + 3.5, y + 11.5 - 5),
		Point(x + 10 + 3.5, y + 7.5 - 5),
		Point(x + 7 + 3.5, y + 7.5 - 5),
		};
		g->FillPolygon(sColor, pointsP1);
		g->FillPolygon(sColor, pointsP2);
		g->FillRectangle(sColor, x + 18.0, y, 11.0, 5.0);

		// draw hitbox

		Pen^ p = gcnew Pen(Color::Green, 1);
		g->DrawRectangle(p, x, y, width, height);
	}
	float getPosX() {
		return x;
	}
	Rectangle* getRectangle() {
		return new Rectangle(x, y, width, height);
	}
	float getWidth() {
		return width;
	}

	int getTipo() {
		return tipo;
	}
	bool isColisionado() {
		return colisionado;
	}

	void setColisionado(bool colision) {
		this->colisionado = colision;
	}

	void CambiarDir() {
		this->dx *= -1;
		this->dy *= -1;
	}

};