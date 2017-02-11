#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"


class Darstellung_Feldlinien
{
public:
	Darstellung_Feldlinien();
	Darstellung_Feldlinien(std::shared_ptr<sf::RenderWindow> Window, std::vector<Punktladung>* teilchen);
	~Darstellung_Feldlinien();

	std::vector<Punktladung>* Teilchen_vec;
	void Update();
	void Draw();

	sf::Color m_Color;

private:
	std::shared_ptr<sf::RenderWindow> dFl_RenderWindow;

	std::vector<sf::VertexArray> Lines;

	sf::Vector2f Next_Pos(sf::Vector2f pos,  bool Positiv);
};

