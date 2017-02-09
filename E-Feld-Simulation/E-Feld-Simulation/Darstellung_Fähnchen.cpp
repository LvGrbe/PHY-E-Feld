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

sf::Vector2f Darstellung_F�hnchen::Elektrische_Feldst�rke_Vektoren_Viele(std::vector<Punktladung>* ladungen, sf::Vector2f probeladung)
{
	sf::Vector2f a;
	for (int i = 0; i < (*ladungen).size(); i++)
	{
		a += (probeladung - (*ladungen)[i].pos) / (pow(L�nge_Vektor(probeladung) - L�nge_Vektor((*ladungen)[i].pos), 3));

	}

	return a / (float)(4 * PI * Elektrische_Feldkonstante);

}

void Darstellung_F�hnchen::Draw()
{
	for (int i = 0; i < 800; i++)
	{

		for (int y = 0; y < 600; y++)
		{

			std::cout << "Punkt: " << i << " " << y << " Elektrische Feldst�rke: " << L�nge_Vektor(Elektrische_Feldst�rke_Vektoren_Viele(ladungen, sf::Vector2f(i, y))) << std::endl;
		}


	}
}
