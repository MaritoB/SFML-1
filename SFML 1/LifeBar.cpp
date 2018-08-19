#include "LifeBar.h"

#include <iostream>




LifeBar::LifeBar(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float vida):
	animacion(textura, imageCount, switchTime)
{
	body.setSize(sf::Vector2f(32, 4));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(960.0f, 900.0f);
	body.setTexture(textura);
	body.setScale(2, 2);
}

LifeBar::~LifeBar()
{
}


void LifeBar::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
void LifeBar::Update(float deltaTime, float vida, sf::Vector2f posicion, float size)
{
	if (vida >= 10) row = 9;
	if (vida >= 20) row = 8;
	if (vida >= 30) row = 7;
	if (vida >= 40) row = 6;
	if (vida >= 50) row = 5;
	if (vida >= 60) row = 4;
	if (vida >= 70) row = 3;
	if (vida >= 80) row = 2;
	if (vida >= 90) row = 1;
	if (vida >= 100) row = 0;
	
	body.setPosition(posicion.x,posicion.y - size*1.20f );
	animacion.Update(row, deltaTime, true, false, false);
	body.setTextureRect(animacion.uvRect);
}
