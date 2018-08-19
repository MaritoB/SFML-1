#include "animacion.h"

Animacion::Animacion(sf::Texture* textura, sf::Vector2u cantImagenes, float switchTime) {

	this->imageCount = cantImagenes;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = textura->getSize().x / float(cantImagenes.x);
	uvRect.height = textura->getSize().y / float(cantImagenes.y);


}

Animacion::~Animacion()
{
}

void Animacion::Update(int row, float deltaTime,bool faceRigth, bool attack, bool dead)
{
	if (currentImage.y != row) currentImage.x = 0;
	currentImage.y = row;
	totalTime += deltaTime;


	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.top = currentImage.y * uvRect.height;

	if(faceRigth)
	{
		uvRect.left = (currentImage.x * uvRect.width);
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

	if (attack && currentImage.x > 6)
		ataco = true;
	else
		ataco = false;
	if (dead && currentImage.x > 8)
		murio = true;
	else
		murio = false;
				
}

