#pragma once
#include<SFML\Graphics.hpp>
#include <iostream>
#include "enemigo.h"
#include "stage1.h"
#include "campeon.h"

using namespace sf;
using namespace std;
class juego
{
public:

	juego(int resX, int resY, std::string titulo);
	void dibujar();
	void gameLoop();
	void acciones();/*
	void procesarColisiones();
	int procesarMouse();
	void procesarEnemigos();
	void spawn_enemigos();
	void procesarEventos();
	void animacion(int n);
	void animacionMorir();
	void animacionAtacar();
	void animacionSaltar();
	void animacionBola();
	void trayectoBola();
	void efectoGravedad();
	float getImpulso();
	float getGravedad();
	void setImpulso(float x);
	void setGravedad(float x);
	*/




	

private:
	Campeon * campeon;
	float * deltaTime;
	RenderWindow  window;
	View vista;
	Texture * textura_fondo;
	Texture * textura_bola;
	Sprite * sprite_bola;
	Sprite * sprite_fondo;
	Sprite * sprite_campeon;
	Event * evento;
	Vector2i * posicionCampeon;
	Clock * reloj;
	Clock * relojSpawn;
	Clock * relojEnemigo[3];
	Clock * relojBola;
	Time * tiempo;
	float  impulso;
	float  gravedad;
	bool  cayendo;
	bool  isOut;
	Vector2i posicion_mouse;
	Vector2f inicioBola;
	Vector2f destinoBola;
	enemigo *  bat[3];
	stage * stage1;
}; 