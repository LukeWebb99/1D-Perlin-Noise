#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "PerlinNoise.hpp"
#include <iostream>

using namespace std;



int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(400, 400), "PerlinNoise 1D");
	window.setFramerateLimit(144);
	siv::PerlinNoise Noise;
	Noise.reseed(25738);

	float inc = 0.01;
	float start = 0;

	/*
	lines[0].position = sf::Vector2f(rand() % 400, rand() % 400);
	*/

	sf::VertexArray lines(sf::LinesStrip, 400);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		float yoff = start;
		for (int x = 0; x < 400; x++) {
			//int y = rand() % 400;
			float y = Noise.octaveNoise0_1(yoff, 2) * 400;
			//cout << y << endl;
			lines[x].position = sf::Vector2f(x, y);

			yoff += inc;
		}
		start = start + inc;
		//cout << start << endl;

		window.clear();
		window.draw(lines);
		window.display();
	}

	return 0;
}