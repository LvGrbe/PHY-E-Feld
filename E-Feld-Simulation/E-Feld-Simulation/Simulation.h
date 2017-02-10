#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Darstellung_Feldlinien.h"
#include "Darstellung_Fähnchen.h"

class Simulation
{
public:
	Simulation();
	Simulation(std::shared_ptr<sf::RenderWindow> Window);
	~Simulation();

	Darstellung_Fähnchen df;
	Darstellung_Feldlinien Feldlinien;
	bool Draw_Fähnchen_var;
	bool Draw_Feldlinien_var;
	static std::vector<Punktladung> Teilchen_vec;
	void renderer_Teilchen();
	void Draw_Fähnchen();
	void Draw_Feldlinin();
	sf::Font font;
private:
	std::shared_ptr<sf::RenderWindow> sim_RenderWindow;

	

};

