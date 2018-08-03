
#include "aliado.h"
#include <iostream>


aliado::aliado(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida) :
	animacion(textura, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->vel_ataque = vel_ataque;
	this->recuperacion = 0.50f;
	this->vida = vida;
	row = 0;
	faceRight = true;
	cld_dash = 1.0f;
	//txt_bala.loadFromFile("daga.png");

	body.setSize(sf::Vector2f(32, 32));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(420.0f, 986.0f);
	body.setTexture(textura);
	body.setScale(2.2f, 2.2f);

	//txt_lifeBar.loadFromFile("lifeBar.png");

	//lifeBar = new LifeBar(&txt_lifeBar, sf::Vector2u(1, 10), 0.01f, 100);

}

aliado::~aliado()
{
}

void aliado::Update(float deltaTime)
{
	row = 0;

	animacion.Update(row, deltaTime, faceRight,false, false);
	body.setTextureRect(animacion.uvRect);

}

void aliado::Draw(sf::RenderWindow & window)
{
	window.draw(body);
	
}

void aliado::onCollision(sf::Vector2f direction)
{
	

}

void aliado::disparar(sf::Vector2i posicion)
{

}


void aliado::getHurt(float daño)
{
	if (clock_recuperacion.getElapsedTime().asSeconds() > recuperacion)
	{
		clock_recuperacion.restart();
		vida -= daño;

	}
}

