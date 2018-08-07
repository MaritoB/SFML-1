#pragma once
#include<SFML/Graphics.hpp>
#include "Collider.h"
#include "Platform.h"
#include "enemigo.h"
#include "aliado.h"
#include "campeon.h"
#include "Orco.h"
#include "Bat.h"
#include "Kyle.h"
#include "Demon.h"
#include "Portal.h"
#include <vector>

using namespace sf;
using namespace std;

class stage{
public:
	stage(String fondo);
	void procesarColisionesStageX(Campeon & campeon);
	void Draw(sf::RenderWindow & window, float deltaTime, Campeon & campeon);
	Sprite procesarColisionesStage(Sprite campeon);
	Sprite getFondo();
	Sprite getPiso();
	Sprite getCajas(int i);
private:
	std::vector<Platform>  cajas;
	std::vector<Portal>  portals;
	std::vector<Kyle>  kyles;
	std::vector<Demon>  demons;
	std::vector<Platform>  pisos;
	std::vector<enemigo>  enemigos;
	std::vector<Orco>  bosses;
	std::vector<Bat>  bats;
	std::vector<aliado>  aliados;
	Platform * caja;
	Platform * piso;
	Sprite sprite_piso;
	Sprite sprite_casa;
	Sprite sprite_cajas[5];
	Sprite sprite_arboles[4];
	Sprite sprite_background[4];
	Texture textura_portal;
	Texture textura_cajas;
	Texture textura_demon;
	Texture textura_kyle;
	Texture textura_aliados;
	Texture textura_boss;
	Texture textura_bat;
	Texture textura_piso;
	Texture textura_casa;
	Texture textura_fondo;
	Texture textura_fondo2;
};
