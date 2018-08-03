#include "Orco.h"
#include "campeon.h"


Orco::Orco(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida, sf::Vector2f position):
	Entidad( textura, imageCount,switchTime,speed,  jumpHeight,  vel_ataque,  vida)
{
	body.setPosition(position);
	body.setSize(sf::Vector2f(64,64));
	body.setOrigin(body.getSize() / 2.0f);
	body.setScale(1.5, 1.5);
}

void Orco::Update(float deltaTime, Campeon & campeon)
{
	bool atacar = false;
	bool morir = false;
	txt_lifeBar.loadFromFile("lifeBar.png");
	lifeBar = new LifeBar(&txt_lifeBar, sf::Vector2u(1, 10), 0.01f, vida);

	if (!atacar)
	{

		if (sqrt(pow((campeon.GetPosition().x - body.getPosition().x), 2)) < 250)
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
		else
		{
			velocity.x = 0.0f;
			row = 0;

		}

		if ((abs(campeon.GetPosition().x - body.getPosition().x) < 60)&& (abs(campeon.GetPosition().y - body.getPosition().y) < 30))
		{
			if (vida > 0)
			{
				velocity.x = 0;
				row = 3;
				atacar = true;
				if (animacion.ataco == true)
				{
					if (!animacion.murio)
					{
						campeon.getHurt(25.0f);

					}
				}
			}
		}

		velocity.y += 981.0f * deltaTime;


		if (vida <= 0)
		{
			velocity.x = 0;
			morir = true;
			row =4;
			if (animacion.murio == true)
			{
				setIsAlive(false);
			}
		}
		else
		{
			if (!atacar)
			{
				row = 2;
				if (velocity.x == 0) row = 0;
				if (velocity.x > 0.0f)
					faceRight = true;
				else
					faceRight = false;

			}
		}


	}



	vector<Proyectil>* balas = campeon.getBalas();
	procesarImpactos(*balas);
	animacion.Update(row, deltaTime, faceRight, atacar, morir);
	body.setTextureRect(animacion.uvRect);
	body.move(velocity * deltaTime);
	lifeBar->Update(deltaTime, vida, body.getPosition(), body.getSize().y);
	//
}

void Orco::procesarImpactos(std::vector<Proyectil>& balas)
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
void Orco::procesarGolpearCampeon(Campeon & campeon)
{
	Collider cEnemigo = GetCollider();
	// push = procentaje de no empujable
	//push = 1 NO EMPUJABLE

	sf::Vector2f direction;

	if (campeon.GetCollider().CheckCollision(cEnemigo, direction, 1.0f))
	{
		campeon.getHurt(30.0f);
	}

}


Orco::~Orco()
{
}
