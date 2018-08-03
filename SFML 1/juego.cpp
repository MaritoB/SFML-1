#include "juego.h"
#include "animacion.h"
#include "campeon.h"
//#include<stdlib.h>
#include<windows.h>

juego::juego(int resolucionX, int resolucionY, std::string Titulo) 
{
	window.create(VideoMode(resolucionX, resolucionY), Titulo);

    stage1 = new stage("fondo1.png");
	
	
	//reloj = new Clock();
	/*
	sprite_bola = new Sprite(*textura_bola);
	textura_bola = new Texture;
	textura_bola->loadFromFile("bola.png", IntRect(0, 0, 24,16));

	 
	relojSpawn = new Clock();
	relojBola = new Clock();
	tiempo = new Time();
	sprite_campeon->setScale(3, 3);
	sprite_bola->setScale(2, 2);
	sprite_campeon->setOrigin(16, 16);
	sprite_campeon->setPosition(600, 800);
	for (int i = 0; i < 3; i++)
	{
		bat[i] = new enemigo("ratbat.png");

		relojEnemigo [i] = new Clock();
		bat[i]->animacionenemigo(1, i, "ratbat.png");
		bat[i]->get_sprite().setPosition( 1200 + 200.f * i, 100.0f + 100 * i);
	}
	isOut = true;
	evento = new Event;
	*/
	window.setFramerateLimit(60);
	gameLoop();
}

