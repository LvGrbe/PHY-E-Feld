#include "Renderer.h"

//Dekelration des Smart_ptr zum Fenster
std::shared_ptr<sf::RenderWindow> Renderer::renderWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "E-Feld-Simulation"));
GUI gui = GUI();

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
			GUI::gui_Desktop->HandleEvent(event);

			if (event.type == sf::Event::Closed)
				renderWindow->close();
			else if(event.type == sf::Event::Resized)
			{
				sf::View v = renderWindow->getView();				
				v.move(event.size.width , event.size.height );
				renderWindow->setView(v);
			}
		}

		GUI::gui_Desktop->Update(1.0f);

		renderWindow->clear();

		GUI::gui_sfgui.Display(*renderWindow);

		renderWindow->display();

		renderWindow->resetGLStates();
	}

	return 0;
}

