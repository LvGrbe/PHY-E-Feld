#include "Renderer.h"

//Dekelration des Smart_ptr zum Fenster
std::shared_ptr<sf::RenderWindow> Renderer::renderWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "E-Feld-Simulation"));
Simulation Renderer::sim = Simulation(Renderer::renderWindow);
GUI Renderer::gui = GUI(Renderer::renderWindow, Renderer::sim);

Renderer::Renderer() : Feldlinien(Renderer::renderWindow)
{	

}

Renderer::~Renderer()
{

}


// Window loop funktion
int Renderer::run()
{    
	

	InConvert::set(renderWindow->getSize());
	//Grid
	gui.gridvar = gui.grid();
	
	while (renderWindow->isOpen())
	{

		sf::Event event;
		while (renderWindow->pollEvent(event))
		{
			gui.gui_Desktop->HandleEvent(event);

			if (event.type == sf::Event::Closed)
				renderWindow->close();
			else if (event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				renderWindow->setView(sf::View(visibleArea));

				InConvert::set(renderWindow->getSize());
				gui.gridvar = gui.grid();

			}
			
		}

		gui.gui_Desktop->Update(1.0f);
		Feldlinien.Update();

		renderWindow->clear(sf::Color::White);

		
		//Zeichne Grid
		for (int i = 0; i < gui.gridvar.size(); i++)
		{
			renderWindow->draw(gui.gridvar[i]);
		}

		//Zeichen Teilchen
		sim.renderer_Teilchen();
		
		Feldlinien.Draw();

		gui.gui_sfgui.Display(*renderWindow);


		renderWindow->display();

		renderWindow->resetGLStates();
	}

	return 0;
}


