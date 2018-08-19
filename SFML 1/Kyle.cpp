#include "Kyle.h"
#include "campeon.h"


Kyle::Kyle(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida, sf::Vector2f position) :
	Entidad(textura, imageCount, switchTime, speed, jumpHeight, vel_ataque, vida)
{
	body.setPosition(position);
	body.setSize(sf::Vector2f(64, 64));
	body.setOrigin(body.getSize() / 2.0f);


}

void Kyle::Update(float deltaTime, Campeon & campeon)
{
	bool atacar = false;
	bool morir = false;
	txt_lifeBar.loadFromFile("lifeBar.png");
	lifeBar = new LifeBar(&txt_lifeBar, sf::Vector2u(1, 10), 0.01f, vida);

	if (!atacar)
	{

		if (sqrt(pow((campeon.GetPosition().x - body.getPosition().x), 2)) < 200)
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

		if (sqrt(pow((campeon.GetPosition().x - body.getPosition().x), 2)) < 90)
		{
			velocity.x = 0;
			row = 3;
			atacar = true;
			if (animacion.ataco == true)
			{
				if(campeon.getVida()<100)
					campeon.setVida(campeon.getVida() + 1.0f);
			}
		}

		velocity.y += 981.0f * deltaTime;


		if (vida <= 0)
		{
			velocity.x = 0;
			morir = true;
			row = 4;
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

	animacion.Update(row, deltaTime, faceRight, atacar, morir);
	body.setTextureRect(animacion.uvRect);
	body.move(velocity * deltaTime);
	lifeBar->Update(deltaTime, vida, body.getPosition(), body.getSize().y);
	//
}


Kyle::~Kyle()
{
}
