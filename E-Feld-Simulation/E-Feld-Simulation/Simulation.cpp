#include "Simulation.h"

std::vector<Punktladung> Simulation::Teilchen_vec = std::vector<Punktladung>();
bool Simulation::Draw_Pfeil_var = false;
bool Simulation::Draw_Feldlinien_var = false;

Simulation::Simulation()
{
	text = new sf::Text();
	if (!font.loadFromFile("Sanchezregular.otf"))
	{
	}
	text->setFont(font);
	df = Darstellung_Pfeil(sim_RenderWindow,&Teilchen_vec,text);
	dfl = Darstellung_Feldlinien(sim_RenderWindow,&Teilchen_vec);

}

Simulation::Simulation(std::shared_ptr<sf::RenderWindow> Window)
	: sim_RenderWindow(Window)
{
	text = new sf::Text();
	if (!font.loadFromFile("Sanchezregular.otf"))
	{
	}
	text->setFont(font);
	dfl = Darstellung_Feldlinien(sim_RenderWindow,&Teilchen_vec);
	df =  Darstellung_Pfeil(sim_RenderWindow,&Teilchen_vec, text);
	
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

		if (Teilchen_vec[i].Ausgewaehlt)
		{
			auto Kreis = sf::CircleShape(8.f);
			Kreis.setOutlineColor(sf::Color::Black);
			Kreis.setOutlineThickness(1.f);
			Kreis.setFillColor(sf::Color(0, 0, 0, 0));
			Kreis.setPosition(d.getPosition());
			Kreis.move(-3, -3);
			sim_RenderWindow->draw(Kreis);
		}


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

