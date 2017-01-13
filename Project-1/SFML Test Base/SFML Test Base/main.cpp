#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	sf::RenderWindow meniu(sf::VideoMode(450, 450), "Menu", sf::Style::Close);
	sf::RectangleShape menu(sf::Vector2f(450.0f, 450.0f));
	sf::Texture meniuTexture;
	meniuTexture.loadFromFile("menu.png");
	menu.setTexture(&meniuTexture);



	while (meniu.isOpen())
	{
		sf::Event evnttt;

		while (meniu.pollEvent(evnttt))
		{
			switch (evnttt.type)
			{
			case sf::Event::Closed:
			{
				meniu.close();
				return EXIT_SUCCESS;
				break;
			}
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(meniu);
			if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 375 && mousePos.y < 450)
			{
				meniu.close();
				return EXIT_SUCCESS;
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(meniu);
			if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 195 && mousePos.y < 295)
			{
				meniu.close();
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
				sf::Vector2i mousePos = sf::Mouse::getPosition(meniu);
				if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 295 && mousePos.y < 375)
				{
					sf::RenderWindow instructiuni(sf::VideoMode(528, 373), "Menu", sf::Style::Close);
					sf::RectangleShape instruct(sf::Vector2f(528.0f, 373.0f));
					sf::Texture instructTexture;
					instructTexture.loadFromFile("instructiuni.png");
					instruct.setTexture(&instructTexture);

					while (instructiuni.isOpen())
					{
						sf::Event evt;

						while (instructiuni.pollEvent(evt))
						{
							switch (evt.type)
							{
							case sf::Event::Closed:
							{
								instructiuni.close();
								break;
							}
							}
						}
						instructiuni.clear();
						instructiuni.draw(instruct);
						instructiuni.display();
					}
			}

		}
		meniu.clear();
		meniu.draw(menu);
		meniu.display();
	}


	int i = 1, j = 0, c = 1, k = 1;
	float ax, ay, bx, by;
	ax = rand() * 40 % 640;
	ay = rand() * 40 % 640;
	bx = rand() * 40 % 640;
	by = rand() * 40 % 640;

	char s = 'X';

	sf::RectangleShape snake[256];

	sf::RenderWindow window(sf::VideoMode(640, 640), "Snake", sf::Style::Close);
	sf::RectangleShape ecran(sf::Vector2f(640.0f, 640.0f));


	sf::RectangleShape player(sf::Vector2f(40, 40)); // player
	player.setPosition(ax, ay);

	sf::RectangleShape food(sf::Vector2f(40, 40)); // food
	food.setPosition(bx, by);

	sf::Texture playerTexture;							// textura player
	playerTexture.loadFromFile("player1.png");
	player.setTexture(&playerTexture);
	snake[0] = player;

	sf::Texture foodTexture;							//textura hrana
	foodTexture.loadFromFile("food.png");
	food.setTexture(&foodTexture);

	sf::Texture ecranTexture;							//textura fereastra
	ecranTexture.loadFromFile("4h.png");
	ecran.setTexture(&ecranTexture);

	window.setFramerateLimit(7);

	

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

		if (snake[0].getPosition().x > 600)								//daca iese inafara ecranului se teleporteaza la capatul opus
			snake[0].setPosition(0.0, snake[0].getPosition().y);

		if (snake[0].getPosition().x < 0)
			snake[0].setPosition(600, snake[0].getPosition().y);

		if (snake[0].getPosition().y > 600)
			snake[0].setPosition(snake[0].getPosition().x, 0);

		if (snake[0].getPosition().y < 0)
			snake[0].setPosition(snake[0].getPosition().x, 600);



		if (snake[0].getPosition().x == food.getPosition().x && snake[0].getPosition().y == food.getPosition().y) // daca are loc coleziunea dintre hrana si sarpe
		{
			food.setFillColor(sf::Color::Blue);
			snake[k] = food;
			k = k + 1;
			snake[k].setPosition(snake[k - 1].getPosition().x, snake[k - 1].getPosition().y);

			food.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));  // setez o culoare aleatorie hranei
			bx = rand() * 40 % 640;
			by = rand() * 40 % 640;
			for (j = 0; j < k; j++)
				while (snake[j].getPosition().x == bx && snake[j].getPosition().y == by)
				{
					bx = rand() * 40 % 640;
					by = rand() * 40 % 640;
				}
			food.setPosition(bx, by);
				
		}


		if (s == 'A')
		{

			for (i = k; i > 0; i--)
				snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
			snake[0].move(-40.0f, 0.0f);
		}
		if (s == 'D')
		{

			for (i = k; i > 0; i--)
				snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
			snake[0].move(40.0f, 0.0f);
		}
		if (s == 'W')
		{

			for (i = k; i > 0; i--)
				snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
			snake[0].move(0.0f, -40.0f);
		}
		if (s == 'S')
		{

			for (i = k; i > 0; i--)
				snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
			snake[0].move(0.0f, 40.0f);

		}




		if (s != 'D' && s != 'A')
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				for (i = k; i > 0; i--)
					snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
				snake[0].move(-40.0f, 0.0f);
				s = 'A';

			}
		if (s != 'D' && s != 'A')
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				for (i = k; i > 0; i--)
					snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
				snake[0].move(40.0f, 0.0f);
				s = 'D';
			}
		if (s != 'W' && s != 'S')
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				for (i = k; i > 0; i--)
					snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
				snake[0].move(0.0f, -40.0f);
				s = 'W';
			}
		if (s != 'S' && s != 'W')
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				for (i = k; i > 0; i--)
					snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y);
				snake[0].move(0.0f, 40.0f);
				s = 'S';
			}

		for (c = 1; c < k; c++)
			if (snake[0].getPosition().x == snake[c].getPosition().x && snake[0].getPosition().y == snake[c].getPosition().y)
			{
				sf::RenderWindow pierdut(sf::VideoMode(160, 150), "Ai piedut", sf::Style::Close | sf::Style::Resize);
				sf::RectangleShape lose(sf::Vector2f(160.0f, 150.0f));
				sf::Texture loseTexture;
				loseTexture.loadFromFile("5h.png");
				lose.setTexture(&loseTexture);

				while (pierdut.isOpen())
				{
					sf::Event evntt;

					while (pierdut.pollEvent(evntt))
					{
						switch (evntt.type)
						{
						case sf::Event::Closed:
						{
							pierdut.close();
							window.close();
						}
						}
					}

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						sf::Vector2i mousePos = sf::Mouse::getPosition(pierdut);
						if (mousePos.x > 100 && mousePos.y < 160)
						{
							pierdut.close();
							window.close();
						}
					}
					pierdut.clear();
					pierdut.draw(lose);
					pierdut.display();
				}
			}


		sf::Texture fsnakeTexture;							// textura player
		fsnakeTexture.loadFromFile("player1.png");

		for (j = 0; j < k; j++)			// colorez sarpele albastru;
			snake[j].setTexture(&fsnakeTexture);
		//std::cout << k << std::endl;
		window.clear();
		window.draw(ecran);
		window.draw(food);
		for (j = 0; j < k; j++)
		window.draw(snake[j]);
		window.display();
	}

	return 0;
}