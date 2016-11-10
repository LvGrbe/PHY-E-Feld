#pragma once
#include <math.h>

#define e (1.6022f * (std::pow(10, -19)))
#define Elektrische_Feldkonstante (8.85418782 * (std::pow(10. -12)));
#define PI 3.141592653589

typedef Physik_Value long double

namespace Physik 
{
    /* Satz des Pytagoras */
    static Physik_Value distance(Physik_Value a, Physik_Value b)
    {
        return std::squart(std::pow(a, 2) + std::pow(b, 2));
    }

    static Physik_Value Coulomb_sches_gesetz(Physik_Value Ladung_1, Physik_Value Ladung_2, Physik_Value r)
    {
        return ( 1/(4 * PI * Elektrische_Feldkonstante ))*((Ladung_1 * Ladung_2) / r);
    }
	 
}