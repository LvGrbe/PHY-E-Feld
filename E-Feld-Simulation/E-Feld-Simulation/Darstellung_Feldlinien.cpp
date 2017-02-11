#include "Darstellung_Feldlinien.h"



Darstellung_Feldlinien::Darstellung_Feldlinien()
{
}

Darstellung_Feldlinien::Darstellung_Feldlinien(std::shared_ptr<sf::RenderWindow> Window, std::vector<Punktladung>* teilchen)
	: dFl_RenderWindow(Window), Teilchen_vec(teilchen), m_Color(sf::Color::Red)
{
}


Darstellung_Feldlinien::~Darstellung_Feldlinien()
{
}

void Darstellung_Feldlinien::Update()
{

	Lines.clear();

	int line_counter = 0;

	for (int i = 0; i != (*Teilchen_vec).size(); i++)
	{
		for (int n = 0; n != 10; n++)
		{
			int Winkel = 360 / 10 * n;
			sf::Vector2f Start_pos = (*Teilchen_vec)[i].pos + sf::Vector2f(std::cos(Winkel * PI / 180), std::sin(Winkel * PI / 180)) * (InConvert::Get_X_On_Sim(5.f) - InConvert::Get_X_On_Sim(0));

			Lines.push_back(sf::VertexArray(sf::PrimitiveType::LineStrip));
			Lines[line_counter].append(sf::Vertex(InConvert::To_Screen(Start_pos), m_Color));

			for (int s = 0; s != 100 && (*Teilchen_vec)[i].Q != 0 ; s++)
			{
				auto t = Next_Pos(Start_pos, (*Teilchen_vec)[i].Q > 0);
				Lines[line_counter].append(sf::Vertex(InConvert::To_Screen(t), m_Color));
				Start_pos = t;
			}

			line_counter++;
		}
	}


}

void Darstellung_Feldlinien::Draw()
{
	for (int i = 0; i != Lines.size(); i++)
	{

		dFl_RenderWindow->draw(Lines[i]);
		
	}

}

sf::Vector2f Darstellung_Feldlinien::Next_Pos(sf::Vector2f pos, bool Positiv)
{
	sf::Vector2f Kraft_Vec = sf::Vector2f(0,0);
	
	for (int i = 0; i != (*Teilchen_vec).size(); i++)
	{
		sf::Vector2f Richtung = (*Teilchen_vec)[i].pos - pos;
		
		float abstand = (float)(std::sqrt(std::pow(Richtung.x, 2) + std::pow(Richtung.y, 2)));

		Richtung /= abstand;
		
		if(Positiv)
			Richtung *= -1.f;

		// Voleufig
		float Kraft = 8987551785 * (1 * (*Teilchen_vec)[i].Q) / std::pow(abstand, 2);

		Kraft_Vec += Richtung * Kraft;
	}
	
	if (Kraft_Vec.x != 0 || Kraft_Vec.y != 0)
	{
		sf::Vector2f out = Kraft_Vec / (float)(std::sqrt(std::pow(Kraft_Vec.x, 2) + std::pow(Kraft_Vec.y, 2)));
		out *= 0.1f;
		return pos + out;
	}
	else
		return pos + Kraft_Vec;
}
