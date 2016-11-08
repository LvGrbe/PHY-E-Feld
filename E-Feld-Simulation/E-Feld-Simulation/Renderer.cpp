#include "Renderer.h"

//Dekelration des Smart_ptr zum Fenster
std::shared_ptr<sf::RenderWindow> Renderer::renderWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "E-Feld-Simulation"));

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}




// Window loop funktion
int Renderer::run()
{
	
	while (renderWindow->isOpen())
	{

		sf::Event event;
		while (renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderWindow->close();
		}

		renderWindow->clear();
		
		renderWindow->display();

	}

	return 0;
}

