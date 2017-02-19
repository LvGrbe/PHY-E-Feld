#pragma once
#include <memory>
#include "Math_PH.h"
#include <iostream>
#include "Punktladung.h"
#include <SFML\Graphics.hpp>
#include "InConvert.h"
#include <string>
#include <sstream>

class �quipotentiallinien
{
public:
	�quipotentiallinien();
	�quipotentiallinien(std::shared_ptr<sf::RenderWindow> Window, std::vector<Punktladung>* teilchen);
	~�quipotentiallinien();

	std::vector<Punktladung>* Teilchen_vec;
	std::shared_ptr<sf::RenderWindow> dael_Window;

	void Update();
	void Draw();
};

