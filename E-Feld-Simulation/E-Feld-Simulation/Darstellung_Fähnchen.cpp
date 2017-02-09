#include "Darstellung_F�hnchen.h"



Darstellung_F�hnchen::Darstellung_F�hnchen()
{
}

Darstellung_F�hnchen::Darstellung_F�hnchen(std::vector<Punktladung>* ladungen)
	: ladungen(ladungen)
{
}


Darstellung_F�hnchen::~Darstellung_F�hnchen()
{
}

float Darstellung_F�hnchen::L�nge_Vektor(sf::Vector2f a)
{

	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

sf::Vector2f Darstellung_F�hnchen::Elektrische_Feldst�rke_Vektoren_Viele(std::vector<Punktladung>* ladungen, sf::Vector2f punkt)
{
	sf::Vector2f Ergebniss;
	for (int i = 0; i < (*ladungen).size(); i++)
	{
		sf::Vector2f OrtsVec = punkt - (*ladungen)[i].pos;
		Ergebniss =+ (float)((*ladungen)[i].Q / (4 * PI * Elektrische_Feldkonstante * pow(L�nge_Vektor(OrtsVec), 3))) * OrtsVec;
	}
	
	return Ergebniss;
}

void Darstellung_F�hnchen::Draw()
{
	
			std::cout << "Punkt: " << "2" << " " << "2" << " Elektrische Feldst�rke: " << L�nge_Vektor(Elektrische_Feldst�rke_Vektoren_Viele(ladungen, sf::Vector2f(2, 2))) << std::endl;
		
}
