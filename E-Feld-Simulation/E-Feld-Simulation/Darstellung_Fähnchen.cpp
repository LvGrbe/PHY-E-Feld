#include "Darstellung_Fähnchen.h"



Darstellung_Fähnchen::Darstellung_Fähnchen()
{
}

Darstellung_Fähnchen::Darstellung_Fähnchen(std::vector<Punktladung>* ladungen)
	: ladungen(ladungen)
{
}


Darstellung_Fähnchen::~Darstellung_Fähnchen()
{
}

float Darstellung_Fähnchen::Länge_Vektor(sf::Vector2f a)
{

	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

sf::Vector2f Darstellung_Fähnchen::Elektrische_Feldstärke_Vektoren_Viele(std::vector<Punktladung>* ladungen, sf::Vector2f probeladung)
{
	sf::Vector2f a;
	for (int i = 0; i < (*ladungen).size(); i++)
	{
		a += (probeladung - (*ladungen)[i].pos) / (pow(Länge_Vektor(probeladung) - Länge_Vektor((*ladungen)[i].pos), 3));

	}

	return a / (float)(4 * PI * Elektrische_Feldkonstante);

}

void Darstellung_Fähnchen::Draw()
{
	for (int i = 0; i < 800; i++)
	{

		for (int y = 0; y < 600; y++)
		{

			std::cout << "Punkt: " << i << " " << y << " Elektrische Feldstärke: " << Länge_Vektor(Elektrische_Feldstärke_Vektoren_Viele(ladungen, sf::Vector2f(i, y))) << std::endl;
		}


	}
}
