#include "Simulation.h"

std::vector<Punktladung> Simulation::Teilchen_vec = std::vector<Punktladung>();
bool Simulation::Draw_Pfeil_var = false;
bool Simulation::Draw_Feldlinien_var = false;

Simulation::Simulation()
{

	df = Darstellung_Pfeil(sim_RenderWindow,&Teilchen_vec);
	dfl = Darstellung_Feldlinien(sim_RenderWindow,&Teilchen_vec);
	if (!font.loadFromFile("Sanchezregular.otf"))
	{
	}
}

Simulation::Simulation(std::shared_ptr<sf::RenderWindow> Window)
{
	sim_RenderWindow = Window;
	dfl = Darstellung_Feldlinien(sim_RenderWindow,&Teilchen_vec);
	df =  Darstellung_Pfeil(sim_RenderWindow,&Teilchen_vec);
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

void Simulation::Draw_Pfeil()
{
	df.Draw();
}

void Simulation::Draw_Feldlinin()
{
	dfl.Update();

	dfl.Draw();
}

