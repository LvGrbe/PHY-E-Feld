#include "InConvert.h"

float InConvert::mXMAX;
float InConvert::mXMIN;
float InConvert::mSCAL;
float InConvert::mYMAX;
float InConvert::mYMIN;
float InConvert::Pro_Fac;
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

	Pro_Fac = Get_X_On_Screen(1) - Get_X_On_Screen(0);


	mYMAX = ((float)Window_Size.y / 2.f) / Pro_Fac;
	mYMIN = ((float)Window_Size.y / 2.f) / Pro_Fac;
	mYMIN *= -1;
}

sf::Vector2f InConvert::To_Screen(sf::Vector2f pos)
{
	return sf::Vector2f(Get_X_On_Screen(pos.x), Get_Y_On_Screen(pos.y));
}

sf::Vector2f InConvert::To_Sim(sf::Vector2f pos)
{
	return sf::Vector2f(Get_X_On_Sim(pos.x), Get_Y_On_Sim(pos.y));
}

 float InConvert::Get_X_On_Screen(float x)
{
	float re = (((float)Window_Size.x) / (mXMAX - mXMIN)) * (x - mXMIN);
	return re;
}

 float InConvert::Get_Y_On_Screen(float y)
 {
	 float re = (float)Window_Size.y + ((0.f - (float)Window_Size.y) / (mYMAX - mYMIN)) * (y - mYMIN);
	 return re;
 }

 float InConvert::Get_X_On_Sim(float x)
 {
	 float re = mXMIN + (((mXMAX - mXMIN) / Window_Size.x) * x);
	 return re;
 }

 float InConvert::Get_Y_On_Sim(float y)
 {
	 float re = mYMAX + (((mYMIN - mYMAX) / Window_Size.y) * y);
	 return re;
 }
