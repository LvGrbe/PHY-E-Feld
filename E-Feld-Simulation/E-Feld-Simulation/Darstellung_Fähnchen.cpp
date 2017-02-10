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

sf::Vector2f Darstellung_Fähnchen::Elektrische_Feldstärke_Vektoren_Viele(std::vector<Punktladung>* ladungen, sf::Vector2f punkt)
{
	sf::Vector2f Ergebniss;
	for (int i = 0; i < (*ladungen).size(); i++)
	{
		sf::Vector2f OrtsVec = punkt - (*ladungen)[i].pos;
		Ergebniss =+ (float)((*ladungen)[i].Q / (4 * PI * Elektrische_Feldkonstante * pow(Länge_Vektor(OrtsVec), 3))) * OrtsVec;
	}
	
	return Ergebniss;
}

void Darstellung_Fähnchen::Draw()
{
	
			std::cout << "Punkt: " << "2" << " " << "2" << " Elektrische Feldstärke: " << Länge_Vektor(Elektrische_Feldstärke_Vektoren_Viele(ladungen, sf::Vector2f(2, 2))) << std::endl;
		
}
