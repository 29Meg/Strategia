#pragma once

#include <iostream>

#include <ctime>
#include "Gracz.h"
#include "Zdobycz.h"
#include<vector>
#include <sstream>

class Gra
{

private:
	sf::VideoMode tvideo;
	sf::RenderWindow* okno;
	bool koniecGry;
	sf::Event wydarzenie;

	Gracz gracz;
	int punkty;

	sf::Font czcionka;
	sf::Text guiText;
	sf::Text koniecGryTekst;

	std::vector<Zdobycz> zdobycz;
	float spawnTimerMax;
	float spawnTimer;
	int maxZdobycz;

	

	void niechZmiennePowstana();
	void niechCzcionkaPowstanie();
	void niechTekstPowstanie();
	void niechOknoPowstanie();
public:

	Gra();
	~Gra();

	//accessors
	const bool& zakonczGre() const;


	//funkcje
	const bool running() const;
	void pollEvents();
	void spawnZdobycz();
	const int  typKulkiRand()const ;
	void updateGracz();
	void kolizjaUpdate();
	void updateGui();
	
	void update();
	void renderGui(sf::RenderTarget* target);
	void render();

};
