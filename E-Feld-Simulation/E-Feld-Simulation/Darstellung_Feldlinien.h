#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include <thread>
#include <mutex>

class Darstellung_Feldlinien
{
public:
	Darstellung_Feldlinien();
	Darstellung_Feldlinien(std::shared_ptr<sf::RenderWindow> Window, std::vector<Punktladung>* teilchen);
	~Darstellung_Feldlinien();

	std::vector<Punktladung>* Teilchen_vec;
	void Update();
	void Draw();

	int anzahl_Feldlinien;
	sf::Color m_Color;

	std::mutex mutex_Lines_vec;
	std::mutex mutex_Line_count;
	std::vector<sf::VertexArray> Lines;
	int line_counter;

private:
	std::shared_ptr<sf::RenderWindow> dFl_RenderWindow;
	sf::Vector2f Next_Pos(sf::Vector2f pos,  bool Positiv);
};

