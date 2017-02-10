#pragma once
#include "Math_PH.h"
#include <iostream>
#include "Punktladung.h"
#include <SFML\Graphics.hpp>
#include "InConvert.h"

class Darstellung_Fähnchen
{
public:
	Darstellung_Fähnchen();
	Darstellung_Fähnchen(std::vector<Punktladung>* ladungen);
	~Darstellung_Fähnchen();
	std::vector<Punktladung>* ladungen;
	/*std::vector<Pfeil>* ladungen;*/
	float Länge_Vektor(sf::Vector2f a);
	sf::Vector2f Elektrische_Feldstärke_Vektoren_Viele(std::vector<Punktladung>* ladungen, sf::Vector2f punkt);
	void Draw();
};

