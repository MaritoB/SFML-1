#include "TileMap.h"
#include <iostream>
#include <vector>

TileMap::TileMap(std::string  texture, unsigned int nLevelWidth, unsigned int nLevelHeight, std::string & sLevel, unsigned int nTileWidth, unsigned int nTileHeight) :
	nLevelWidth(nLevelWidth), nLevelHeight(nLevelHeight), sLevel(sLevel), nTileWidth(nTileWidth), nTileHeight(nTileHeight)
{

	textura_Tiles.loadFromFile("Tiles.png");
	textura_fondo.loadFromFile("prueba.png");
	textura_fondo2.loadFromFile("prueba2.png");
	textura_bat.loadFromFile("ratbat.png");
	textura_demon.loadFromFile("Demon.png");


	for (int i = 0; i < 9; i++)
	{
		sprite_background[i].setTexture(textura_fondo);
		sprite_arboles[i].setTexture(textura_fondo2);
		sprite_arboles[i].setPosition(1920.0f * i, -300);
		sprite_background[i].setPosition(1920.0f * i, -300);
	}
	auto GetTile = [&](int x, int y)
	{
		if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
			return sLevel[y * nLevelWidth + x];
		else
			return ' ';
	};
	auto SetTile = [&](int x, int y, char c)
	{
		if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight)
			sLevel[y * nLevelWidth + x] = c;

	};

	for (int x = 0; x < nLevelWidth; x++)
	{
		for (int y = 0; y < nLevelHeight; y++)
		{
			Tiles[x + y * nLevelWidth].setPosition(x * nTileWidth, y * nTileHeight);
			Tiles[x + y * nLevelWidth].setSize(sf::Vector2f(nTileWidth, nTileHeight));

			wchar_t sTileID = GetTile(x, y);
			switch (sTileID)
			{
			case '.':

				//Tiles[x + y * nLevelWidth].setFillColor(sf::Color::Cyan);

				break;
			case 'q':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(0, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'w':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128*1, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'e':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 2, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'a':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 3, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;

			case 's':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 4, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'd':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 5, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'z':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 6, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'x':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 7, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;

			case 'c':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 8, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'r':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 * 9, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 't':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 *10, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'f':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 *11, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;

			case 'g':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 *12, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'h':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 *13, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'b':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 *14, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case 'y':

				Tiles[x + y * nLevelWidth].setTexture(&textura_Tiles);
				Tiles[x + y * nLevelWidth].setTextureRect(sf::IntRect(128 *15, 0, 128, 128));
				vTiles.push_back(Tiles[x + y * nLevelWidth]);
				break;
			case '1':

				bats.push_back(Bat(&textura_bat, sf::Vector2u(10, 10), 0.07f, 140, 4, 150.0f + x, 10.0f, sf::Vector2f(x*nTileWidth, y*nTileHeight)));
				SetTile(x, y, '.');
				break;
			case '2':

				demons.push_back(Demon(&textura_demon, sf::Vector2u(10, 4), 0.12f, 130.0f, 100.0f, 0.01f, 100.0f, sf::Vector2f(x*nTileWidth, y*nTileHeight)));
				SetTile(x, y, '.');
				break;
			default:
				break;
			}

		}

	}
} 
/*
bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{

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
*/

void TileMap::TileMapDraw(sf::RenderWindow & window, float deltaTime, Campeon & campeon)
{
	
	
	for (int i = 0; i < 9; i++)
	{
		//background movement
		sprite_background[i].setPosition(sprite_background[i].getPosition().x - 0.15f * campeon.GetVelocity().x, sprite_background[i].getPosition().y);
		sprite_arboles[i].setPosition(sprite_arboles[i].getPosition().x - 0.35f * campeon.GetVelocity().x, sprite_arboles[i].getPosition().y);
	}

	for (int i = 0; i < 9; i++)
	{
		window.draw(sprite_background[i]);
		window.draw(sprite_arboles[i]);
	}
	
	for (sf::RectangleShape& Tile : vTiles)
	{
		
		window.draw(Tile);

			
	}
	for (size_t i = 0; i < bats.size(); i++)
	{
		Bat bat = bats[i];
		if (!bat.getisAlive())
		{
			bats.erase(bats.begin() + i);
		}

	}

	for (Demon& Demon : demons)
	{
		if (Demon.getisAlive())
		{
			Demon.Update(deltaTime, campeon, sLevel, nTileWidth, nTileHeight, nLevelWidth, nLevelHeight);
			Demon.Draw(window);
		}

	}
	for (size_t i = 0; i < demons.size(); i++)
	{
		Demon Demon = demons[i];
		if (!Demon.getisAlive())
		{
			demons.erase(demons.begin() + i);
		}

	}

	for (Bat& bat : bats)
	{
		if (bat.getisAlive())
		{
			bat.Update(deltaTime, campeon, sLevel, nTileWidth, nTileHeight, nLevelWidth, nLevelHeight);
			bat.Draw(window);
		}

	}
	/*
	for (unsigned int i = 0; i <64*16; i++)
	{
		window.draw(Tiles[i]);

	}
	*/
	
	
}


void TileMap::CheckCollisionTileMap(float fElapsedTime, sf::RenderWindow & window, Campeon & campeon) {

	campeon.inputHandler(window);
	campeon.setVelocity(campeon.GetVelocity().x*0.91f, campeon.GetVelocity().y*0.99f);
	float fPlayerVelX = campeon.GetVelocity().x;
	float fPlayerVelY = campeon.GetVelocity().y;
	float fPlayerPosX = campeon.GetPosition().x/nTileWidth;
	float fPlayerPosY = campeon.GetPosition().y/nTileHeight;
	float playerHalfSize = campeon.GetCollider().GetHalfSize().x/ nTileWidth;
	fPlayerVelY += 20.0f * fElapsedTime;

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
		if (GetTile(fNewPlayerPosX - playerHalfSize, fPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX - playerHalfSize, fPlayerPosY + playerHalfSize ) != L'.')
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

	campeon.setCanJump(false);
	if (fPlayerVelY <= 0) // Moving Up
	{
		if (GetTile(fNewPlayerPosX - playerHalfSize, fNewPlayerPosY - playerHalfSize) != L'.' || GetTile(fNewPlayerPosX + playerHalfSize, fNewPlayerPosY- playerHalfSize) != L'.')
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
			campeon.setCanJump(true); // Player has a solid surface underfoot
									//nDirModX = 0;
		}
	}
	// Apply new position
	fNewPlayerPosX = fPlayerPosX + fPlayerVelX * fElapsedTime;
	fNewPlayerPosY = fPlayerPosY + fPlayerVelY * fElapsedTime;
	campeon.setPosition(sf::Vector2f(fNewPlayerPosX*nTileWidth, fNewPlayerPosY*nTileHeight));
	campeon.setVelocity(fPlayerVelX, fPlayerVelY);

	campeon.Update(fElapsedTime, window);



}