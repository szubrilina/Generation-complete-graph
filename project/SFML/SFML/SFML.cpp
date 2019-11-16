#define _CRT_SECURE_NO_WARNINGS
#include<SFML/Graphics.hpp> 
#include<iostream> 
#include <Windows.h>
#include<fstream> 

using namespace std;
using namespace sf;

vector<int>fer3(15, 0);
vector<int>fer4(153, 0);

vector<pair<int, int>>rebro3(15);
vector<pair<int, int>>fershina3(6);

vector<pair<int, int>>fershina4(18);
vector<pair<int, int>>rebro4(153);

int fl = 0;
void color1()
{
	long long per = 1;
	for (int i = fer3.size() - 1; i >= 0; --i)
	{
		fer3[i] += per;
		per = 0;
		if (fer3[i] == 2)
		{
			fer3[i] = 0;
			per = 1;
		}
		if (per == 0)
			break;

	}
}

void color2()
{
	for (int i = fer4.size() - 1; i >= 0; --i)
	{
		int a = rand();
		if (a % 2 == 0)
			fer4[i] = 1;
		else
			fer4[i] = 0;
	}
}

void wait()
{
	while (true)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
			return;
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			fl = 1;
			break;
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	RenderWindow window(VideoMode(1200, 800), "sfmltest", Style::Close);
	sf::VertexArray lines(sf::Lines, 2);

	fershina3[0] = make_pair(210, 65);
	fershina3[1] = make_pair(410, 250);
	fershina3[2] = make_pair(410, 450);
	fershina3[3] = make_pair(210, 650);
	fershina3[4] = make_pair(15, 250);
	fershina3[5] = make_pair(15, 450);

	for (int i = 0; i < 6; ++i)
	{
		CircleShape shape(10);
		shape.setFillColor(sf::Color(250, 250, 250));
		shape.setPosition(fershina3[i].first - 8, fershina3[i].second - 8);
		window.draw(shape);
		window.display();
	}

	for (int i = 1; i <= 5; ++i)
		rebro3[i - 1] = make_pair(0, i);

	for (int i = 2; i <= 5; ++i)
		rebro3[i + 3] = make_pair(1, i);

	for (int i = 3; i <= 5; ++i)
		rebro3[i + 6] = make_pair(2, i);

	for (int i = 4; i <= 5; ++i)
		rebro3[i + 8] = make_pair(3, i);

	rebro3[14] = make_pair(4, 5);





	///////////////////////////////////////////////граф от R(4, 4);


	long long ch_reb = 0;
	for (int i = 0; i < 18; ++i)
	for (int j = i + 1; j < 18; ++j)
	{
		rebro4[ch_reb] = make_pair(i, j);
		++ch_reb;
	}

	//до 300
	long long ch = 0, y1 = 310, x1 = 460;
	for (int i = 0; i < 18; ++i)
	{
		if (ch <= 2)
		{
			fershina4[i] = make_pair(x1, y1);
			if (ch != 2)
			{
				x1 += 50;
				y1 -= 130;
			}
		}
		if (ch >= 3 && ch <= 5)
		{
			x1 += 130;
			fershina4[i] = make_pair(x1, y1);

		}
		if (ch == 6)
		{
			x1 += 130;
			fershina4[i] = make_pair(x1, y1);
		}
		if (ch >= 7 && ch <= 8)
		{
			x1 += 50;
			y1 += 130;
			fershina4[i] = make_pair(x1, y1);
		}
		if (ch == 9)
		{
			y1 += 130;
			fershina4[i] = make_pair(x1, y1);
		}
		if (ch >= 10 && ch <= 11)
		{
			y1 += 130;
			x1 -= 50;
			fershina4[i] = make_pair(x1, y1);
		}
		if (ch >= 12 && ch <= 14)
		{
			x1 -= 130;
			fershina4[i] = make_pair(x1, y1);
		}
		if (ch == 15)
		{
			x1 -= 130;
			fershina4[i] = make_pair(x1, y1);
		}
		if (ch >= 16 && ch <= 17)
		{
			y1 -= 130;
			x1 -= 50;
			fershina4[i] = make_pair(x1, y1);
		}
		++ch;
		CircleShape shape(10);
		shape.setFillColor(sf::Color(250, 250, 250));
		shape.setPosition(fershina4[i].first - 8, fershina4[i].second - 8);
		window.draw(shape);
		window.display();
	}


	long long ch_help = 0;
	while (window.isOpen())
	{
		while (true)
		{
			VertexArray lines(sf::Lines, 2);

			Font font;
			font.loadFromFile("sansation.ttf");

			sf::Text text("R(3, 3) = 6", font);
			text.setCharacterSize(40);
			text.setStyle(sf::Text::Bold);
			text.setColor(sf::Color::Blue);
			text.move(10, 10);
			window.draw(text);


			sf::Text text1("R(4, 4) = 18", font);
			text1.setCharacterSize(40);
			text1.setStyle(sf::Text::Bold);
			text1.setColor(sf::Color::Cyan);
			text1.move(340, 10);
			window.draw(text1);

			for (int i = 0; i < 6; ++i)
			{
				CircleShape shape(10);
				shape.setFillColor(sf::Color(250, 250, 250));
				shape.setPosition(fershina3[i].first - 8, fershina3[i].second - 8);
				window.draw(shape);
			}

			for (int i = 0; i < 18; ++i)
			{
				CircleShape shape(10);
				shape.setFillColor(sf::Color(250, 250, 250));
				shape.setPosition(fershina4[i].first - 8, fershina4[i].second - 8);
				window.draw(shape);
			}

			color1();
			for (int i = 0; i < 15; ++i)
			{

				lines[0].position = Vector2f(fershina3[rebro3[i].first].first, fershina3[rebro3[i].first].second);
				lines[1].position = Vector2f(fershina3[rebro3[i].second].first, fershina3[rebro3[i].second].second);

				if (fer3[i] == 0)
				{
					lines[0].color = Color::Red;
					lines[1].color = Color::Red;
				}
				else
				{
					lines[0].color = Color::Blue;
					lines[1].color = Color::Blue;
				}
				window.draw(lines);
			}
			color2();
			for (int i = 0; i < 153; ++i)
			{

				lines[0].position = Vector2f(fershina4[rebro4[i].first].first, fershina4[rebro4[i].first].second);
				lines[1].position = Vector2f(fershina4[rebro4[i].second].first, fershina4[rebro4[i].second].second);

				if (fer4[i] == 0)
				{
					lines[0].color = Color::Magenta;
					lines[1].color = Color::Magenta;
				}
				else
				{
					lines[0].color = Color::Cyan;
					lines[1].color = Color::Cyan;
				}
				window.draw(lines);
			}
			window.display();

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				wait();
			}
			Sleep(300);
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				wait();
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) || fl == 1)
			{
				window.close();
				return 0;
			}
			Sleep(400);
			window.clear();
			window.display();
			Sleep(50);

		}
		window.display();


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}
	return 0;
}
