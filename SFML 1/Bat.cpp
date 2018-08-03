#include "Bat.h"

Bat::Bat(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida, sf::Vector2f position) :
	Entidad(textura, imageCount, switchTime, speed, jumpHeight, vel_ataque, vida)
{
	body.setPosition(position);
	body.setSize(sf::Vector2f(32, 32));
	body.setOrigin(body.getSize() / 2.0f);
	body.setScale(2, 2);

}


Bat::~Bat()
{
}

void Bat::procesarGolpearCampeon(Campeon & campeon)
{
	Collider cEnemigo = GetCollider();
	// push = procentaje de no empujable
	//push = 1 NO EMPUJABLE

	sf::Vector2f direction;

	if (campeon.GetCollider().CheckCollision(cEnemigo, direction, 1.0f))
	{
		campeon.getHurt(10.0f);
	}
}

void Bat::procesarImpactos(std::vector<Proyectil>& balas)
{
	Collider cEnemigo = GetCollider();
	// push = procentaje de no empujable
	//push = 1 NO EMPUJABLE


	sf::Vector2f direction;

	for (size_t i = 0; i < balas.size(); i++)
	{
		Proyectil bala = balas[i];
		if (bala.GetCollider().CheckCollision(cEnemigo, direction, 1.0f))
		{

			vida -= bala.getDaño();
			balas.erase(balas.begin() + i);

			if (vida <= 0)
			{
				//setIsAlive(false);
			}

		}
	}
}

void Bat::Update(float deltaTime, Campeon & campeon)
{
	bool morir = false;
	txt_lifeBar.loadFromFile("lifeBar.png");
	lifeBar = new LifeBar(&txt_lifeBar, sf::Vector2u(1, 10), 0.01f, vida);

	if (body.getPosition().y < 600)
	{
		velocity.y = 0;
	}
	if (sqrt(pow((campeon.GetPosition().x - body.getPosition().x), 2)) < 300)
	{
		if (campeon.GetPosition().x < body.getPosition().x)
		{
			velocity.x = -speed;
		}
		else
		{
			velocity.x = +speed;
		}

	}
	if (sqrt(pow((campeon.GetPosition().x - body.getPosition().x), 2)) < 30)
	{
		velocity.x = 0.0f;
		if (campeon.GetPosition().y > body.getPosition().y)
		{
			velocity.y = speed * 1.50f;
		}
		else
		{
			velocity.y = -speed;
			if (body.getPosition().y < 700)
			{
				velocity.y = 0;
			}
		}
	}
	if (campeon.GetPosition().y < body.getPosition().y)
	{
		velocity.y = -speed;
	}

	if (velocity.x == 0.0f)
	{
		row = 5;
	}
	else
	{
		row = 7;
		if (velocity.x > 0.0f)
			faceRight = false;
		else
			faceRight = true;
	}


	if (velocity.y > 0.0f)row = 8;

	if (vida <= 0)
	{
		velocity.x = 0;
		velocity.y = 30;
		morir = true;
		row =9;
		if (animacion.murio == true)
		{
			setIsAlive(false);
		}
	}
	vector<Proyectil>* balas = campeon.getBalas();
	procesarImpactos(*balas);
	procesarGolpearCampeon(campeon);
	animacion.Update(row, deltaTime, faceRight, false, morir);
	body.setTextureRect(animacion.uvRect);
	body.move(velocity * deltaTime);
	lifeBar->Update(deltaTime, vida, body.getPosition(), body.getSize().y);
	//
}

