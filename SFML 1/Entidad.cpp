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


void Entidad::CheckCollisionTileMap(std::string sLevel, float fElapsedTime, float nTileWidth, float nTileHeight, float nLevelWidth, float nLevelHeight) {

	//setVelocity(GetVelocity().x*0.91f, GetVelocity().y*0.99f);
	float fPlayerVelX = GetVelocity().x*0.1f;
	float fPlayerVelY = GetVelocity().y*0.1f;
	float fPlayerPosX = GetPosition().x / nTileWidth;
	float fPlayerPosY = GetPosition().y / nTileHeight;
	float playerHalfSize = GetCollider().GetHalfSize().x / nTileWidth;
	//fPlayerVelY += 200 * fElapsedTime;

	float fNewPlayerPosX = fPlayerPosX + fPlayerVelX * fElapsedTime;
	float fNewPlayerPosY = fPlayerPosY + fPlayerVelY * fElapsedTime;



	auto GetTile = [&](int x, int y)
	{
		if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
			return sLevel[y * nLevelWidth + x];
		else
			return ' ';
	};
	auto SetTile = [&](int x, int y, wchar_t c)
	{
		if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
			sLevel[y * nLevelWidth + x] = c;

	};

	if (fPlayerVelX <= 0) // Moving Left
	{
		//if (GetTile(fNewPlayerPosX + 0.0f, fPlayerPosY + 0.0f) != L'.' || GetTile(fNewPlayerPosX + 0.0f, fPlayerPosY + 0.9f) != L'.')
		if (GetTile(fNewPlayerPosX - playerHalfSize, fPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX - playerHalfSize, fPlayerPosY + playerHalfSize) != L'.')
		{
			fNewPlayerPosX = (int)fNewPlayerPosX + 1;
			fPlayerVelX = 0;
		}
	}
	else // Moving Right
	{
		//if (GetTile(fNewPlayerPosX + 1.0f, fPlayerPosY + 0.0f) != L'.' || GetTile(fNewPlayerPosX + 1.0f, fPlayerPosY + 0.9f) != L'.')
		if (GetTile(fNewPlayerPosX + playerHalfSize, fPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX + playerHalfSize, fPlayerPosY + playerHalfSize) != L'.')
		{
			fNewPlayerPosX = (int)fNewPlayerPosX;
			fPlayerVelX = 0;

		}
	}

		
	if (fPlayerVelY <= 0) // Moving Up
	{
		if (GetTile(fNewPlayerPosX - playerHalfSize, fNewPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX + playerHalfSize, fNewPlayerPosY - playerHalfSize) != L'.')
		{
			fNewPlayerPosY = (int)fNewPlayerPosY + 1;
			fPlayerVelY = 0;
		}
	}
	else // Moving Down
	{
		if (GetTile(fNewPlayerPosX - playerHalfSize, fNewPlayerPosY + playerHalfSize) != L'.' || GetTile(fNewPlayerPosX + playerHalfSize, fNewPlayerPosY + playerHalfSize) != L'.')
		{
			fNewPlayerPosY = (int)fNewPlayerPosY;
			fPlayerVelY = 0;
				
		}
	}
	if (fPlayerVelY> 2.5f)fPlayerVelY = 2.5f;
	if (fPlayerVelY < -2.5f)fPlayerVelY = -2.5f;
	// Apply new position
	fNewPlayerPosX = fPlayerPosX * nTileWidth + fPlayerVelX *10 * fElapsedTime;
	fNewPlayerPosY = fPlayerPosY * nTileHeight + fPlayerVelY *100 * fElapsedTime ;
	setPosition(sf::Vector2f(fNewPlayerPosX, fNewPlayerPosY));
	setVelocity(fPlayerVelX, fPlayerVelY);
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


