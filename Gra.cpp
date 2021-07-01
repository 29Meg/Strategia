#include "Gra.h"

void Gra::niechOknoPowstanie()
{
	this->tvideo = sf::VideoMode(800, 600);
	this->okno = new  sf::RenderWindow(this->tvideo, "PROJEKT_PSIO_GRA", sf::Style::Close | sf::Style::Titlebar);
	this->okno->setFramerateLimit(60);
}

void Gra::niechZmiennePowstana()
{
	this->koniecGry = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxZdobycz = 10;

	this-> punkty=0;
}

void Gra::niechCzcionkaPowstanie()
{
	if(!this->czcionka.loadFromFile("Font/Fifth-Grader.ttf"))
	{
		std::cout << "COULD NOT LOAD Fifth-Grader.ttf" << "\n";
	}
}

void Gra::niechTekstPowstanie()
{
	//gui text init
	this->guiText.setFont(this->czcionka);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(60);

	//koniec gry tekst
	this->koniecGryTekst.setFont(this->czcionka);
	this->koniecGryTekst.setFillColor(sf::Color::Red);
	this->koniecGryTekst.setCharacterSize(100);
	this->koniecGryTekst.setPosition(sf::Vector2f(20, 300));
	this->koniecGryTekst.setString("	   KONIEC GRY ");

}

//konstruktory i destruk
Gra::Gra()
{
	this->niechOknoPowstanie();
	this->niechZmiennePowstana();
	this->niechCzcionkaPowstanie();
	this->niechTekstPowstanie();

}

Gra::~Gra()
{
	delete this->okno;
}

const bool& Gra::zakonczGre() const
{
	return this->koniecGry;
}

const bool Gra::running() const
{
	return this->okno->isOpen() ;
}

//funkcje

void Gra::pollEvents()
{
	while (this->okno->pollEvent(this->wydarzenie))
	{
		switch (this->wydarzenie.type)
		{
		case sf::Event::Closed:
			this->okno->close();
			break;
		case sf::Event::KeyPressed:
			if (this->wydarzenie.key.code == sf::Keyboard::Escape)
				this->okno->close();
			break;
		}
	}
}


void Gra::spawnZdobycz()
{
	//timer
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->zdobycz.size() < this->maxZdobycz)
		{
			this->zdobycz.push_back(Zdobycz(*this->okno, this->typKulkiRand()));
			this->spawnTimer = 0.f;
		}
		
	}
}

const int Gra::typKulkiRand() const
{
	int type = TypZdobyczy::DEFAULT;
	int randValue = rand() % 100 + 1;

	if (randValue > 60 && randValue <= 80)
		type = TypZdobyczy::OBRAZENIA;
	else if (randValue > 80 && randValue <= 100)
		type = TypZdobyczy::LECZENIE;

	return type;
}

void Gra::updateGracz()
{
	this->gracz.update(this->okno);

	if (this->gracz.getHp() <= 0)
		this->koniecGry = true;
}

void Gra::kolizjaUpdate()
{
	
	for (size_t i = 0; i < this->zdobycz.size(); i++)
	{
		if (this->gracz.getShape().getGlobalBounds().intersects(this->zdobycz[i].getShape().getGlobalBounds()))
		{
			switch (this->zdobycz[i].getType())
			{
			case TypZdobyczy::DEFAULT:
				this->punkty++;
				break;
			case TypZdobyczy::OBRAZENIA:
				this->gracz.takeDamage(5);
				break;
			case TypZdobyczy::LECZENIE:
				this->gracz.gainHealth(3);
				break;
			}

			//usun zdobycz
			this->zdobycz.erase(this->zdobycz.begin() + i);
		
		}
	}
	
}

void Gra::updateGui()
{
	std::stringstream ss;
	ss << " PUNKTY "<<this->punkty<<"\n"
			<< " Zycie " << this->gracz.getHp() << " I " << this->gracz.getHpMax()<< "\n" ;

	this->guiText.setString(ss.str());
}

void Gra::update()
{
	this->pollEvents();
	if (this->koniecGry == false)
	{
	
	this->spawnZdobycz();
	this->updateGracz();
	this->kolizjaUpdate();
	this->updateGui();
	}
}


void Gra::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}


void Gra::render()
{
	this->okno->clear();
	//render 
	this->gracz.render(this->okno);
	for (auto i : this->zdobycz)
	{
		i.render(*this->okno);
	}

	//render (gui)
	this->renderGui(this->okno);

	//render i tekst 
	if (this->koniecGry == true)
		this->okno->draw(this->koniecGryTekst);

	this->okno->display();

}
