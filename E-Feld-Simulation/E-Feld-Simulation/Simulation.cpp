#include "Simulation.h"

std::vector<Punktladung> Simulation::Teilchen_vec = std::vector<Punktladung>();

Simulation::Simulation()
{
	Draw_Feldlinien_var = false;
	Draw_Fähnchen_var = false;
	df = Darstellung_Fähnchen(&Teilchen_vec);
	Feldlinien = Darstellung_Feldlinien(sim_RenderWindow);
	if (!font.loadFromFile("Sanchezregular.otf"))
	{
	}
}

Simulation::Simulation(std::shared_ptr<sf::RenderWindow> Window)
{
	Draw_Feldlinien_var = false;
	Draw_Fähnchen_var = false;
	sim_RenderWindow = Window;
	Feldlinien = Darstellung_Feldlinien(sim_RenderWindow);
	df =  Darstellung_Fähnchen(&Teilchen_vec);
	if (!font.loadFromFile("Sanchezregular.otf"))
	{
	}
}


Simulation::~Simulation()
{
}

void Simulation::renderer_Teilchen()
{
	//Zeichen die Vektor Punkte 
	for (int i = 0; i < Teilchen_vec.size(); i++)
	{
		auto d = Teilchen_vec[i].Erstelle_Kreis_Ladung(5.0);
		d.move(sf::Vector2f(-5, -5));
		sim_RenderWindow->draw(d);	

	}


}

void Simulation::Draw_Fähnchen()
{
	df.Draw();
}

void Simulation::Draw_Feldlinin()
{
	Feldlinien.Update();

	Feldlinien.Draw();
}

