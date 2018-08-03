#pragma once
#include<SFML/Graphics.hpp>
#include "animacion.h"
#include "Collider.h"
class Proyectil
{
public:
	Proyectil(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, float daño, float duracion, float velocidad, sf::Vector2f direccion, sf::Vector2f inicio);
	~Proyectil();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	bool eliminar();

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	float getDaño() { return daño; }
	void setIsAlive(bool x) { isAlive = x; }
	bool getIsAlive() { return isAlive; }


private:
	sf::Clock clock_duracion;
	sf::RectangleShape body;
	sf::Vector2f direccion;
	sf::Vector2f inicio;
	Animacion animacion;
	unsigned int row;
	bool faceRight;
	float daño;
	float duracion;
	float velocidad;
	bool isAlive;

};

