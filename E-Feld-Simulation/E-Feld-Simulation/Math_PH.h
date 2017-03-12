#pragma once
#include <math.h>
#include "Punktladung.h"
#define e (1.6022f * (pow(10, -19)))
#define Elektrische_Feldkonstante (8.85418782 * (pow(10, -12)))
#define _USE_MATH_DEFINES // for C++  
#include <math.h>  

typedef long double Physik_Value;

namespace Physik 
{
		
	static float Länge_Vektor(sf::Vector2f a)
	{
		return sqrt(pow(a.x, 2) + pow(a.y, 2));
	}
	static float Winkel_Vektor_Positiv_x_Achse(sf::Vector2f a)
	{
		return atan2(a.x,a.y) * 180 / M_PI;
	}
	static sf::Vector2f Elektrische_Feldstärke_Vektoren_Viele(sf::Vector2f punkt,std::vector<Punktladung>* Teilchen_vec)
	{
		sf::Vector2f Ergebniss = sf::Vector2f(0,0);
		for (int i = 0; i < (*Teilchen_vec).size(); i++)
		{
			sf::Vector2f OrtsVec = punkt - (*Teilchen_vec)[i].pos;
			Ergebniss += (float)((*Teilchen_vec)[i].Q / (4 * M_PI * Elektrische_Feldkonstante * pow(Physik::Länge_Vektor(OrtsVec), 3))) * OrtsVec;
		}

		return Ergebniss;
	}

}