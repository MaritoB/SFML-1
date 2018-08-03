
#include "campeon.h"
#include <iostream>


Campeon::Campeon(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida):
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
	txt_bala.loadFromFile("daga.png");

	body.setSize(sf::Vector2f(32, 32));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(500.0f, 900.0f);
	body.setTexture(textura);
	body.setScale(2, 2);

	txt_lifeBar.loadFromFile("lifeBar.png");

	lifeBar = new LifeBar(&txt_lifeBar,sf::Vector2u(1,10), 0.01f, 100);
	
}

Campeon::~Campeon()
{
}
sf::Vector2i Campeon::procesarMouse(sf::RenderWindow & window) {

	sf::Vector2i posicion_mouse = sf::Mouse::getPosition(window);
	posicion_mouse = (sf::Vector2i)window.mapPixelToCoords(posicion_mouse);
	return posicion_mouse;
}

void Campeon::Update(float deltaTime, sf::RenderWindow & window)
{

	bool atacar = false;
	bool morir = false;
	sf::Vector2i posicionMouse;
	
	if (sqrt(pow(velocity.x, 2)) < 10.0f) velocity.x = 0;
	else velocity.x *= 0.90f;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (clock_dash.getElapsedTime().asSeconds() > cld_dash)
		{
			velocity.x *= 6;
			clock_dash.restart();
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		velocity.x =0.0f;
		row = 3;
		atacar = true;
		if (animacion.ataco == true)
		{
			if (!animacion.murio)
			{
				posicionMouse = procesarMouse(window);
				disparar(posicionMouse);
				if (posicionMouse.x > body.getPosition().x) faceRight = true;
				else  faceRight = false;

			}
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed ;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 918.0f * jumpHeight);
	}
	velocity.y += 981.0f * deltaTime;

	if (!atacar)
	{

		if (abs(velocity.x) < 20.0f)
		{
			row = 0;
		}
		else
		{
			row = 2;
			if (sqrt(pow(velocity.x,2 ))> 270) row = 5;
			if (velocity.x > 0.0f)
				faceRight = true;
			else
				faceRight = false;
		}
	}
	if (vida <= 0)
	{
		morir = true;
		row = 4;
		if (animacion.murio == true)
		{
			setIsAlive(false);
		}
	}


	animacion.Update(row, deltaTime, faceRight, atacar, morir);
	body.setTextureRect(animacion.uvRect);
	body.move(velocity * deltaTime );
	lifeBar->Update(deltaTime, vida, body.getPosition(), body.getSize().y);

	for (Proyectil& bala : balas)
	{
		if (bala.getIsAlive())
		{
			bala.Update(deltaTime);
		}

	}
}

void Campeon::Draw(sf::RenderWindow & window)
{
	window.draw(body);
	lifeBar->Draw(window);
	for (size_t i = 0; i < balas.size(); i++)
	{
		Proyectil bala = balas[i];
		if (!bala.getIsAlive()||bala.eliminar())
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

void Campeon::onCollision(sf::Vector2f direction)
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
		velocity.y= 0.0f;
	}
	
}

void Campeon::disparar(sf::Vector2i posicion)
{
	if (clock_ataque.getElapsedTime().asSeconds() > vel_ataque)
	{

		balas.push_back(Proyectil(&txt_bala,sf::Vector2u(10,1),0.05f, 10.0f, 3.0f, 300.0f,(sf::Vector2f)posicion,body.getPosition()));
		clock_ataque.restart();
	}

}


void Campeon::getHurt(float daño)
{	
	if (clock_recuperacion.getElapsedTime().asSeconds() > recuperacion)
	{
		clock_recuperacion.restart();
		vida -= daño;

	}
}


