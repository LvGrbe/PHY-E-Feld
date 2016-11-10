#pragma once
#include <math.h>

#define e (1.6022f * (std::pow(10, -19)))
#define Elektrische_Feldkonstante (8.85418782 * (std::pow(10. -12)));
#define PI 3.141592653589

typedef Physik_Value long double

namespace Physik 
{
    /* Satz des Pytagoras 
        a in m  
        b in m 
        return c in m
    */
    static Physik_Value distance(Physik_Value a, Physik_Value b)
    {
        return std::squart(pow(a, 2) + pow(b, 2));
    }

    /* Coulomb'sches Gesetz
        Ladung_1 & Ladung_2 in c
        r in m
    */
    static Physik_Value Coulomb_sches_gesetz(Physik_Value Ladung_1, Physik_Value Ladung_2, Physik_Value r)
    {
        return ( 1/(4 * PI * Elektrische_Feldkonstante ))*((Ladung_1 * Ladung_2) / r);
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
		return (Ladung / 4 * PI * Elektrische_Feldkonstante * pow(r, 2));
	}

}