void juego::dibujar(){


	/*
	for (int i = 0; i < 5 ; i++)
	{

		window.draw(stage1->getCajas(i));
	}

	for (int i = 0; i < 3; i++)
	{
		if (bat[i]->getisDead() == false) {
			window.draw(bat[i]->get_sprite());
		}
	}
	campeon->Draw(window);
	if (!isOut) {
		window.draw(*sprite_bola);
	}*/
}
void juego::gameLoop() {
	Clock reloj;
	float deltaTime = 0.0f;
	deltaTime = reloj.restart().asSeconds();

	Texture textura_campeon0;
	textura_campeon0.loadFromFile("StreetThief.png");
	Campeon campeon(&textura_campeon0, Vector2u(10, 6), 0.3f, 32.0f,200.0f, 0.20f,100);

	while (window.isOpen())
	{
		Event evento;
		while (window.pollEvent(evento)) 
		{
			switch (evento.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
			
		}
		campeon.Update(deltaTime);
		window.clear();
		//window.setView(vista);
		//window.draw(stage1->getFondo());
		//window.draw(stage1->getPiso());
		campeon.Draw(window);
		window.display();
	}
}
//void juego::acciones() {	
	//procesarEnemigos();
	//efectoGravedad();
	//procesarMouse();
	//procesarEventos();
	//procesarColisiones();
//	stage1->procesarColisionesStage(*sprite_campeon);
	/*if (!isOut)
	{
		trayectoBola();
	}
	// CAMARA
	/*

	}*/
//}
/*
void juego::procesarColisiones()
{
	for (int i = 0; i < 3 ; i++)
	{
		if (bat[i]->getisDead() == false && isOut == false)
		{
			if (sprite_bola->getGlobalBounds().intersects(bat[i]->get_sprite().getGlobalBounds())){
				isOut = true;
				bat[i]->morir();

			}
		}
	}
}
	




int juego::procesarMouse() {
	posicion_mouse = Mouse::getPosition(window);
	posicion_mouse = (Vector2i)window.mapPixelToCoords(posicion_mouse);
	return posicion_mouse.x;
} 

void juego::spawn_enemigos()
{
	Time tiempo2;



		for (int i = 0; i < 3; i++)
		{
			*tiempo = relojSpawn->getElapsedTime();
			if (tiempo->asSeconds() > 5) {
				if (bat[i]->getisDead())
				{
					bat[i]->setisDead(false);
					cout << "revivio";
					bat[i]->get_sprite().setPosition(1920.f, 300 );
					relojSpawn->restart();
				}
			}
		}
	
	


}
void juego::procesarEnemigos()
{
	static int n[3];

	for (int i = 0; i < 3; i++)
	{
		spawn_enemigos();
		if (bat[i]->getisDead()==false)

		*tiempo = relojEnemigo[i]->getElapsedTime();
		if (tiempo->asSeconds() > 0.03) {

			bat[i]->animacionenemigo(5, n[i], "ratbat.png");
			if(!bat[i]->getisDead())
				bat[i]->mover();
			relojEnemigo[i]->restart();

			if (n[i] < 9) n[i] ++;
			else n[i] = 0;
		}

	}
}

void juego::procesarEventos() 
{
	static float movimiento = 0;
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (movimiento > -6)
		movimiento = movimiento - 0.1f;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (movimiento < 6)
		movimiento = movimiento + 0.1f;
	}

	if (movimiento > 0) {
		animacion(2);
	}
	else
	{
		if (movimiento == 0) animacion(0);
		else animacion(5);
	}

	if (stage1->procesarColisionesStageX(*sprite_campeon, movimiento))
		movimiento = 0;
	else
		sprite_campeon->setPosition(sprite_campeon->getPosition().x + movimiento, sprite_campeon->getPosition().y);

	if (!Keyboard::isKeyPressed(Keyboard::A))
	{
		if (movimiento < 0)
		{
			movimiento += 0.2f;
			if (movimiento > 0) movimiento = 0;
		}

	}
	if (!Keyboard::isKeyPressed(Keyboard::D))
	{
		if (movimiento > 0)
		{
			movimiento -= 0.2f;
			if (movimiento < 0) movimiento = 0;
		}

	}
	if (Keyboard::isKeyPressed(Keyboard::G)) {

		animacionAtacar();

	}
	if (Keyboard::isKeyPressed(Keyboard::H)) {

		animacionMorir();

	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if ((stage1->procesarColisionesStage(*sprite_campeon).getPosition().y -46) <= sprite_campeon->getPosition().y){
			setGravedad(1);
			setImpulso(-14);
		}

	}
	while (window.pollEvent(*evento))
	{

		switch (evento->type)
		{
		case Event::Closed:
				window.close();
				break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				isOut = false;
				sprite_bola->setPosition(sprite_campeon->getPosition().x, sprite_campeon->getPosition().y);
				inicioBola.x = sprite_campeon->getPosition().x;
				inicioBola.y = sprite_campeon->getPosition().y;
				destinoBola.x = (float)posicion_mouse.x;
				destinoBola.y = (float)posicion_mouse.y;

			}
			break;
		}


	}



}

void juego::animacion(int i)
{
	static int n = 0;
	
	*tiempo = reloj->getElapsedTime();
	if (tiempo->asSeconds() > 0.05) {
		textura_campeon0->loadFromFile("StreetThief.png", IntRect(n * 32 + 7, i * 32 +1, 18, 31));
		if (n<9)n++;
		else n = 0;
		reloj->restart();
	}


}
void juego::animacionMorir() {
	bool fin = true;
	int n = 0;

	reloj->restart();
	while (fin)
	{
		*tiempo = reloj->getElapsedTime();
		if (tiempo->asSeconds() > 0.1) {
			textura_campeon0->loadFromFile("StreetThief.png", IntRect(0 + n * 32, 0 + 4 * 32, 32, 32));
			dibujar();
			reloj->restart();
			if (n < 9)n++;
			else fin = false;
		}
	}
}
void juego::animacionAtacar()
{
	bool fin = true;
	int n = 0;

	reloj->restart();
	while (fin)
	{
		*tiempo = reloj->getElapsedTime();
		if (tiempo->asSeconds() > 0.04) {
			textura_campeon0->loadFromFile("StreetThief.png", IntRect(0 + n * 32, 0 + 3 * 32, 32, 32));
			dibujar();
			reloj->restart();
			if (n < 9)n++;
			else fin = false;
		}
	}
} 
void juego::trayectoBola()
{
	float xi;
	float yi;
	float xf;
	float yf;
	xi = inicioBola.x;
	yi = inicioBola.y;
	xf = destinoBola.x;
	yf = destinoBola.y;

	float xn = xi;
	float yn = yi;
	xn =   (xf - xi)/30;
	yn =   (yf - yi)/30;

	*tiempo = relojBola->getElapsedTime();
	if (tiempo->asSeconds() > 0.03) {
		
		sprite_bola->setPosition(sprite_bola->getPosition().x + xn, sprite_bola->getPosition().y + yn);
		animacionBola();
		relojBola->restart();
		if (sprite_bola->getPosition().x > 1920 || sprite_bola->getPosition().y > 1080 || sprite_bola->getPosition().x < 0 || sprite_bola->getPosition().y < 0) 
		{
			isOut = true;
			
		}
	}

	
}
void juego::animacionBola()
{

	static int n = 0;


		textura_bola->loadFromFile("bola.png", IntRect(0 + 0, 0 + n * 16, 24, 16));

		if (n<8)n++;
		else n = 0;



}
void juego::animacionSaltar() {

	textura_campeon0->loadFromFile("StreetThief.png", IntRect(0 + 2 * 32, 0 + 2 * 32, 32, 32));

}

void juego::efectoGravedad() {
	float resultante;
	Sprite x = stage1->procesarColisionesStage(*sprite_campeon);
	int suelo = x.getPosition().y ;
	static bool resetear = false;
	resultante = 0;
	resultante = getImpulso() + getGravedad();
	int alturaCampeon = sprite_campeon->getGlobalBounds().height / -2;

	if ((sprite_campeon->getPosition().y - alturaCampeon) > suelo) {
		//si estoy mas a bajo que el suelo, vuelvo al sueloa
		sprite_campeon->setPosition(sprite_campeon->getPosition().x, suelo + alturaCampeon);
	}

	if ((sprite_campeon->getPosition().y - alturaCampeon) == suelo ) {
		//salto desde el suelo
		sprite_campeon->setPosition(sprite_campeon->getPosition().x, sprite_campeon->getPosition().y  + resultante);
	}

	if ((sprite_campeon->getPosition().y - alturaCampeon) < suelo ) {
		//subiendo o bajando
		//cuando me paso cayendo 
		if (sprite_campeon->getPosition().y - alturaCampeon + resultante > suelo )
		{
			sprite_campeon->setPosition(sprite_campeon->getPosition().x, (float)suelo - alturaCampeon);
			resultante = 0;
			setImpulso(0);

		}
		else 
		{
			sprite_campeon->setPosition(sprite_campeon->getPosition().x, sprite_campeon->getPosition().y + resultante);
			setImpulso(resultante);
		}
	}
	else
	{
		if (resetear) {
			setImpulso(0);
			resultante = 0;
			sprite_campeon->setPosition(sprite_campeon->getPosition().x, (float)suelo - alturaCampeon);

		}
	}
	
	if (sprite_campeon->getPosition().y <= suelo) {

		if (sprite_campeon->getPosition().y + resultante > suelo) {

			sprite_campeon->setPosition(sprite_campeon->getPosition().x,(float)suelo);
			resetear = true;
		}
		else
		{
			sprite_campeon->setPosition(sprite_campeon->getPosition().x, sprite_campeon->getPosition().y + resultante);
			resetear = true;
		}
	}
	else {
		if (resetear) {
			setGravedad(0);
			setImpulso(0);
			resultante = 0;
			sprite_campeon->setPosition(sprite_campeon->getPosition().x,(float)suelo);

			resetear = false;
		}
	
		
}

void juego::setGravedad(float x) 
{
	gravedad = x;

}
void juego::setImpulso(float x)
{
	impulso = x;

}
float juego::getGravedad() {

	return gravedad;
}
float juego::getImpulso() {

	return impulso;
}
*/