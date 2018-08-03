#pragma once
#include "Entidad.h"
#include <SFML\Graphics.hpp>
#include "animacion.h"
#include "Collider.h"
#include "Proyectil.h"
#include "LifeBar.h"
#include "campeon.h"

class Orco : public Entidad
{
public:
	Orco(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida, sf::Vector2f position);
	~Orco();

	void procesarGolpearCampeon(Campeon & campeon);
	void procesarImpactos(std::vector<Proyectil>& balas);
	void Update(float deltaTime, Campeon & campeon);

	float getVida() { return vida; }
	bool getisAlive() { return isAlive; }
	void setIsAlive(bool x) { isAlive = x; }

};
