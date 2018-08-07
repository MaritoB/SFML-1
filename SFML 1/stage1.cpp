#include"stage1.h"
#include<iostream>
#include "Collider.h"
stage::stage(String fondo)
{
	textura_fondo.loadFromFile(fondo);
	textura_fondo2.loadFromFile("prueba2.png");
	for (int i = 0; i < 4; i++)
	{
		sprite_background[i].setTexture(textura_fondo);
		sprite_arboles[i].setTexture(textura_fondo2);
		sprite_arboles[i].setPosition(1920.0f * i, 0);
		sprite_background[i].setPosition(1920.0f * i, 0);
	}


	textura_bat.loadFromFile("ratbat.png");
	textura_portal.loadFromFile("portal.png");
	textura_demon.loadFromFile("demon.png");
	textura_kyle.loadFromFile("kyle.png");
	textura_boss.loadFromFile("orc.png");
	textura_aliados.loadFromFile("amon.png");
	textura_casa.loadFromFile("casa.png");
	textura_piso.loadFromFile("suelo.png", IntRect(0, 0, 1920, 76));
	textura_cajas.loadFromFile("roca.png", IntRect(0, 0, 125, 146));

	aliados.push_back(aliado(&textura_aliados, Vector2u(10, 1), 0.15f, 18.0f, 100.0f, 0.6f, 100.0f));

	kyles.push_back(Kyle(&textura_kyle, Vector2u(10, 10), 0.15f, 90.0f, 100.0f, 0.6f, 100.0f, Vector2f(3000, 800.0f)));

	cajas.push_back(Platform(&textura_casa, sf::Vector2f(600.0f, 400.0f), sf::Vector2f(150.0f, 820.0f)));

	pisos.push_back(Platform(&textura_piso, sf::Vector2f(1920.0f, 76.0f), sf::Vector2f(1920.0f/2, 1040.0f)));
	pisos.push_back(Platform(&textura_piso, sf::Vector2f(1920.0f, 76.0f), sf::Vector2f(1920.0f / 2 + 1920.0f, 1040.0f)));
	pisos.push_back(Platform(&textura_piso, sf::Vector2f(1920.0f, 76.0f), sf::Vector2f(1920.0f / 2 + 1920.0f * 2, 1040.0f)));
	pisos.push_back(Platform(&textura_piso, sf::Vector2f(1920.0f, 76.0f), sf::Vector2f(1920.0f / 2 + 1920.0f*3, 1040.0f)));




	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(700.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(900.0f, 950.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(950.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(1200.0f, 885.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(1600.0f, 885.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(1600.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(400.0f, 146.0f), sf::Vector2f(2110.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(3400.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(3500.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(3500.0f, 950.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(4300.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(4250.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(4300.0f, 950.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(5000.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(5050.0f, 950.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(5100.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(5350.0f, 885.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(5750.0f, 850.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(125.0f, 146.0f), sf::Vector2f(6150.0f, 820.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(350.0f, 250.0f), sf::Vector2f(6650.0f, 1000.0f)));
	cajas.push_back(Platform(&textura_cajas, sf::Vector2f(700.0f, 1500.0f), sf::Vector2f(7000.0f, 1000.0f)));

	bats.push_back(Bat(&textura_bat, Vector2u(10, 10), 0.07f, 140, 4, 100.0f, 10.0f, Vector2f(1800.0f, 800.0f)));
	bats.push_back(Bat(&textura_bat, Vector2u(10, 10), 0.07f, 140, 4, 100.0f, 10.0f, Vector2f(2000.0f, 800.0f)));
	bats.push_back(Bat(&textura_bat, Vector2u(10, 10), 0.07f, 130, 4, 100.0f, 10.0f, Vector2f(2600.0f, 800.0f)));
	bats.push_back(Bat(&textura_bat, Vector2u(10, 10), 0.07f, 130, 4, 100.0f, 10.0f, Vector2f(4600.0f, 800.0f)));
	bats.push_back(Bat(&textura_bat, Vector2u(10, 10), 0.07f, 130, 4, 100.0f, 10.0f, Vector2f(4800.0f, 800.0f)));

	bosses.push_back(Orco(&textura_boss, Vector2u(10, 10), 0.14f, 90.0f, 100.0f, 0.6f, 50.0f, Vector2f(1300.0f, 800.0f)));
	bosses.push_back(Orco(&textura_boss, Vector2u(10, 10), 0.14f, 90.0f, 100.0f, 0.6f, 50.0f, Vector2f(2000.0f, 800.0f)));
	bosses.push_back(Orco(&textura_boss, Vector2u(10, 10), 0.14f, 90.0f, 100.0f, 0.6f, 50.0f, Vector2f(2800.0f, 800.0f)));
	bosses.push_back(Orco(&textura_boss, Vector2u(10, 10), 0.14f, 90.0f, 100.0f, 0.6f, 50.0f, Vector2f(4700.0f, 800.0f)));
	bosses.push_back(Orco(&textura_boss, Vector2u(10, 10), 0.14f, 100.0f, 100.0f, 0.6f, 50.0f, Vector2f(4500.0f, 800.0f)));

	demons.push_back(Demon(&textura_demon, Vector2u(10, 4), 0.15f, 90.0f, 100.0f, 0.01f, 100.0f, Vector2f(3900, 800.0f)));
	demons.push_back(Demon(&textura_demon, Vector2u(10, 4), 0.15f, 90.0f, 100.0f, 0.01f, 100.0f, Vector2f(5700, 800.0f)));
	demons.push_back(Demon(&textura_demon, Vector2u(10, 4), 0.15f, 90.0f, 100.0f, 0.01f, 100.0f, Vector2f(5800, 800.0f)));


	portals.push_back(Portal(&textura_portal, Vector2u(7, 1), 0.1f, Vector2f(6600, 850.0f)));
}



void stage::procesarColisionesStageX(Campeon& campeon)
{
	sf::Vector2f direction;
	Collider cCampeon = campeon.GetCollider();
	Collider cCaja = caja->GetCollider();
	// push = procentaje de no empujable
	//push = 1 NO EMPUJABLE

	for(Platform& caja : cajas)	
	{
		if (caja.GetCollider().CheckCollision(cCampeon, direction, 1.0f))
			campeon.onCollision(direction);

	}
	for (Portal& portal : portals)
	{
		if ((abs(portal.GetCollider().GetPosition().x - campeon.GetPosition().x ) < 10) && (abs(portal.GetCollider().GetPosition().y - campeon.GetPosition().y) < 10))
		{
			for (int i = 0; i < 4; i++)
			{

				sprite_background[i].setPosition(1920.0f * i ,0);
				sprite_arboles[i].setPosition(1920.0f * i, 0);
			}

			campeon.SetPosition(sf::Vector2f(500, 500));
		}


	}
	for (Platform& piso : pisos)
	{
		if (piso.GetCollider().CheckCollision(cCampeon, direction, 1.0f))
			campeon.onCollision(direction);
	}
	for (Orco& boss : bosses)
	{
		Collider cBoss = boss.GetCollider();

		for (Platform& caja : cajas)
		{
			if (caja.GetCollider().CheckCollision(cBoss, direction, 1.0f))
				boss.onCollision(direction);

		}
		for (Platform& piso : pisos)
		{
			if (piso.GetCollider().CheckCollision(cBoss, direction, 1.0f))
				boss.onCollision(direction);
		}
	}
	for (Demon& demon : demons)
	{
		Collider cDemon = demon.GetCollider();

		for (Platform& caja : cajas)
		{
			if (caja.GetCollider().CheckCollision(cDemon, direction, 1.0f))
				demon.onCollision(direction);

		}
		for (Platform& piso : pisos)
		{
			if (piso.GetCollider().CheckCollision(cDemon, direction, 1.0f))
				demon.onCollision(direction);
		}
	}
	for (Kyle& kyle : kyles)
	{
		Collider cKyle = kyle.GetCollider();

		for (Platform& caja : cajas)
		{
			if (caja.GetCollider().CheckCollision(cKyle, direction, 1.0f))
				kyle.onCollision(direction);

		}
		for (Platform& piso : pisos)
		{
			if (piso.GetCollider().CheckCollision(cKyle, direction, 1.0f))
				kyle.onCollision(direction);
		}
	}
	for (int i = 0; i < 4; i++)
	{

		sprite_background[i].setPosition(sprite_background[i].getPosition().x - 0.0015f * campeon.GetVelocity().x, sprite_background[i].getPosition().y);
		sprite_arboles[i].setPosition(sprite_arboles[i].getPosition().x - 0.0025f * campeon.GetVelocity().x, sprite_arboles[i].getPosition().y);
	}
		

}

void stage::Draw(sf::RenderWindow & window, float deltaTime, Campeon& campeon)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(sprite_background[i]);
		window.draw(sprite_arboles[i]);
	}
	//piso->Draw(window);

	for (Platform& caja : cajas)
		caja.Draw(window);

	for (size_t i = 0; i < demons.size(); i++)
	{
		Demon demon = demons[i];
		if (!demon.getisAlive())
		{
			demons.erase(demons.begin() + i);
		}
	}
	for (Portal& portal: portals)
	{
		portal.Update(deltaTime);
		portal.Draw(window);
	}


	for (Demon& demon : demons)
	{

		demon.Update(deltaTime, campeon);
		demon.Draw(window);
	}
	for (size_t i = 0; i < bosses.size(); i++)
	{
		Orco boss = bosses[i];
		if (!boss.getisAlive())
		{
			bosses.erase(bosses.begin() + i);
		}
	}
	for (Orco& boss : bosses)
	{

		boss.Update(deltaTime, campeon);
		boss.Draw(window);
	}
	for (Platform& piso : pisos)
		piso.Draw(window);
	for (Kyle& kyle : kyles)
	{

		kyle.Update(deltaTime, campeon);
		kyle.Draw(window);
	}
	for (Platform& piso : pisos)
		piso.Draw(window);
	for (aliado& aliado : aliados)
	{
		aliado.Update(deltaTime);
		aliado.Draw(window);
	}
	
	for (size_t i = 0; i < bats.size(); i++)
	{
		Bat bat = bats[i];
		if (!bat.getisAlive())
		{
			bats.erase(bats.begin() + i);
		}

	}

	for (Bat& bat : bats)
	{
		if (bat.getisAlive())
		{
			bat.Update(deltaTime, campeon);
			bat.Draw(window);
		}

	}
}

Sprite stage::getFondo() {
	return sprite_background[1];
}
Sprite stage::getPiso() {
	return sprite_piso;
}

