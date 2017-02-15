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
    /* Satz des Pytagoras 
        a in m  
        b in m 
        return c in m
    */
    static Physik_Value distance(Physik_Value a, Physik_Value b)
    {
        return sqrt(pow(a, 2) + pow(b, 2));
    }

    /* Coulomb'sches Gesetz
        Ladung_1 & Ladung_2 in c
        r in m
    */
    static Physik_Value Coulomb_sches_gesetz(Physik_Value Ladung_1, Physik_Value Ladung_2, Physik_Value r)
    {
        return (( 1/(4 * M_PI * Elektrische_Feldkonstante ))*((Ladung_1 * Ladung_2) / r));
    }
	 
	static Physik_Value Elektrische_Feldst�rke_Allgemein(Physik_Value Kraft, Physik_Value Elektrische_Ladung)
	{
		return (Kraft / Elektrische_Ladung );
	}

	static Physik_Value Elektrische_Feldst�rke_Kondensator(Physik_Value Spannung, Physik_Value Abstand)
	{
		return (Spannung / Abstand);
	}

	
	static double L�nge_Vektor(sf::Vector2<double> a)
	{
		return sqrt(pow(a.x, 2) + pow(a.y, 2));
	}
	static double Winkel_Vektor_Positiv_x_Achse(sf::Vector2<double> a)
	{
		return atan2(a.x,a.y) * 180 / M_PI;
	}
	static sf::Vector2<double> Elektrische_Feldst�rke_Vektoren_Viele(sf::Vector2f punkt,std::vector<Punktladung>* Teilchen_vec)
	{
		sf::Vector2<double> Ergebniss;
		for (int i = 0; i < (*Teilchen_vec).size(); i++)
		{
			sf::Vector2<double> OrtsVec = (sf::Vector2<double>)punkt - (sf::Vector2<double>)(*Teilchen_vec)[i].pos;
			Ergebniss += ((*Teilchen_vec)[i].Q / (4 * M_PI * Elektrische_Feldkonstante * pow(Physik::L�nge_Vektor(OrtsVec), 3))) * OrtsVec;
		}

		return Ergebniss;
	}
	


}