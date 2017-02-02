#include "InConvert.h"

float InConvert::mXMAX;
float InConvert::mXMIN;
float InConvert::mSCAL;
float InConvert::mYMAX;
float InConvert::mYMIN;
sf::Vector2u InConvert::Window_Size;

InConvert::InConvert()
{
}


InConvert::~InConvert()
{
}

void InConvert::set(float xmax, float xmin, float scal, sf::Vector2u size)
{
	mXMAX = xmax;
	mXMIN = xmin;
	mSCAL = scal;

	Window_Size = size;

	float Pro_Fac = Get_X(1) - Get_X(0);

	mYMAX = ((float)Window_Size.y / 2.f) / Pro_Fac;
	mYMIN = ((float)Window_Size.y / 2.f) / Pro_Fac;
	mYMIN *= -1;
}

sf::Vector2f InConvert::To_Screen(sf::Vector2f pos)
{
	return sf::Vector2f(Get_X(pos.x), Get_Y(pos.y));
}

 float InConvert::Get_X(float x)
{
	float re = (((float)Window_Size.x) / (mXMAX - mXMIN)) * (x - mXMIN);
	return re;
}

 float InConvert::Get_Y(float y)
 {
	 float re = (float)Window_Size.y + ((0.f - (float)Window_Size.y) / (mYMAX - mYMIN)) * (y - mYMIN);
	 return re;
 }
