#include "Teilchen.h"



Teilchen::Teilchen(Physik_Value Ladung,sf::Vector2i position)
{
	Q = Ladung;
	pos = position;
}


Teilchen::~Teilchen()
{
}

sf::CircleShape Teilchen::Erstelle_Kreis_Ladung(Physik_Value Radius)
{
	sf::CircleShape Kreis = sf::CircleShape();
	Kreis.setRadius(Radius);
	Kreis.setPosition(pos.x,pos.y);
	Kreis.setOutlineThickness(1.);
	Kreis.setFillColor(sf::Color::Yellow);

	return Kreis;
}
