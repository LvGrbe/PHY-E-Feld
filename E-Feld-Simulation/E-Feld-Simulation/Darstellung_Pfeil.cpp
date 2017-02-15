#include "Darstellung_Pfeil.h"



Darstellung_Pfeil::Darstellung_Pfeil()
{
}

Darstellung_Pfeil::Darstellung_Pfeil(std::shared_ptr<sf::RenderWindow> Window,std::vector<Punktladung>* teilchen, sf::Text* text)
	: df_Window(Window),Teilchen_vec(teilchen),text(text)
{
}

Darstellung_Pfeil::~Darstellung_Pfeil()
{
}

void Darstellung_Pfeil::Draw()
{

	//Variablen
	float angle = 0;
	std::ostringstream oss;
	sf::Vector2f simkoords = InConvert::To_Sim((sf::Vector2f)sf::Mouse::getPosition(*df_Window));

	//Berechnungen
	sf::Vector2f Elektrische_Feldstärke = Physik::Elektrische_Feldstärke_Vektoren_Viele(InConvert::To_Sim((sf::Vector2f)sf::Mouse::getPosition(*df_Window)), Teilchen_vec);
	angle = Physik::Winkel_Vektor_Positiv_x_Achse(Elektrische_Feldstärke);

	//Einstellung Pfeil Rotation
	sf::Transform Rotation;
	Rotation.rotate(angle, sf::Mouse::getPosition(*df_Window).x, sf::Mouse::getPosition(*df_Window).y);
	
	//Text Einstellungen
	oss << "Die Elektrische Feldstärke am Punkt " <<  " " << simkoords.x << " " << simkoords.y  << " " << "betraegt" << " " << Physik::Länge_Vektor(Elektrische_Feldstärke);
	std::string var = oss.str();
	text->setString(var);
	text->setCharacterSize(12);
	text->setColor(sf::Color::Black);

	//Draw
	df_Window->draw(*text);
	df_Window->draw(Erstelle_Arrow(sf::Mouse::getPosition(*df_Window)), Rotation);
}

sf::VertexArray Darstellung_Pfeil::Erstelle_Arrow(sf::Vector2i mouspos)
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

