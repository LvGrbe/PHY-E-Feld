#include "Punktladung.h"



Punktladung::Punktladung(double Ladung,sf::Vector2f position)
{
	Q = Ladung;
	pos = position;
	col = sf::Color::Blue;
}


Punktladung::~Punktladung()
{
}

sf::CircleShape Punktladung::Erstelle_Kreis_Ladung(double Radius)
{
	sf::CircleShape Kreis = sf::CircleShape();
	Kreis.setRadius(Radius);
	Kreis.setPosition(InConvert::To_Screen(sf::Vector2f(pos.x, pos.y)));
	Kreis.setOutlineThickness(1.);
	Kreis.setFillColor(col);

	return Kreis;
}
