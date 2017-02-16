#include "Punktladung.h"



Punktladung::Punktladung(double Ladung,sf::Vector2f position) : Ausgewaehlt(false)
{
	Q = Ladung;
	pos = position;
	col = sf::Color::Blue;
}


Punktladung::~Punktladung()
{
}

bool Punktladung::OnPoint(sf::Vector2f pos_in)
{
	sf::Vector2f Dis = pos - pos_in;
	
	float Laenge = sqrt(pow(Dis.x, 2) + pow(Dis.y, 2));

	return Laenge < (InConvert::Get_X_On_Sim(5.f) - InConvert::Get_X_On_Sim(0.f));
}

sf::CircleShape Punktladung::Erstelle_Kreis_Ladung(double Radius)
{
	sf::CircleShape Kreis = sf::CircleShape();
	Kreis.setRadius(Radius);
	Kreis.setPosition(InConvert::To_Screen(sf::Vector2f(pos.x, pos.y)));
	Kreis.setOutlineThickness(1.);
	if (Q > 0)
	{
		Kreis.setFillColor(sf::Color::Red);
	}
	else if (Q < 0) {
		Kreis.setFillColor(sf::Color::Blue);
	}
	else
	{
		Kreis.setFillColor(sf::Color::White);
		Kreis.setOutlineColor(sf::Color::Black);
	}
	

	return Kreis;
}
