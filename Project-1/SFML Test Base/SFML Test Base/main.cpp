#include <SFML/Graphics.hpp>
#include <iostream>

static const float VIEW_HEIGHT = 512.0f;
// void
//aaaaa
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{	
	//int Random = sf::Randomizer::Random(0, 100);
	char s = 'X';
	sf::RenderWindow window(sf::VideoMode(900, 600), "Snake", sf::Style::Close | sf::Style::Resize); // sf::Style::Fullscreen);
	sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
	player.setPosition(206.0f, 206.0f);
	player.setFillColor(sf::Color::Blue);
	//sf::Texture playerTexture;
	//playerTexture.loadFromFile("romania.jpg");
	//player.setTexture(&playerTexture);
	window.setFramerateLimit(60);
	//sf::Vector2u textureSize = playerTexture.getSize();
	//textureSize.x /= 3;
	//textureSize.y /= 9;
	//player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));

	sf::RectangleShape food(sf::Vector2f(50.0f, 50.0f));
	food.setPosition(206.0f, 206.0f);
	food.setFillColor(sf::Color::Red);
	food.setPosition(rand()%900, rand() % 600);
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
		if (s == 'A')
			player.move(-1.0f, 0.0f);
		if (s == 'D')
			player.move(1.0f, 0.0f);
		if (s == 'W')
			player.move(0.0f, -1.0f);
		if (s == 'S')
			player.move(0.0f, 1.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{	
			player.move(-0.5f, 0.0f);
			s = 'A';
		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.5f, 0.0f);
			s = 'D';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.5f);
			s = 'W';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.5f);
			s = 'S';
		}



		window.clear();
		window.draw(player);
		window.draw(food);
		window.display();
		window.clear();
	}
	return 0;
}