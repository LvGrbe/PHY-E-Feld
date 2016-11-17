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

			for (int t = 0; t < Teilchen_vec[i].vl_vec.size(); t++)
			{

				sf::Vertex line[] =
				{
					sf::Vertex(Teilchen_vec[i].vl_vec[t].pos1),
					sf::Vertex(Teilchen_vec[i].vl_vec[t].pos2)

				};
				line[0].color = sf::Color::Blue;
				line[1].color = sf::Color::Blue;
				sim_RenderWindow->draw(line, 2, sf::Lines);


			}

		}

	}

	



}

void Simulation::create_lines_Punktladung()
{

	for (int i = 0; i < Teilchen_vec.size(); i++)
	{
		Teilchen_vec[i].vl_vec.clear();
	}

	if (Teilchen_vec.size() >= 2)
	{
		int start = 0;

		for (int i = 1; i < Teilchen_vec.size(); i++)
		{
			auto vg = Verbindunglines();
			vg.pos1 = sf::Vector2f(Teilchen_vec[start].pos.x, Teilchen_vec[start].pos.y);
			vg.pos2 = sf::Vector2f(Teilchen_vec[i].pos.x, Teilchen_vec[i].pos.y);
			vg.color = sf::Color::Blue;

			Teilchen_vec[start].vl_vec.push_back(vg);
			Teilchen_vec[i].vl_vec.push_back(vg);
			start++;

		}

		auto vg = Verbindunglines();
		vg.pos1 = sf::Vector2f(Teilchen_vec[0].pos.x, Teilchen_vec[0].pos.y);
		vg.pos2 = sf::Vector2f(Teilchen_vec[Teilchen_vec.size() - 1].pos.x, Teilchen_vec[Teilchen_vec.size() - 1].pos.y);
		vg.color = sf::Color::Blue;

		Teilchen_vec[0].vl_vec.push_back(vg);
		Teilchen_vec[Teilchen_vec.size() - 1].vl_vec.push_back(vg);


	}


}



