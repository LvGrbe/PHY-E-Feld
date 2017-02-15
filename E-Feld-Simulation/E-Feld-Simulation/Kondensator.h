#pragma once
#include <SFML\Graphics.hpp>
#include "Punktladung.h"
#include "InConvert.h"
class Kondensator
{
public:
	Kondensator();
	~Kondensator();
	std::vector<Punktladung> Kondensatorplatte1;
	std::vector<Punktladung> Kondensatorplatte2;

	sf::Vector2f pos1;
	sf::Vector2f pos2;
};

