#include "Renderer.h"

//Dekelration des Smart_ptr zum Fenster
std::shared_ptr<sf::RenderWindow> Renderer::renderWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "E-Feld-Simulation"));
GUI gui = GUI(Renderer::renderWindow);

Renderer::Renderer()
{
	sim = Simulation(Renderer::renderWindow);

}

Renderer::~Renderer()
{

}


// Window loop funktion
int Renderer::run()
{    
	x_scl = 50.;
	y_scl = 50.;
	gridvar = grid(renderWindow->getSize().x, 0., x_scl, renderWindow->getSize().y, 0., y_scl);

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

				gridvar = grid(renderWindow->getSize().x, 0., x_scl, renderWindow->getSize().y, 0., y_scl);

			}
			
		}

		gui.gui_Desktop->Update(1.0f);


		renderWindow->clear(sf::Color::White);

		
		//Zeichne Grid
		for (int i = 0; i < gridvar.size(); i++)
		{
			renderWindow->draw(gridvar[i]);
		}

		//Zeichen Teilchen
		sim.create_lines_Punktladung();
		sim.renderer_Teilchen();
		
		gui.gui_sfgui.Display(*renderWindow);

		renderWindow->display();

		renderWindow->resetGLStates();
	}

	return 0;
}



std::vector<sf::VertexArray> Renderer::grid(long x_max,long x_min,long x_scl, long y_max, long y_min,long y_scl)
{
	std::vector<sf::VertexArray> vec_vertex;
	std::vector<sf::Vector2f> vec_Vec2f_hl;
	std::vector<sf::Vector2f> vec_Vec2f_vr;

	//Horizontale Linien
	for (long i = x_min; i < x_max; i+=x_scl)
	{
		for (long j = y_min; j <= y_max; j++)
		{
		
			auto point = sf::Vector2f(i, j);
			vec_Vec2f_hl.push_back(point);

			if (vec_Vec2f_hl.size() > 2 && j == y_max)
			{
				sf::VertexArray line(sf::Lines, 2);
				line[0] = vec_Vec2f_hl[0];
				line[1] = vec_Vec2f_hl[y_max];
				line[0].color = sf::Color::Black;
				line[1].color = sf::Color::Black;

				vec_vertex.push_back(line);
				vec_Vec2f_hl.clear();
			}

		}

	}

	//Vetikale Linien
	for (long i = y_min; i < y_max; i+=y_scl)
	{

		for (long j = x_min; j < x_max; j++)
		{

			auto point = sf::Vector2f(j, i);
			vec_Vec2f_vr.push_back(point);

			if (vec_Vec2f_vr.size() == x_max)
			{
				sf::VertexArray line(sf::Lines, 2);
				line[0] = vec_Vec2f_vr[0];
				line[1] = vec_Vec2f_vr[x_max-1];
				line[0].color = sf::Color::Black;
				line[1].color = sf::Color::Black;

				vec_vertex.push_back(line);
				vec_Vec2f_vr.clear();
			}

		}

	}


	return vec_vertex;


}

