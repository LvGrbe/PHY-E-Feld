#pragma once
#include <memory>
#include "Math_PH.h"
#include <iostream>
#include "Punktladung.h"
#include <SFML\Graphics.hpp>
#include "InConvert.h"

class Darstellung_Fähnchen
{
public:
	Darstellung_Fähnchen();
	Darstellung_Fähnchen(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen);
	~Darstellung_Fähnchen();
	std::vector<Punktladung>* Teilchen_vec;
	std::shared_ptr<sf::RenderWindow> df_Window;
	/*std::vector<Pfeil>* ladungen;*/
	float Länge_Vektor(sf::Vector2f a);
	sf::Vector2f Elektrische_Feldstärke_Vektoren_Viele(sf::Vector2f punkt);
	void Draw();
};

