#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Elektrische_Feldst�rke
{
public:
	Elektrische_Feldst�rke();
	~Elektrische_Feldst�rke();

	sf::Vector2i pos_beginn;
	sf::Vector2i pos_ende;
	int Betrag;
};

