#pragma once
#include "GUI.h"
#include "Teilchen.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <memory>

class Renderer
{
public:
	Renderer();
	~Renderer();

	//Shared Pointer zum Fenster
	static std::shared_ptr<sf::RenderWindow> renderWindow;
	// Window loop funktion
	int run();
private:
	//GUI Inisalisieren
	static  GUI gui;

	std::vector<sf::VertexArray> grid(long x_max, long x_min, long x_scl, long y_max, long y_min, long y_scl);
	std::vector<sf::VertexArray> gridvar;
	long y_scl;
	long x_scl;
	

	
};

