#include "Darstellung_F�hnchen.h"



Darstellung_F�hnchen::Darstellung_F�hnchen()
{
}

Darstellung_F�hnchen::Darstellung_F�hnchen(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen)
	: df_Window(Window),Teilchen_vec(teilchen)
{
}


Darstellung_F�hnchen::~Darstellung_F�hnchen()
{
}

float Darstellung_F�hnchen::L�nge_Vektor(sf::Vector2f a)
{

	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

sf::Vector2f Darstellung_F�hnchen::Elektrische_Feldst�rke_Vektoren_Viele(sf::Vector2f punkt)
{
	sf::Vector2f Ergebniss;
	for (int i = 0; i < (*Teilchen_vec).size(); i++)
	{
		sf::Vector2f OrtsVec = punkt - (*Teilchen_vec)[i].pos;
		Ergebniss =+ (float)((*Teilchen_vec)[i].Q / (4 * PI * Elektrische_Feldkonstante * pow(L�nge_Vektor(OrtsVec), 3))) * OrtsVec;
	}
	
	return Ergebniss;
}

void Darstellung_F�hnchen::Draw()
{
	
			std::cout << "Punkt: " << "1" << " " << "0" << " Elektrische Feldst�rke: " << L�nge_Vektor(Elektrische_Feldst�rke_Vektoren_Viele(sf::Vector2f(1, 0))) << std::endl;
		
}
