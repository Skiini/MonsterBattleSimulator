/* Author : Martins Filipe
 * Name : Monster Battle Simulator
 * Date : 2016.11.28
 */

#include <iostream>
#include "Monster.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
	double m1PosX = 0.0;
	double m1PosY = 150.0;
	double m2PosX = 350.0;
	double m2PosY = 150.0;

	//Setting Monsters
	Monster m1 = Monster("MonsterValues1.json", m1PosX, m1PosY);
	Monster m2 = Monster("MonsterValues2.json", m2PosX, m2PosY);

	sf::Music music;
	music.openFromFile("data/battle1.ogg");
	

	sf::RenderWindow window(sf::VideoMode(500, 500), "Battle!");

	while (window.isOpen()) //GameLoop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		while (m1.getHealth() <= 0 || m2.getHealth() <= 0)
		{
			if (m1.getSpeed()>m2.getSpeed())
			{
				m1.attack(&m2);
				m2.attack(&m1);
			}
			else
			{
				m2.attack(&m1);
				m1.attack(&m2);
			}

			music.play();
			/* TO DO : - Showing the winner*/
		}

		window.clear();
		m1.draw(&window);
		m2.draw(&window);
		window.display();
	}

	system("pause");
	return 0;
}