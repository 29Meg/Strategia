#include "Zdobycz.h"

void Zdobycz::initShape(const sf::RenderWindow& okno)
{
	this->ksztalt.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color kolor;
	switch (this->type)
	{
	case DEFAULT:
		kolor = sf::Color(rand() % 255 + 1, rand() % 255 + 1 , rand() % 255 + 1 );
		break;
	case OBRAZENIA:
		kolor = sf::Color::Yellow;
		this->ksztalt.setOutlineColor(sf::Color::Blue);
		this->ksztalt.setOutlineThickness(2.f);
		break;
	case LECZENIE:
		kolor = sf::Color::Magenta;
		this->ksztalt.setOutlineColor(sf::Color::White);
		this->ksztalt.setOutlineThickness(2.f);
		break;
	}

	this->ksztalt.setFillColor(kolor);
	this->ksztalt.setPosition(
		sf::Vector2f(
		static_cast<float>(rand()% okno.getSize().x - this->ksztalt.getGlobalBounds().width), 
		static_cast<float>(rand()% okno.getSize().y - this->ksztalt.getGlobalBounds().height)));
}

Zdobycz::Zdobycz(const sf::RenderWindow& okno, int type)
	:type(type)
{
	this->type = type;
	this->initShape(okno);

	
}

Zdobycz::~Zdobycz()
{

}

const sf::CircleShape Zdobycz::getShape() const
{
	return this-> ksztalt;
}

const int& Zdobycz::getType() const
{
	return this->type;
}

void Zdobycz::update()
{

}

void Zdobycz::render(sf::RenderTarget& target)
{
	target.draw(this->ksztalt);
}
