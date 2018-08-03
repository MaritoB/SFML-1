
#include "juego.h"
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
	vista.zoom(1.f);
	window.setView(vista);
	window.setFramerateLimit(60);
	sf::Music music ;
	music.openFromFile("music.ogg");
	music.setVolume(5);
	music.setPlayingOffset(sf::seconds(60));
	music.play();
	stage stage1("prueba.png");
	Texture textura_campeon0;
	textura_campeon0.loadFromFile("StreetThief.png");
	Campeon campeon(&textura_campeon0, Vector2u(10, 6), 0.07f, 18.0f, 100.0f, 0.6f, 100.0f);


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
		campeon.Update(deltaTime, window);

		stage1.procesarColisionesStageX(campeon);
		/*
		
		if (campeon.GetPosition().x <400)
			vista.setCenter(400, 750);
		else if(campeon.GetPosition().x >1520)
			vista.setCenter(1520, 750);
		else
		*/
		vista.setCenter(campeon.GetPosition().x, 750);
		window.clear();
		window.setView(vista);
		stage1.Draw(window, deltaTime,campeon);
		campeon.Draw(window);
		window.display();
	}
	return 0;
}
