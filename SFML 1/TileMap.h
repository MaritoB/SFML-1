#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "campeon.h"
#include <vector>
class TileMap : public sf::Drawable, public sf:: Transformable
{
public:
	TileMap(std::string texture, sf::Vector2u tileSize, int* tiles,unsigned int width, unsigned int height);
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

	Collider GetCollider() { return Collider(body); }
	void Draw(sf::RenderWindow & window, float deltaTime, Campeon & campeon);
	std::string texture;
	sf::Vector2u tileSize;
	int* tiles;
	unsigned int width;
	unsigned int height;
private:

	sf::Sprite sprite_arboles[4];
	sf::Sprite sprite_background[4];

	sf::RectangleShape body;
	sf::Texture textura_fondo;
	sf::Texture textura_fondo2;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);

	}
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;


};

