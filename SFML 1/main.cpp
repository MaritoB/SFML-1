
#include "juego.h"
#include "TileMap.h"
#include "stage1.h"
#include <math.h>
#include <SFML/Audio/Music.hpp>

static const float VIEW_HEIGHT = 800;
void ResizedView(sf::RenderWindow& window, sf::View& vista)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600),"Juego", sf::Style::Close | sf::Style::Resize);
	sf::View vista(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 600));
	vista.setCenter(300, 300);
	vista.zoom(1.0f);
	window.setView(vista);
	window.setFramerateLimit(60);
	sf::Music music ;
	music.openFromFile("music.ogg");
	music.setVolume(50);
	music.setPlayingOffset(sf::seconds(70));
	music.play();
	//stage stage1("prueba.png");
	Texture textura_campeon0;
	textura_campeon0.loadFromFile("jack.png");
	Campeon campeon(&textura_campeon0, Vector2u(10, 6), 0.07f, 0.30f, 0.030f, 0.6f, 100.0f);
	
	string sLevel =   "......................................ad.........................................ad...................ad.................assss..";
			sLevel += "......................................ad...1.1...................................ad............2......ad.......qe........assss..";
			sLevel += "......................................ase.................1.1...............1.1..ad............t......ad...........qe....asssss.";
			sLevel += "......................................asswwwwe.......qwe.....................2...ad...11.....qwwwe....ad2.t............qessss...";
			sLevel += "..........................2...2.......zsxxxxxxe.....qssse............qwwe.2.qwe..zxwe.....2.qssssswe..zsggxggge....qwwwssssss...";
			sLevel += ".....1..1.......1.1.....qwwwwwwwwwwe...b.1.11.b....qsxxxxgggh....qwwwsssswwwssd....zc...qwwwsssssssd...b1.1.1.b...qsssssssss....";
			sLevel += "..........qe...........qsssssssssssse............qwsd12.........qsssssssssssssswe..11..qsssssssssssse.....qe.....qsssssss.......";
			sLevel += "wwwwwwwwwwsswwwwwwwwwwwsssssssssssssswwwwwwwwwwwwsssswwwwwwwwwwwssssssssssssssssswwwwwwsssssssssssssswwwwwwwwwwwwsssssss........";
			sLevel += "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss..........";

	TileMap map("tiles64.png", 128,9, sLevel, 128,128);


	
	Clock reloj;
	float deltaTime = 0.0f;

	while (window.isOpen())
	{

		deltaTime = reloj.restart().asSeconds();
		Event evento;
		while (window.pollEvent(evento))
		{
			switch (evento.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				ResizedView(window, vista);
				break;


			}

		}

		//stage1.procesarColisionesStageX(campeon);
		/*
		
		if (campeon.GetPosition().x <400)
			vista.setCenter(400, 750);
		else if(campeon.GetPosition().x >1520)
			vista.setCenter(1520, 750);
		else
		*/

		//VISTA CON ACELERACION
		/*
			int viewMovement;
			viewMovement = 0;
			if ((campeon.GetPosition().x - vista.getCenter().x) > 0) viewMovement = 4;
			if ((campeon.GetPosition().x - vista.getCenter().x) < 0) viewMovement = -4;
			if (abs(campeon.GetPosition().x - vista.getCenter().x) < 50)
			{
				vista.setCenter(vista.getCenter().x, 750);
			}
			else
			{
				vista.setCenter(vista.getCenter().x + viewMovement, 750);

			}
		*/
		
		//vista.setCenter(campeon.GetPosition().x, 750);

		window.clear();
		window.setView(vista);
		map.CheckCollisionTileMap(deltaTime,window,campeon);
		vista.setCenter(campeon.GetPosition().x, campeon.GetPosition().y - 50 );
		map.TileMapDraw(window, deltaTime, campeon);
		//window.draw(map);
		//stage1.Draw(window, deltaTime,campeon);
		campeon.Draw(window);
		window.display();

	}
	return 0;
}
