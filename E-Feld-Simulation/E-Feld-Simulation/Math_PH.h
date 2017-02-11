#pragma once
#include <math.h>
#include "Punktladung.h"
#define e (1.6022f * (pow(10, -19)))
#define Elektrische_Feldkonstante (8.85418782 * (pow(10, -12)))
#define PI 3.141592654

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
        return (( 1/(4 * PI * Elektrische_Feldkonstante ))*((Ladung_1 * Ladung_2) / r));
    }
	 
	static Physik_Value Elektrische_Feldstärke_Allgemein(Physik_Value Kraft, Physik_Value Elektrische_Ladung)
	{
		return (Kraft / Elektrische_Ladung );
	}

	static Physik_Value Elektrische_Feldstärke_Kondensator(Physik_Value Spannung, Physik_Value Abstand)
	{
		return (Spannung / Abstand);
	}

	static Physik_Value Elektrische_Feldstärke_Abstand_r_von_Punktladung_Vakuum(Physik_Value Ladung, Physik_Value r)
	{
		return (Ladung / (4 * PI * Elektrische_Feldkonstante * pow(r, 2)));
	}
	static float Länge_Vektor(sf::Vector2f a)
	{
		return sqrt(pow(a.x, 2) + pow(a.y, 2));
	}
	static float Skalarprodukt(sf::Vector2f a, sf::Vector2f b)
	{
		return (a.x * b.x + a.y * b.y);
	}
	static sf::Vector2f Elektrische_Feldstärke_Vektoren_Viele(sf::Vector2f punkt,std::vector<Punktladung>* Teilchen_vec)
	{
		sf::Vector2f Ergebniss;
		for (int i = 0; i < (*Teilchen_vec).size(); i++)
		{
			sf::Vector2f OrtsVec = punkt - (*Teilchen_vec)[i].pos;
			Ergebniss += (float)((*Teilchen_vec)[i].Q / (4 * PI * Elektrische_Feldkonstante * pow(Physik::Länge_Vektor(OrtsVec), 3))) * OrtsVec;
		}

		return Ergebniss;
	}
	


}