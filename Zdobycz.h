#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

enum TypZdobyczy{DEFAULT=0,OBRAZENIA, LECZENIE, NRTYPES};

class Zdobycz
{
private:
	sf::CircleShape ksztalt;
	int type;

	void initShape(const sf::RenderWindow& okno);

public:
	Zdobycz(const sf::RenderWindow& okno, int type);
	virtual ~Zdobycz();

	//accessor
	

	const sf::CircleShape getShape() const;
	const int& getType() const;
	//funkcje

	void update();
	void render(sf::RenderTarget& target);
};

