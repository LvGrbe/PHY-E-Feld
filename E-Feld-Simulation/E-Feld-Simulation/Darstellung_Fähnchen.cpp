#include "Darstellung_Fähnchen.h"



Darstellung_Fähnchen::Darstellung_Fähnchen()
{
}

Darstellung_Fähnchen::Darstellung_Fähnchen(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen)
	: df_Window(Window),Teilchen_vec(teilchen)
{
}


Darstellung_Fähnchen::~Darstellung_Fähnchen()
{
}

void Darstellung_Fähnchen::Draw()
{
	
	sf::VertexArray line(sf::Lines, 2);
	line[0].position = InConvert::To_Screen(sf::Vector2f(0,0));
	line[1].position = (sf::Vector2f)sf::Mouse::getPosition(*df_Window);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	df_Window->draw(line);

	float angle = 0;
	angle = Physik::Winkel_zwischen_Vektor_Vektor(Physik::Elektrische_Feldstärke_Vektoren_Viele(InConvert::To_Sim((sf::Vector2f)sf::Mouse::getPosition(*df_Window)), Teilchen_vec), sf::Vector2f(0, 1));
	std::cout << "Winkel:  " << angle << std::endl;
	sf::Transform Rotation;
	Rotation.rotate(angle, sf::Mouse::getPosition(*df_Window).x, sf::Mouse::getPosition(*df_Window).y);
	df_Window->draw(Erstelle_Arrow(sf::Mouse::getPosition(*df_Window)), Rotation);

}

sf::VertexArray Darstellung_Fähnchen::Erstelle_Arrow(sf::Vector2i mouspos)
{

	sf::VertexArray Arrow(sf::LineStrip,9);
	Arrow[0].position = sf::Vector2f(mouspos.x, mouspos.y);
	Arrow[0].color = sf::Color::Black;
	Arrow[1].position = sf::Vector2f(mouspos.x-2, mouspos.y);
	Arrow[1].color = sf::Color::Black;
	Arrow[2].position = sf::Vector2f(mouspos.x-2, mouspos.y - 10);
	Arrow[2].color = sf::Color::Black;
	Arrow[3].position = sf::Vector2f(mouspos.x - 5, mouspos.y - 10);
	Arrow[3].color = sf::Color::Black;
	Arrow[4].position = sf::Vector2f(mouspos.x, mouspos.y - 20);
	Arrow[4].color = sf::Color::Black;
	Arrow[5].position = sf::Vector2f(mouspos.x + 5, mouspos.y - 10);
	Arrow[5].color = sf::Color::Black;
	Arrow[6].position = sf::Vector2f(mouspos.x + 2, mouspos.y - 10);
	Arrow[6].color = sf::Color::Black;
	Arrow[7].position = sf::Vector2f(mouspos.x + 2, mouspos.y);
	Arrow[7].color = sf::Color::Black;

	Arrow[8].position = sf::Vector2f(mouspos.x, mouspos.y);
	Arrow[8].color = sf::Color::Black;

	return Arrow;
}

