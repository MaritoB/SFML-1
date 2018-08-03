#pragma once

#include<SFML\Graphics.hpp> 
#include "animacion.h"
#include "Collider.h"
#include "campeon.h"
#include "LifeBar.h"

using namespace std;

class enemigo 
{
	public:
		enemigo(sf::Texture * textura, sf::Vector2u imageCount, float switchTime, float speed,float attack_speed, float jumpHeight, float vida, sf::Vector2f position);



		void Update(float deltaTime, Campeon & campeon);
		void Draw(sf::RenderWindow & window);
		void onCollision(sf::Vector2f direction);

		void procesarGolpearCampeon(Campeon & campeon);
		void procesarImpactos(std::vector<Proyectil>& balas);

		sf::Vector2f GetPosition() { return body.getPosition(); }
		Collider GetCollider() { return Collider(body); }

		float getVida() { return vida; }
		bool getisAlive() { return isAlive; }
		void setIsAlive(bool x) { isAlive = x; }
	

	private:

		sf::RectangleShape body;
		Animacion animacion;

		sf::Texture txt_lifeBar;
		LifeBar * lifeBar;
		sf::Clock clock_ataque;
		unsigned int row;
		float speed;
		float attack_speed;
		bool faceRight;
		float vida;
		sf::Vector2f velocity;
		bool canJump;
		bool isAlive;
		float jumpHeight;

};