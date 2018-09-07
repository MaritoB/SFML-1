
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

	body.setSize(sf::Vector2f(64, 64));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(20,660);
	//body.setPosition(500.0f, 900.0f);
	body.setTexture(textura);
	//body.setScale(2, 2);

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
// , TileMap& map)




void Campeon::inputHandler(sf::RenderWindow & window)
{
	setAttacking(false);
	setDying(false);
	sf::Vector2i posicionMouse;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		velocity.x = 0.0f;
		row = 3;
		setAttacking(true);
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
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 918.0f * jumpHeight);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (clock_dash.getElapsedTime().asSeconds() > cld_dash)
		{
			//velocity.x = 10;
			clock_dash.restart();
		}
	}
	//limitacion de la velocidad
	if (velocity.x <-4)velocity.x = -4;
	if (velocity.x > 4)velocity.x = 4;
	//duracion del dash
	if (clock_dash.getElapsedTime().asSeconds() < 0.15f){
		velocity.x *= 2.5f;
	}
		
		
}
void Campeon::Update(float deltaTime, sf::RenderWindow & window)
{
	
	//velocity.y += 981.0f * deltaTime;
	
	
	if (!getAttacking())
	{

		if (abs(velocity.x) < 1.0f)
		{
			row = 0;
		}
		else
		{
			row = 2;
			if (velocity.x > 0.0f)
				faceRight = true;
			else
				faceRight = false;
		}
	}
	if (velocity.y > 0)row = 4;
	if (velocity.y < 0)row = 5;
	
	if (abs(velocity.x)> 3.3f) row =1;

	if (vida <= 0)
	{
		setDying(true);
		row = 4;
		if (animacion.murio == true)
		{
			setIsAlive(false);
		}
	}
	if (clock_recuperacion.getElapsedTime().asSeconds() < recuperacion )
	{
		body.setFillColor(sf::Color::Red);
	}
	else
	{
		body.setFillColor(sf::Color::White);
	}
	animacion.Update(row, deltaTime, faceRight, getAttacking(), getDying());
	body.setTextureRect(animacion.uvRect);
	//body.move(velocity * deltaTime );
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

		balas.push_back(Proyectil(&txt_bala,sf::Vector2u(10,1),0.04f, 10.0f, 3.0f, 300.0f,(sf::Vector2f)posicion,body.getPosition()));
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


