#pragma once
#include <SFML\Graphics.hpp>
#include "InConvert.h"


class Punktladung
{
public:
	Punktladung(double Ladung, sf::Vector2f position);
	~Punktladung();

	bool OnPoint(sf::Vector2f pos_in);

	double Q;
	sf::Vector2f pos;
	sf::Color col;
	sf::CircleShape Erstelle_Kreis_Ladung(double Radius);

	bool Ausgewaehlt;
};

