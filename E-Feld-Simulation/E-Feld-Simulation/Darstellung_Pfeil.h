#pragma once
#include <memory>
#include "Math_PH.h"
#include <iostream>
#include "Punktladung.h"
#include <SFML\Graphics.hpp>
#include "InConvert.h"
#include <string>
#include <sstream>

class Darstellung_Pfeil
{
public:
	Darstellung_Pfeil();
	Darstellung_Pfeil(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen, sf::Text* text);
	~Darstellung_Pfeil();

	sf::Text* text;
	std::vector<Punktladung>* Teilchen_vec;
	std::shared_ptr<sf::RenderWindow> df_Window;
	void Draw();
	sf::VertexArray Erstelle_Arrow(sf::Vector2i mouspos);
};

