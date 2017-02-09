#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Simulation.h"

class Darstellung_Feldlinien
{
public:
	Darstellung_Feldlinien();
	Darstellung_Feldlinien(std::shared_ptr<sf::RenderWindow> Window);
	~Darstellung_Feldlinien();

	void Update();
	void Draw();


private:
	std::shared_ptr<sf::RenderWindow> dFl_RenderWindow;

	std::vector<sf::VertexArray> Lines;

	sf::Vector2f Next_Pos(sf::Vector2f pos,  bool Positiv);
};

