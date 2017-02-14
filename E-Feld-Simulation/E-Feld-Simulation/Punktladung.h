#pragma once
#include <SFML\Graphics.hpp>
#include "InConvert.h"

class Punktladung
{
public:
	Punktladung(double Ladung, sf::Vector2f position);
	~Punktladung();

	double Q;
	sf::Vector2f pos;
	sf::Color col;
	sf::CircleShape Erstelle_Kreis_Ladung(double Radius);
};

