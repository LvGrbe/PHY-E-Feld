#pragma once
#include <SFML\Graphics.hpp>
#include "Math_PH.h"
#include "Teilchen.h"
#include <memory>

class Simulation
{
public:
	Simulation();
	Simulation(std::shared_ptr<sf::RenderWindow> Window);
	~Simulation();

	static std::vector<Teilchen> Teilchen_vec;
	void renderer_Teilchen();
private:
	std::shared_ptr<sf::RenderWindow> sim_RenderWindow;

	

};

