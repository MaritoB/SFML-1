#include "TileMap.h"
#include <iostream>


TileMap::TileMap(std::string  texture, sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height) 
{
	this->texture = texture;
	this->tileSize = tileSize;
	this->tiles = tiles;
	this->width = width;
	this->height = height;
	load(texture, tileSize, tiles, width, height);

}
bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	textura_fondo.loadFromFile("prueba.png");
	textura_fondo2.loadFromFile("prueba2.png");
	for (int i = 0; i < 4; i++)
	{
		sprite_background[i].setTexture(textura_fondo);
		sprite_arboles[i].setTexture(textura_fondo2);
		sprite_arboles[i].setPosition(1920.0f * i, 0);
		sprite_background[i].setPosition(1920.0f * i, 0);
	}

	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position =sf::Vector2f((float)i * tileSize.x,(float) j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	return true;
}

void TileMap::Draw(sf::RenderWindow & window, float deltaTime, Campeon & campeon)
{

	for (int i = 0; i < 4; i++)
	{
		//background movement
		sprite_background[i].setPosition(sprite_background[i].getPosition().x - 0.0015f * campeon.GetVelocity().x, sprite_background[i].getPosition().y);
		sprite_arboles[i].setPosition(sprite_arboles[i].getPosition().x - 0.0025f * campeon.GetVelocity().x, sprite_arboles[i].getPosition().y);
	}

	for (int i = 0; i < 4; i++)
	{
		window.draw(sprite_background[i]);
		window.draw(sprite_arboles[i]);
	}
	
	auto GetTile = [&](int x, int y)
	{
	//colision del centro
		if (x >= 0 && x < width*tileSize.x && y >= 0 && y < height*tileSize.y)
		{

			return  tiles[(int)campeon.GetPosition().x / tileSize.x + (int)(campeon.GetPosition().y / tileSize.y)*width];
		}
		else
			return 404;
	 
	};
	auto SetTile = [&](int x, int y, wchar_t c)
	{
	if (x >= 0 && x < width && y >= 0 && y < height)
	tiles[y*width + x] = c;
	};
	

	if (GetTile(campeon.GetPosition().x , campeon.GetPosition().y ) == 3)
	{
		sf::Vector2f direccion;
		direccion.x = 0;
		direccion.y = -1;

		campeon.onCollision(direccion);
		campeon.GetCollider().Move(0.0f,-1.0f);
	}
}
