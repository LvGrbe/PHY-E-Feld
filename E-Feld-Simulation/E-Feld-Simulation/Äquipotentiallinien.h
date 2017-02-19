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
	std::vector<sf::VertexArray> Lines;
	sf::Color m_Color;

	void Update();
	void Draw();
	sf::Vector2f NextPos�Linien(sf::Vector2f pos);
	sf::Vector2f Next_Pos(sf::Vector2f pos, bool Positiv);
};

