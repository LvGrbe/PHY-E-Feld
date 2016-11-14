#include "Simulation.h"

std::vector<Teilchen> Simulation::Teilchen_vec = std::vector<Teilchen>();

Simulation::Simulation()
{
}

Simulation::Simulation(std::shared_ptr<sf::RenderWindow> Window)
{
	sim_RenderWindow = Window;
}


Simulation::~Simulation()
{
}

void Simulation::renderer_Teilchen()
{
	//Zeichen die Vektor Punkte 
	for (int i = 0; i < Teilchen_vec.size(); i++)
	{
		sim_RenderWindow->draw(Teilchen_vec[i].Erstelle_Kreis_Ladung(5.0));
	}



}


