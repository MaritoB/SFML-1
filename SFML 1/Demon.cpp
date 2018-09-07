#include "Demon.h"

#include "campeon.h"


Demon::Demon(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida, sf::Vector2f position) :
	Entidad(textura, imageCount, switchTime, speed, jumpHeight, vel_ataque, vida)
{
	body.setPosition(position);
	body.setSize(sf::Vector2f(100, 100));
	body.setOrigin(body.getSize() / 2.0f);
	
	
	txt_bala.loadFromFile("bola1.png");
}

void Demon::Update(float deltaTime, Campeon & campeon, std::string sLevel, float nTileWidth, float nTileHeight, float nLevelWidth, float nLevelHeight){
	 bool atacar = false;
	bool morir = false;
	txt_lifeBar.loadFromFile("lifeBar.png");
	lifeBar = new LifeBar(&txt_lifeBar, sf::Vector2u(1, 10), 0.01f, vida);
	velocity.y = 20;
	if (!atacar)
	{

		if (sqrt(pow((campeon.GetPosition().x - body.getPosition().x), 2)) < 400)
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

		if ((sqrt(pow((campeon.GetPosition().x - body.getPosition().x), 2)) < 200) && (sqrt(pow((campeon.GetPosition().y - body.getPosition().y), 2)) < 300))
		{
			if (vida > 0)
			{
				velocity.x = 0.0f;
				row = 2;
				atacar = true;
				if (animacion.ataco == true)
				{
					if (!animacion.murio)
					{
						disparar(campeon.GetPosition());

					}
				}
			}
		}


		CheckCollisionTileMap(sLevel, deltaTime, nTileWidth, nTileHeight, nLevelWidth, nLevelHeight);

		if (vida <= 0)
		{
			velocity.x = 0;
			morir = true;
			row = 3;
			if (animacion.murio == true)
			{
				setIsAlive(false);
			}
		}
		else
		{
			if (!atacar)
			{
				row = 1;
				if (velocity.x == 0) row = 0;
				if (campeon.GetPosition().x > body.getPosition().x)
					faceRight = true;
				else
					 faceRight = false;

			}
		}


	}


	for (Proyectil& bala : balas)
	{
		if (bala.getIsAlive())
		{
			bala.Update(deltaTime);
		}

	}

	std::vector<Proyectil>* xbalas = campeon.getBalas();
	procesarImpactos(*xbalas);
	procesarGolpearCampeon(campeon);
	animacion.Update(row, deltaTime, faceRight, atacar, morir);
	body.setTextureRect(animacion.uvRect);
	body.move(velocity * deltaTime);
	lifeBar->Update(deltaTime, vida, body.getPosition(), body.getSize().y);
	
}

void Demon::disparar(sf::Vector2f posicion)
{
	
	if (clock_ataque.getElapsedTime().asSeconds() > vel_ataque)
	{

		balas.push_back(Proyectil(&txt_bala, sf::Vector2u(10, 1), 0.05f, 2.0f, 3.0f, 300.0f, (sf::Vector2f)posicion, body.getPosition()));
		clock_ataque.restart();
	}

	

}

void Demon::procesarImpactos(std::vector<Proyectil>& balas)
{
	Collider cEnemigo = GetCollider();
	// push = procentaje de no empujable
	//push = 1 NO EMPUJABLE


	sf::Vector2f direction;

	for (size_t i = 0; i < balas.size(); i++)
	{
		Proyectil bala = balas[i];
		if (bala.GetCollider().CheckCollision(cEnemigo, direction, 0.0f))
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
void Demon::procesarGolpearCampeon(Campeon & campeon)
{
	Collider cCampeon = campeon.GetCollider();
	// push = procentaje de no empujable
	//push = 1 NO EMPUJABLE


	sf::Vector2f direction;

	for (size_t i = 0; i < balas.size(); i++)
	{
		Proyectil bala = balas[i];
		if (bala.GetCollider().CheckCollision(cCampeon, direction, 0.0f))
		{

			campeon.setVida(campeon.getVida() - bala.getDaño());
			balas.erase(balas.begin() + i);

			if (vida <= 0)
			{
				//setIsAlive(false);
			}

		}
	}

}
void Demon::Draw(sf::RenderWindow & window)
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


Demon::~Demon()
{
}
