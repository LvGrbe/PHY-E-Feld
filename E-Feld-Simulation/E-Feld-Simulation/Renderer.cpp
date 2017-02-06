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
	long x_scl = 50.;
	long y_scl = 50.;

	InConvert::set(renderWindow->getSize());
	
	//Grid
	gridvar = grid();
	
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
				gridvar = grid();

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
		sim.renderer_Teilchen();
		
		gui.gui_sfgui.Display(*renderWindow);

		renderWindow->display();

		renderWindow->resetGLStates();
	}

	return 0;
}



std::vector<sf::VertexArray> Renderer::grid()
{
	std::vector<sf::VertexArray> vec_vertex;

	sf::VertexArray  vec_Vec2f_X_A(sf::Lines, 2);
	sf::VertexArray  vec_Vec2f_Y_A(sf::Lines, 2);
	std::vector<sf::Vector2f> vec_Vec2f_X_Scal_A;
	std::vector<sf::Vector2f> vec_Vec2f_Y_Scal_A;

	
	    vec_Vec2f_X_A[0] = sf::Vector2f(InConvert::Get_X_On_Screen(InConvert::mXMAX),InConvert::Get_Y_On_Screen(0));
	    vec_Vec2f_X_A[1] = sf::Vector2f(InConvert::Get_X_On_Screen(InConvert::mXMIN),InConvert::Get_Y_On_Screen(0));
		vec_Vec2f_X_A[0].color = sf::Color::Black;
		vec_Vec2f_X_A[1].color = sf::Color::Black;

		vec_Vec2f_Y_A[0] = sf::Vector2f(InConvert::Get_X_On_Screen(0), InConvert::Get_Y_On_Screen(InConvert::mYMAX));
		vec_Vec2f_Y_A[1] = sf::Vector2f(InConvert::Get_X_On_Screen(0), InConvert::Get_Y_On_Screen(InConvert::mYMIN));
		vec_Vec2f_Y_A[0].color = sf::Color::Black;
		vec_Vec2f_Y_A[1].color = sf::Color::Black;

		vec_vertex.push_back(vec_Vec2f_Y_A);
		vec_vertex.push_back(vec_Vec2f_X_A);

		for (int i = InConvert::mXMIN; i < InConvert::mXMAX; i += InConvert::mSCALX)
		{

			sf::VertexArray line(sf::Lines, 2);
			line[0] = sf::Vector2f(InConvert::Get_X_On_Screen(i), InConvert::Get_Y_On_Screen(0.2));
			line[1] = sf::Vector2f(InConvert::Get_X_On_Screen(i), InConvert::Get_Y_On_Screen(-0.2));
			line[0].color = sf::Color::Black;
			line[1].color = sf::Color::Black;

			vec_vertex.push_back(line);

		}

		for (int i = InConvert::mYMIN; i < InConvert::mYMAX; i += InConvert::mSCALY)
		{

			sf::VertexArray line(sf::Lines, 2);
			line[0] = sf::Vector2f(InConvert::Get_X_On_Screen(-0.2), InConvert::Get_Y_On_Screen(i));
			line[1] = sf::Vector2f(InConvert::Get_X_On_Screen(0.2), InConvert::Get_Y_On_Screen(i));
			line[0].color = sf::Color::Black;
			line[1].color = sf::Color::Black;

			vec_vertex.push_back(line);


		}


	return vec_vertex;

}


