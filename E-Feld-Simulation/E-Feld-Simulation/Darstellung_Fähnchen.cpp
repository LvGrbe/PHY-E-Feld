#include "Darstellung_Fähnchen.h"



Darstellung_Fähnchen::Darstellung_Fähnchen()
{
}

Darstellung_Fähnchen::Darstellung_Fähnchen(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen)
	: df_Window(Window),Teilchen_vec(teilchen)
{
}


Darstellung_Fähnchen::~Darstellung_Fähnchen()
{
}

float Darstellung_Fähnchen::Länge_Vektor(sf::Vector2f a)
{

	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

sf::Vector2f Darstellung_Fähnchen::Elektrische_Feldstärke_Vektoren_Viele(sf::Vector2f punkt)
{
	sf::Vector2f Ergebniss;
	for (int i = 0; i < (*Teilchen_vec).size(); i++)
	{
		sf::Vector2f OrtsVec = punkt - (*Teilchen_vec)[i].pos;
		Ergebniss =+ (float)((*Teilchen_vec)[i].Q / (4 * PI * Elektrische_Feldkonstante * pow(Länge_Vektor(OrtsVec), 3))) * OrtsVec;
	}
	
	return Ergebniss;
}

void Darstellung_Fähnchen::Draw()
{
	
			std::cout << "Punkt: " << "1" << " " << "0" << " Elektrische Feldstärke: " << Länge_Vektor(Elektrische_Feldstärke_Vektoren_Viele(sf::Vector2f(1, 0))) << std::endl;
		
}
