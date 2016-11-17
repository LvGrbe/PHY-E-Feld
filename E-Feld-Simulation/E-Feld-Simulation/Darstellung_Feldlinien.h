#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"

class Darstellung_Feldlinien
{
public:
	Darstellung_Feldlinien();
	Darstellung_Feldlinien(std::shared_ptr<sf::RenderWindow> Window);
	~Darstellung_Feldlinien();



private:
	std::shared_ptr<sf::RenderWindow> dFl_RenderWindow;



};

