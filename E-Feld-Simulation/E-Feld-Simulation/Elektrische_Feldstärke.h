#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Elektrische_Feldstärke
{
public:
	Elektrische_Feldstärke();
	~Elektrische_Feldstärke();

	sf::Vector2i pos_beginn;
	sf::Vector2i pos_ende;
	int Betrag;
};

