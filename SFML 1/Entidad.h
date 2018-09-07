#pragma once
#include <SFML\Graphics.hpp>
#include "animacion.h"
#include "Collider.h"
#include "Proyectil.h"
#include "LifeBar.h"
class Entidad
{
public:

	Entidad(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float vel_ataque, float vida );
	~Entidad();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow & window);
	void onCollision(sf::Vector2f direction);

	void CheckCollisionTileMap(std::string sLevel, float fElapsedTime, float nTileWidth, float nTileHeight, float nLevelWidth, float nLevelHeight);


	void disparar(sf::Vector2i posicion);
	void getHurt(float daño);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	void setPosition(sf::Vector2f position) { body.setPosition(position); }
	Collider GetCollider() { return Collider(body); }
	sf::Clock GetClockRecuperacion() { return clock_recuperacion; }
	float GetRecuperacion() { return recuperacion; }
	sf::Vector2f GetVelocity() { return velocity; }
	void setVelocity(float velX, float velY) { velocity.x = velX; velocity.y = velY; }
	std::vector<Proyectil>* getBalas() { return  &balas; }

	bool getAttacking() { return attacking; }
	void setAttacking(bool x) { attacking = x; }

	bool getDying() { return dying; }
	void setDying(bool x) { dying = x; }

protected:
	sf::Texture txt_lifeBar;
	LifeBar * lifeBar;

	sf::Texture txt_bala;
	std::vector<Proyectil>  balas;
	sf::Clock clock_ataque;
	sf::Clock clock_recuperacion;

	sf::RectangleShape body;
	Animacion animacion;
	unsigned int row;
	bool faceRight;
	float speed;
	float vel_ataque;
	float recuperacion;
	float vida;
	bool isAlive;

	bool attacking;
	bool dying;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

