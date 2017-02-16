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
    static Physik_Value Satz_des_Pytagoras(Physik_Value a, Physik_Value b)
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
	 
	static Physik_Value Elektrische_Feldstärke_Allgemein(Physik_Value Kraft, Physik_Value Elektrische_Ladung)
	{
		return (Kraft / Elektrische_Ladung );
	}

	static Physik_Value Elektrische_Feldstärke_Kondensator(Physik_Value Spannung, Physik_Value Abstand)
	{
		return (Spannung / Abstand);
	}

	
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
		sf::Vector2f Ergebniss;
		for (int i = 0; i < (*Teilchen_vec).size(); i++)
		{
			sf::Vector2f OrtsVec = punkt - (*Teilchen_vec)[i].pos;
			Ergebniss += (float)((*Teilchen_vec)[i].Q / (4 * M_PI * Elektrische_Feldkonstante * pow(Physik::Länge_Vektor(OrtsVec), 3))) * OrtsVec;
		}

		return Ergebniss;
	}
	static  double Integrieren_E(float obergrenze, float unteregrenze, double dx, sf::Vector2i p, std::vector<Punktladung>* Teilchen_vec, sf::Vector2f(*f)(sf::Vector2f p, std::vector<Punktladung>* Teilchen_vec))
	{
		if (unteregrenze > obergrenze)
		{
			float tmp = obergrenze; obergrenze = unteregrenze;  unteregrenze = tmp;
		}
		//Ungefähre ANzahl der Streifen könnte aber nicht passen deswegen nach berechnung
		int anzahlStreifen = (int)((obergrenze - unteregrenze) / dx);
		//Deshalb dx anpassen :
		dx = (obergrenze - unteregrenze) / anzahlStreifen;

		double Integral = 0.0;

		for (int i = 0; i < anzahlStreifen; i++)
		{
			/*Integral += (*f)((sf::Vector2f)p,Teilchen_vec)*dx;*/
		}

		return Integral;
	}

}