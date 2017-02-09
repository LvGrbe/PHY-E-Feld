#pragma once
#include "Math_PH.h"
#include <iostream>
#include "Punktladung.h"
#include <SFML\Graphics.hpp>

class Darstellung_F�hnchen
{
public:
	Darstellung_F�hnchen();
	Darstellung_F�hnchen(std::vector<Punktladung>* ladungen);
	~Darstellung_F�hnchen();
	std::vector<Punktladung>* ladungen;
	float L�nge_Vektor(sf::Vector2f a);
	sf::Vector2f Elektrische_Feldst�rke_Vektoren_Viele(std::vector<Punktladung>* ladungen, sf::Vector2f probeladung);
	void Draw();
};

