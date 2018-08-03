#include "Entidad.h"



Entidad::Entidad(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida) :
	animacion(textura, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->vel_ataque = vel_ataque;
	this->recuperacion = 0.50f;
	this->vida = vida;
	row = 0;
	faceRight = true;
	body.setTexture(textura);

	txt_lifeBar.loadFromFile("lifeBar.png");

	lifeBar = new LifeBar(&txt_lifeBar, sf::Vector2u(1, 10), 0.01f, 100);

}

Entidad::~Entidad()
{
}

void Entidad::Update(float deltaTime)
{
}

void Entidad::Draw(sf::RenderWindow & window)
{
	window.draw(body);
	lifeBar->Draw(window);
	for (size_t i = 0; i < balas.size(); i++)
	{
		Proyectil bala = balas[i];
		if (!bala.getIsAlive() || bala.eliminar())
		{
			balas.erase(balas.begin() + i);
		}

	}
	for (Proyectil& bala : balas)
	{
		if (!bala.eliminar())
		{
			if (bala.getIsAlive())
			{
				bala.Draw(window);

			}

		}
	}
}

void Entidad::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//colision en la izq
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{

		//colision en la der
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//colision en la bot
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//top
		velocity.y = 0.0f;
	}

}

void Entidad::disparar(sf::Vector2i posicion)
{
	if (clock_ataque.getElapsedTime().asSeconds() > vel_ataque)
	{

		balas.push_back(Proyectil(&txt_bala, sf::Vector2u(10, 1), 0.05f, 25.0f, 3.0f, 300.0f, (sf::Vector2f)posicion, body.getPosition()));
		clock_ataque.restart();
	}

}


void Entidad::getHurt(float daño)
{
	if (clock_recuperacion.getElapsedTime().asSeconds() > recuperacion)
	{
		clock_recuperacion.restart();
		vida -= daño;

	}
}


