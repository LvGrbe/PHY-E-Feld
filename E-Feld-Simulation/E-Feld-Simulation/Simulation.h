#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Elektrische_Feldstärke.h"
#include "Darstellung_Feldlinien.h"
#include "Darstellung_Fähnchen.h"

class Simulation
{
public:
	Simulation();
	Simulation(std::shared_ptr<sf::RenderWindow> Window);
	~Simulation();

	static std::vector<Punktladung> Teilchen_vec;
	static std::vector<std::vector<Elektrische_Feldstärke>> EFeld_vec;
	void renderer_Teilchen();

	long y_scl;
	long x_scl;
private:
	std::shared_ptr<sf::RenderWindow> sim_RenderWindow;

	

};

