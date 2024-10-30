#pragma once

#include "CCarro.hpp"
#include <vector>

using namespace std;

class CControladora {
private:
	vector<CCarro*> carritos;
public:
	CControladora() {}
	~CControladora() {
		for (int i = 0; i < carritos.size(); ++i) {
			delete carritos[i];
		}
		carritos.clear();
	};
	void StartButton1(Graphics^ g) {
		Random r;
		CCarro* carroNegro = new CCarro(g, 1, (g->VisibleClipBounds.Height / 4) * 1, 0, 0, 0);
		carritos.push_back(carroNegro);
		_sleep(1);
		CCarro* carroAzul = new CCarro(g, 1, (g->VisibleClipBounds.Height / 4) * 2, 0, 0, 255);
		carritos.push_back(carroAzul);
		_sleep(1);
		CCarro* carroAleatorio = new CCarro(g, 1, (g->VisibleClipBounds.Height / 4) * 3, r.Next(0, 255), r.Next(0, 255), r.Next(0, 255));
		carritos.push_back(carroAleatorio);
	}
	void BeginButton1(Graphics^ g) {
		for (int i = 0; i < carritos.size(); ++i) {
			carritos.at(i)->moverEnX(g->VisibleClipBounds.Width);
			carritos.at(i)->dibujar(g);
		}
	}
	bool ColissionButton1(int meta) {
		for (int i = 0; i < carritos.size(); ++i) {
			if (carritos.at(i)->getPosX() + carritos.at(i)->getWidth() >= meta) {
				return true;
			}
		}
			return false;

	}

	void startButton2(Graphics^ g) {
		Random r;
		int WidthCar = 53;
		int HeightCar = 31;
		CCarro* carroNegro = new CCarro(g, 1);
		carritos.push_back(carroNegro);
		_sleep(0);

		CCarro* carroAzul = new CCarro(g, 2);
		carritos.push_back(carroAzul);
		_sleep(0);
		
		CCarro* carroAleatorio = new CCarro(g, 3);
		carritos.push_back(carroAleatorio);
	}
	void AgregarCarroAleatorio(Graphics^ g) {
		Random r;
		switch (r.Next(0, 3))
		{
		case 1: // Carro negro
			CCarro * carroNegro;
			carroNegro = new CCarro(g, 1);
			carritos.push_back(carroNegro);
			break;
		case 2:
			CCarro * carroAzul;
			carroAzul = new CCarro(g, 2);
			carritos.push_back(carroAzul);
			break;
		case 3:
			CCarro * carroAleatorio;
			carroAleatorio = new CCarro(g, 3);
			carritos.push_back(carroAleatorio);
			break;
		default:
			break;
		}
	}
	void eliminarCarro(int index) {
		carritos.erase(carritos.begin() + index);
	}
	void BeginButton2(Graphics^ g) {
		for (int i = 0; i < carritos.size(); ++i) {
			carritos.at(i)->mover(g);
			carritos.at(i)->dibujar(g);
		}
	}
	//cada tick
	void ColissionButton2(Graphics^ g) {
		int indiceEliminar1 = -1;
		int indiceEliminar2 = -1;

		for (int i = 0; i < carritos.size(); ++i) {
			carritos.at(i)->setColisionado(false);
		}

		for (int i = 0; i < carritos.size(); ++i) {
			for (int j = 0; j < carritos.size(); ++j) {
				if (i == j) {
					continue;
				}
				if (carritos.at(i)->getRectangle()->IntersectsWith(*carritos.at(j)->getRectangle())) {
					if (carritos.at(i)->isColisionado() || carritos.at(j)->isColisionado()) {
						continue;
					}
					carritos.at(i)->setColisionado(true);
					carritos.at(j)->setColisionado(true);
					if ((carritos.at(i)->getTipo() == 3 && carritos.at(j)->getTipo() == 2) ||
						(carritos.at(i)->getTipo() == 2 && carritos.at(j)->getTipo() == 3)) {
						indiceEliminar1 = i;
						indiceEliminar2 = j;
						
					}
					if ((carritos.at(i)->getTipo() == 3 && carritos.at(j)->getTipo() == 1) ||
						(carritos.at(i)->getTipo() == 1 && carritos.at(j)->getTipo() == 3)) {
						carritos.at(i)->CambiarDir();
						carritos.at(j)->CambiarDir();
						
					}
					if ((carritos.at(i)->getTipo() == 2 && carritos.at(j)->getTipo() == 1) ||
						(carritos.at(i)->getTipo() == 1 && carritos.at(j)->getTipo() == 2)) {
						CCarro* nuevoCarrito = new CCarro(g, 1);
						carritos.push_back(nuevoCarrito);
					}
					break;
				}
			}
		}

		if (indiceEliminar1 != -1 && indiceEliminar2 != -1) {
			if (indiceEliminar1 > indiceEliminar2) {
				eliminarCarro(indiceEliminar1);
				eliminarCarro(indiceEliminar2);
			}
			else {
				eliminarCarro(indiceEliminar2);
				eliminarCarro(indiceEliminar1);
			}
		}

	}
	int getTam() {
		return carritos.size();
	}
};