#include "Proyectil.h"
#include <iostream>
using namespace std;
Proyectil::Proyectil(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float daño, float duracion, float velocidad, sf::Vector2f direccion, sf::Vector2f inicio):
	animacion(textura, imageCount, switchTime)
{
	this->daño = daño;
	this->duracion = duracion;
	this->velocidad = velocidad;
	this->direccion = direccion;
	this->inicio = inicio;
	this->isAlive = true;

	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(16, 8));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(inicio);
	body.setTexture(textura);
	body.setScale(2, 2);
}

Proyectil::~Proyectil()
{
}

void Proyectil::Update(float deltaTime)
{
	if (clock_duracion.getElapsedTime().asSeconds() < duracion)
	{
		sf::Vector2f aimDir;
		sf::Vector2f aimDirNorm;


		float deltaX = direccion.x - inicio.x;
		float deltaY = direccion.y - inicio.y;
		float angulo = atan2f(deltaY, deltaX);

		sf::Vector2f vel;

		vel.x = cos(angulo)*velocidad;
		vel.y = sin(angulo)*velocidad;

		if (vel.x > 0)faceRight = true;
		else faceRight = false;
		row = 0;
		animacion.Update(row, deltaTime, faceRight, false, false);
		body.setTextureRect(animacion.uvRect);
		body.move(vel * deltaTime);


	}


}
void Proyectil::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

bool Proyectil::eliminar()
{
	if (clock_duracion.getElapsedTime().asSeconds() < duracion)
	{
		return false;
	}
	else return true;

}
