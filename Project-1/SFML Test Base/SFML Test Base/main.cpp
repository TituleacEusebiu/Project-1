#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
	
	sf::RenderWindow meniu(sf::VideoMode(450, 540), "Menu", sf::Style::Close);
	sf::RectangleShape menu(sf::Vector2f(450.0f, 540.0f));
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
			if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 466 && mousePos.y < 540)
			{
				meniu.close();
				return EXIT_SUCCESS;
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(meniu);
			if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 193 && mousePos.y < 293)
			{
				meniu.close();
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
				sf::Vector2i mousePos = sf::Mouse::getPosition(meniu);
				if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 293 && mousePos.y < 376)
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


				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(meniu);
					if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 376 && mousePos.y < 466)
					{
						sf::RenderWindow score(sf::VideoMode(450, 204), "Menu", sf::Style::Close);
						sf::RectangleShape scoree(sf::Vector2f(450.0f, 204.0f));
						sf::Texture scoreTexture;
						scoreTexture.loadFromFile("score.png");
						scoree.setTexture(&scoreTexture);

						while (score.isOpen())
						{
							sf::Event evt;

							while (score.pollEvent(evt))
							{
								switch (evt.type)
								{
								case sf::Event::Closed:
								{
									score.close();
									break;
								}
								}
							}

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								sf::Vector2i mousePos = sf::Mouse::getPosition(score);
								if (mousePos.x > 0 && mousePos.x < 450 && mousePos.y > 146 && mousePos.y < 204)
								{
									std::fstream scored;
									std::ofstream("score.txt");
									scored.open("score.txt", std::ios::out);
									scored << 0;
									scored.close();
								}
							}
							int c = 0;
							std::fstream scored;
							std::ifstream("score.txt");
							scored >> c;
							scored.close();

							std::string hello;
							hello = c;

							sf::Text text;
							text.setCharacterSize(20);
							text.setPosition(280, 45);
							text.setFillColor(sf::Color::Blue);
							
							score.clear();
							score.draw(scoree);
							score.draw(text);
							score.display();
						}
					}
				}

		}
		meniu.clear();
		meniu.draw(menu);
		meniu.display();
	}


	
	float ax, ay, bx, by;
	ax = rand() * 40 % 640;
	ay = rand() * 40 % 640;
	bx = rand() * 40 % 640;
	by = rand() * 40 % 640;

	char s = 'X';


	sf::RenderWindow window(sf::VideoMode(640, 640), "Snake", sf::Style::Close);
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

	window.setFramerateLimit(30);

	sf::RectangleShape az;
alala:
	int i = 1, j = 0, c = 1, k = 1;
	sf::RectangleShape snake[256];
	for (c = 0; c < 255; c++)
		snake[c] = az;
	snake[0] = player;

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event evnt;
		sf::Time elapsed = clock.getElapsedTime();
		sf::Time reload = sf::milliseconds(100);
		if (elapsed >= reload)
		{
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
						int g;
						std::fstream score;
						score.open("score.txt");
						score >> g;
						score.close();
						if (g < k * 10)
							g = k * 10;
							std::cout << g << "   " << k * 10 << std:: endl;

						std::ofstream("score.txt");
						score.open("score.txt", std::ios::out);
						score << g;
						score.close();

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
								goto alala;
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
			clock.restart();
		}
	}
	return 0;
}