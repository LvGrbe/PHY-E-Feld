#pragma once
#include <SFML\Graphics.hpp>
#include "InConvert.h"
class Kondensator
{
public:
	Kondensator();
	~Kondensator();

	float d;
	float ladung;

	sf::Vector2f pos;
	sf::VertexArray line;

};

