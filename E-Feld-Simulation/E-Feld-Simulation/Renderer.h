#pragma once
#include "Renderer.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>

class Renderer
{
public:
	Renderer();
	~Renderer();

	//Shared Pointer zum Fenster
	static std::shared_ptr<sf::RenderWindow> renderWindow;

	// Window loop funktion
	static int run();
	

	
};

