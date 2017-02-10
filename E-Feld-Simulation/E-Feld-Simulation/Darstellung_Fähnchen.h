#pragma once
#include <memory>
#include "Math_PH.h"
#include <iostream>
#include "Punktladung.h"
#include <SFML\Graphics.hpp>
#include "InConvert.h"

class Darstellung_F�hnchen
{
public:
	Darstellung_F�hnchen();
	Darstellung_F�hnchen(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen);
	~Darstellung_F�hnchen();
	std::vector<Punktladung>* Teilchen_vec;
	std::shared_ptr<sf::RenderWindow> df_Window;
	/*std::vector<Pfeil>* ladungen;*/
	float L�nge_Vektor(sf::Vector2f a);
	sf::Vector2f Elektrische_Feldst�rke_Vektoren_Viele(sf::Vector2f punkt);
	void Draw();
};

