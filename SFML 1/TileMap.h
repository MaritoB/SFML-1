#pragma once
#include <SFML\Graphics.hpp>
#include "campeon.h"
#include "Bat.h"
#include "Demon.h"
#include <vector>
class TileMap 
{
public:
	TileMap(std::string  texture, unsigned int nLevelWidth, unsigned int nLevelHeight, std::string & sLevel, unsigned int nTileWidth, unsigned int nTileHeight);
	//bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

	void TileMapDraw(sf::RenderWindow & window, float deltaTime, Campeon & campeon);
	std::string texture;

	void CheckCollisionTileMap(float fElapsedTime, sf::RenderWindow & window, Campeon & campeon);
	
private:

	sf::Sprite sprite_arboles[9];
	sf::Sprite sprite_background[9];

	sf::RectangleShape body;
	sf::Texture textura_fondo;
	sf::Texture textura_Tiles;
	sf::Texture textura_fondo2;
	

	std::vector<Bat>  bats;
	sf::Texture textura_bat;

	std::vector<Demon>  demons;
	sf::Texture textura_demon;

	std::string & sLevel;
	unsigned int nLevelWidth;
	unsigned int nLevelHeight;
	unsigned int nTileWidth;
	unsigned int nTileHeight;

	sf::RectangleShape Tiles[128*9];

	std::vector<sf::RectangleShape> vTiles;

	/*
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);

	}
	*/
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;


};

