#pragma once
#include <SFML\Graphics.hpp>
class InConvert
{
	
public:
	InConvert();
	~InConvert();
 
private:
	
	static sf::Vector2u Window_Size;
public:
	static void set(float xmax, float xmin, float scalx, float scaly, sf::Vector2u size);

	static float mXMAX, mXMIN, mSCALX,mSCALY, mYMAX, mYMIN,Pro_Fac;
	static sf::Vector2f To_Screen(sf::Vector2f pos);
	static sf::Vector2f To_Sim(sf::Vector2f pos);

	// Zu Fenster Kordinaten
	static float Get_X_On_Screen(float x);
	static float Get_Y_On_Screen(float y);
	
	// Zu Simmulations Kordinaten
	static float Get_X_On_Sim(float x);
	static float Get_Y_On_Sim(float y);
};

