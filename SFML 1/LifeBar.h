#pragma once

#include <SFML\Graphics.hpp>
#include "animacion.h"

class LifeBar
{
public:
	LifeBar(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, float vida);
	~LifeBar();
	void Draw(sf::RenderWindow & window);
	void Update(float deltaTime, float vida, sf::Vector2f posicion, float size);

private:
	sf::RectangleShape body;
	Animacion animacion;
	unsigned int row;

};

