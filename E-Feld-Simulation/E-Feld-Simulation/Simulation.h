#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Darstellung_Feldlinien.h"
#include "Darstellung_F�hnchen.h"

class Simulation
{
public:
	Simulation();
	Simulation(std::shared_ptr<sf::RenderWindow> Window);
	~Simulation();

	Darstellung_F�hnchen df;
	Darstellung_Feldlinien Feldlinien;
	bool Draw_F�hnchen_var;
	bool Draw_Feldlinien_var;
	static std::vector<Punktladung> Teilchen_vec;
	void renderer_Teilchen();
	void Draw_F�hnchen();
	void Draw_Feldlinin();
	sf::Font font;
private:
	std::shared_ptr<sf::RenderWindow> sim_RenderWindow;

	

};

