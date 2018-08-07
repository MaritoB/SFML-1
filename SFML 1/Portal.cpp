#include "Portal.h"


Portal::Portal(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, sf::Vector2f position):
	animacion(textura, imageCount, switchTime)
{
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(90, 110));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(textura);
}

Portal::~Portal()
{
}

void Portal::Update(float deltaTime)
{
	animacion.Update(row, deltaTime, faceRight, false, false);
	body.setTextureRect(animacion.uvRect);
}

void Portal::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
