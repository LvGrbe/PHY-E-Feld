#pragma once
#include "GUI.h"
#include "Punktladung.h"
#include "Simulation.h"
#include "InConvert.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <memory>
#include <Windows.h>
#include <Shobjidl.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	//Shared Pointer zum Fenster
	static std::shared_ptr<sf::RenderWindow> renderWindow;
	// Window loop funktion
	int run();
	//GUI Inisalisieren
    static GUI gui;	
	static Simulation sim;

	sf::Clock m_gui_Timer;
	
	void take_screenshot();
};

