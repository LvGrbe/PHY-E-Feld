#pragma once
#include <SFML\Graphics.hpp>
#include "Math_PH.h"

class Teilchen
{
public:
	Teilchen(Physik_Value Ladung, sf::Vector2i position);
	~Teilchen();

	Physik_Value Q;
	sf::Vector2i pos;
    
	sf::CircleShape Erstelle_Kreis_Ladung(Physik_Value Radius);
};

