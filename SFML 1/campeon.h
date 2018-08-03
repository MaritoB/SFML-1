#pragma once
#include <SFML\Graphics.hpp>
#include "animacion.h"
#include "Collider.h"
#include "Proyectil.h"
#include "LifeBar.h"


using namespace std;

class Campeon 
{	

public:
	Campeon(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida );
	~Campeon();

	void Update(float deltaTime, sf::RenderWindow & window);
	void Draw(sf::RenderWindow & window);
	void onCollision(sf::Vector2f direction);

	void disparar(sf::Vector2i posicion);
	void dash();
	void getHurt(float daño);
	sf::Vector2i procesarMouse(sf::RenderWindow & window);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	void setIsAlive(bool x) { isAlive = x; }
	bool getIsAlive() { return isAlive; }
	Collider GetCollider() { return Collider(body); }
	sf::Clock GetClockRecuperacion() { return clock_recuperacion; }
	float GetRecuperacion() { return recuperacion; }
	sf::Vector2f GetVelocity() { return velocity; }
	std::vector<Proyectil>* getBalas() { return  &balas; }
	float getVida() { return vida; }
	void setVida(float x) { vida= x; }


private:
	sf::Texture txt_lifeBar;
	LifeBar * lifeBar;

	sf::Texture txt_bala;
	std::vector<Proyectil>  balas;
	sf::Clock clock_ataque;
	sf::Clock clock_recuperacion;
	sf::Clock clock_dash;

	sf::RectangleShape body;
	Animacion animacion;
	unsigned int row;
	bool faceRight;
	float speed;
	float vel_ataque;
	float recuperacion;
	float cld_dash;
	float vida;

	sf::Vector2f velocity;
	bool canJump;
	bool isAlive;
	float jumpHeight;
};