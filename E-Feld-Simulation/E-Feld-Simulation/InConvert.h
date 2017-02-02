#pragma once
#include <SFML\Graphics.hpp>
class InConvert
{
	
public:
	InConvert();
	~InConvert();
 
private:
	static float mXMAX, mXMIN, mSCAL, mYMAX, mYMIN;
	static sf::Vector2u Window_Size;
public:
	static void set(float xmax, float xmin, float scal, sf::Vector2u size);


	static sf::Vector2f To_Screen(sf::Vector2f pos);
	static float Get_X(float x);
	static float Get_Y(float y);
	
};

