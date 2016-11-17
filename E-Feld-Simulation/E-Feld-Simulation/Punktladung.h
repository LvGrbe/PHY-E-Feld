#pragma once
#include <SFML\Graphics.hpp>

#include "Math_PH.h"

class Punktladung
{
public:
	Punktladung(Physik_Value Ladung, sf::Vector2i position);
	~Punktladung();

	Physik_Value Q;
	sf::Vector2i pos;


	sf::CircleShape Erstelle_Kreis_Ladung(Physik_Value Radius);
};

