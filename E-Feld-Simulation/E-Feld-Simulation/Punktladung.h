#pragma once
#include <SFML\Graphics.hpp>

#include "Math_PH.h"
#include "InConvert.h"

class Punktladung
{
public:
	Punktladung(Physik_Value Ladung, sf::Vector2f position);
	~Punktladung();

	Physik_Value Q;
	sf::Vector2f pos;
	sf::Color col;
	sf::CircleShape Erstelle_Kreis_Ladung(Physik_Value Radius);
};

