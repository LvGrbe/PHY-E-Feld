#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "Math_PH.h"
#include "Punktladung.h"
#include <thread>

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

	void thread_draw(std::vector<Punktladung>* Teilchenv,int teilchen,int anzahl_linien,bool* inDraw);
	bool* inDraw;
private:
	std::shared_ptr<sf::RenderWindow> dFl_RenderWindow;
	sf::Vector2f Next_Pos(sf::Vector2f pos,  bool Positiv);
};

