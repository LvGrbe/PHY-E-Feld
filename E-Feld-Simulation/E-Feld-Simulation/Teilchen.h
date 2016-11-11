#pragma once
#include <SFML\Graphics.hpp>
#include "Math_PH.h"

class Teilchen
{
public:
	Teilchen();
	~Teilchen();
	Physik_Value Ladung;
	sf::Vector2f pos;

};

