#include "Simulation.h"

std::vector<Punktladung> Simulation::Teilchen_vec = std::vector<Punktladung>();

Simulation::Simulation()
{
	
}

Simulation::Simulation(std::shared_ptr<sf::RenderWindow> Window)
{
	sim_RenderWindow = Window;
	df =  Darstellung_Fähnchen(&Teilchen_vec);
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

