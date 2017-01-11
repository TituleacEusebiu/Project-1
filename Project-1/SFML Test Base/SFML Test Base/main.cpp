#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{	
	float ax, ay, bx, by;
	ax = std::rand() * 40 % 640;
	ay = std::rand() * 40 % 640;
	bx = std::rand() * 40 % 640;
	by = std::rand() * 40 % 640;
	char s = 'X';

	sf::Time time = sf::seconds(2);

	sf::RenderWindow window(sf::VideoMode(640, 640), "Snake", sf::Style::Close | sf::Style::Resize); // sf::Style::Fullscreen);
	sf::RectangleShape ecran(sf::Vector2f(640.0f, 640.0f));

	sf::RectangleShape player(sf::Vector2f(40, 40)); // player
	player.setPosition(ax, ay);

	sf::RectangleShape food(sf::Vector2f(40, 40)); // food
	food.setPosition(bx, by);

	sf::Texture playerTexture;							// textura player
	playerTexture.loadFromFile("player1.png");
	player.setTexture(&playerTexture);

	sf::Texture foodTexture;							//textura hrana
	foodTexture.loadFromFile("food.png");
	food.setTexture(&foodTexture);

	sf::Texture ecranTexture;							//textura fereastra
	ecranTexture.loadFromFile("4h.png");
	ecran.setTexture(&ecranTexture);

	window.setFramerateLimit(10);

	while (window.isOpen())
	{
		sf::Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}

		}

		if (player.getPosition().x > 600)
			player.setPosition(0.0, player.getPosition().y);

		if (player.getPosition().x < 0)
			player.setPosition(600, player.getPosition().y);

		if (player.getPosition().y > 600)
			player.setPosition(player.getPosition().x, 0);	

		if (player.getPosition().y < 0)
			player.setPosition(player.getPosition().x, 600);

		
		
		if (player.getPosition().x == food.getPosition().x && player.getPosition().y == food.getPosition().y ||
			player.getPosition().x == food.getPosition().x+20 && player.getPosition().y == food.getPosition().y+20 ||
			player.getPosition().x == food.getPosition().x-20 && player.getPosition().y == food.getPosition().y-20 ||
			player.getPosition().x == food.getPosition().x-20 && player.getPosition().y == food.getPosition().y+20 ||
			player.getPosition().x == food.getPosition().x+20 && player.getPosition().y == food.getPosition().y-20)
		{
			food.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			bx = std::rand() * 40 % 640;
			by = std::rand() * 40 % 640;
			food.setPosition(bx, by);
		}

		if (s == 'A' )
			player.move(-20.0f, 0.0f);
		if (s == 'D')
			player.move(20.0f, 0.0f);
		if (s == 'W')
			player.move(0.0f, -20.0f);
		if (s == 'S')
			player.move(0.0f, 20.0f);

		if (s != 'D' && s != 'A')
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{	
			player.move(-20.0f, 0.0f);
			s = 'A';
		
		}
		if (s != 'D' && s != 'A')
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(20.0f, 0.0f);
			s = 'D';
		}
		if (s != 'W' && s != 'S')
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -20.0f);
			s = 'W';
		}
		if (s != 'S' && s != 'W')
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 20.0f);
			s = 'S';
		}

		

		window.clear();
		window.draw(player);
		window.draw(ecran);
		window.draw(player);
		window.draw(food);
		window.display();
		window.clear();
	}
	return 0;
}