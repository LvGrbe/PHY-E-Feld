#pragma once
#include <SFML\Graphics.hpp>
#include "Verbindunglines.h"
#include "Math_PH.h"

class Punktladung
{
public:
	Punktladung(Physik_Value Ladung, sf::Vector2i position);
	~Punktladung();

	Physik_Value Q;
	sf::Vector2i pos;

	std::vector<Verbindunglines> vl_vec;
	sf::CircleShape Erstelle_Kreis_Ladung(Physik_Value Radius);
};

