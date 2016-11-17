#pragma once
#include <SFML\Graphics.hpp>
#include "Verbindungs_geraden.h"
#include "Math_PH.h"

class Punktladung
{
public:
	Punktladung(Physik_Value Ladung, sf::Vector2i position);
	~Punktladung();

	Physik_Value Q;
	sf::Vector2i pos;
	std::vector<Verbindungs_geraden> Vg_Vec;


	sf::CircleShape Erstelle_Kreis_Ladung(Physik_Value Radius);
};

