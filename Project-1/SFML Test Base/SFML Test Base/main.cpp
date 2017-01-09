#include <SFML/Graphics.hpp>
#include <iostream>

static const float VIEW_HEIGHT = 512.0f;
// void

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{

	sf::RenderWindow window(sf::VideoMode(900, 600), "Snake", sf::Style::Close | sf::Style::Resize); // sf::Style::Fullscreen);
	sf::RectangleShape player(sf::Vector2f(150.0f, 100.0f));

	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("romania.jpg");
	player.setTexture(&playerTexture);

	//sf::Vector2u textureSize = playerTexture.getSize();
	//textureSize.x /= 3;
	//textureSize.y /= 9;
	//player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));

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
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{	
			player.move(-0.1f, 0.0f);
		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		}



		window.clear();
		window.draw(player);
		window.display();
	}
	return 0;
}