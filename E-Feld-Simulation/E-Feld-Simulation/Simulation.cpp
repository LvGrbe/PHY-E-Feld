#include "Simulation.h"

std::vector<Punktladung> Simulation::Teilchen_vec = std::vector<Punktladung>();

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
		
		if (Teilchen_vec.size() >= 2)
		{
			for (int t = 0; t < Teilchen_vec[i].Vg_Vec.size(); t++)
			{

				sf::Vertex line[] =
				{
					sf::Vertex(Teilchen_vec[i].Vg_Vec[t].pos1),
					sf::Vertex(Teilchen_vec[i].Vg_Vec[t].pos2)
					
				};
				line[0].color = sf::Color::Blue;
				line[1].color = sf::Color::Blue;

				sim_RenderWindow->draw(line, 2, sf::Lines);
			}

		}

		

	}

}

void Simulation::create_VerbindungsGeraden_Teilchen()
{

	if (Teilchen_vec.size() >= 2)
	{

		for (int i = 0; i < Teilchen_vec.size(); i++)
		{
			if (Teilchen_vec.size() > Teilchen_vec[i].Vg_Vec.size())
			{

				for (int t = 0; t < Teilchen_vec.size(); t++)
				{
					auto vg = Verbindungs_geraden();
					vg.pos1 = sf::Vector2f(Teilchen_vec[i].pos.x, Teilchen_vec[i].pos.y);
					vg.pos2 = sf::Vector2f(Teilchen_vec[t].pos.x, Teilchen_vec[t].pos.y);
					vg.color = sf::Color::Blue;

					Teilchen_vec[i].Vg_Vec.push_back(vg);
					Teilchen_vec[t].Vg_Vec.push_back(vg);
				}

			}

		}


	}
}


