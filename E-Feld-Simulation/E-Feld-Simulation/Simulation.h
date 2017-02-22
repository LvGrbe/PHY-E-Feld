#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Darstellung_Feldlinien.h"
#include "Darstellung_Pfeil.h"

class Simulation
{
public:
	Simulation();
	Simulation(std::shared_ptr<sf::RenderWindow> Window);
	~Simulation();
	
	static std::vector<Punktladung> Teilchen_vec;
	static int aktuelle_Teilchen_zahl;
	void renderer_Teilchen();
	void Draw_Pfeil();
	void Draw_Feldlinin();
	sf::Font font;
	sf::Text *text;

	Darstellung_Pfeil df;
	Darstellung_Feldlinien dfl;

	static bool Draw_Pfeil_var;
	static bool Draw_Feldlinien_var;
	std::shared_ptr<sf::RenderWindow> sim_RenderWindow;

};

