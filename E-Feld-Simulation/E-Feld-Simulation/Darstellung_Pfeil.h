#pragma once
#include <memory>
#include "Math_PH.h"
#include <iostream>
#include "Punktladung.h"
#include <SFML\Graphics.hpp>
#include "InConvert.h"

class Darstellung_Pfeil
{
public:
	Darstellung_Pfeil();
	Darstellung_Pfeil(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen);
	~Darstellung_Pfeil();
	std::vector<Punktladung>* Teilchen_vec;
	std::shared_ptr<sf::RenderWindow> df_Window;
	void Draw();
	sf::VertexArray Erstelle_Arrow(sf::Vector2i mouspos);
};

