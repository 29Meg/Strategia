#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class Gracz
{
private:
	
	sf::RectangleShape ksztalt;
	int hp;
	int hpMax;

	float movementSpeed;
	void niechZmiennePowstana();
	void initShape();

public:
	Gracz(float x = 0.f, float y = 0.f);
	virtual ~Gracz();
	
	


	//accesors
	const sf::RectangleShape& getShape() const;
	const int& getHp() const;
	const int& getHpMax() const;



	//funkcje
	void takeDamage(const int damage);
	void gainHealth(const int health);
	
	void updateInput();
	void updateWindowsBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};

