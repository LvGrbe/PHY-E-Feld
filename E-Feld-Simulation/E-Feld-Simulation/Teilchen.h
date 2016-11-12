#pragma once
#include <SFML\Graphics.hpp>
#include "Math_PH.h"

class Teilchen
{
public:
	Teilchen(Physik_Value Ladung, sf::Vector2f position);
	~Teilchen();

	Physik_Value Q;
	sf::Vector2f pos;
    
	sf::CircleShape Erstelle_Kreis_Ladung(Physik_Value Radius);
};

