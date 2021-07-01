#include "Gracz.h"
#include<iostream>

void Gracz::niechZmiennePowstana()
{
	this->movementSpeed = 5.f;
	this->hpMax = 20;
	this->hp = hpMax;

}

void Gracz::initShape()
{
	this->ksztalt.setFillColor(sf::Color::Green);
	this->ksztalt.setSize(sf::Vector2f(50.f, 50.f));
}

Gracz::Gracz(float x, float y)
{
	this->ksztalt.setPosition(x, y);

	this->niechZmiennePowstana();
	this->initShape();
}

Gracz::~Gracz()
{

}
//accessors
const sf::RectangleShape & Gracz::getShape() const
{
	return this->ksztalt;
}

const int& Gracz::getHp() const
{
	return this->hp;
}

const int& Gracz::getHpMax() const
{
	return this->hpMax;
}

//funkcje
void Gracz::takeDamage(const int damage)
{
	if (this->hp > 0)
		this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;

}

void Gracz::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;

	if (this->hp > this->hpMax)
		this->hp= this-> hpMax;
}


void Gracz::updateInput()
{


	// ruch gracza(przyciski klawiatury)

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->ksztalt.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->ksztalt.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->ksztalt.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->ksztalt.move(0.f, this->movementSpeed);
	}
}

void Gracz::updateWindowsBoundsCollision(const sf::RenderTarget* target)
{
	//lewo

	if (this->ksztalt.getGlobalBounds().left <= 0.f)
		this->ksztalt.setPosition(0.f, this->ksztalt.getGlobalBounds().top);
	//prawo
	 if (this->ksztalt.getGlobalBounds().left + this->ksztalt.getGlobalBounds().width >= target->getSize().x)
		this->ksztalt.setPosition(target->getSize().x - this->ksztalt.getGlobalBounds().width, this->ksztalt.getGlobalBounds().top);
	//góra
	if (this->ksztalt.getGlobalBounds().top <= 0.f)
		this->ksztalt.setPosition(this->ksztalt.getGlobalBounds().left, 0.f);
	//dół
	 if (this->ksztalt.getGlobalBounds().top + this->ksztalt.getGlobalBounds().height >= target->getSize().y)
		this->ksztalt.setPosition(this->ksztalt.getGlobalBounds().left, target->getSize().y - this->ksztalt.getGlobalBounds().height);
}




void Gracz::update(const sf::RenderTarget* target)
{
	


	this->updateInput();
	
	
	this->updateWindowsBoundsCollision(target);

}

void Gracz::render(sf::RenderTarget* target)
{
	target->draw(this->ksztalt);
}
