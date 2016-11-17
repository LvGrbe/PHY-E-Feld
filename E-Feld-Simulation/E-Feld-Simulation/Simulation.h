#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Darstellung_Feldlinien.h"

class Simulation
{
public:
	Simulation();
	Simulation(std::shared_ptr<sf::RenderWindow> Window);
	~Simulation();

	static std::vector<Punktladung> Teilchen_vec;
	void renderer_Teilchen();
private:
	std::shared_ptr<sf::RenderWindow> sim_RenderWindow;

	

};

