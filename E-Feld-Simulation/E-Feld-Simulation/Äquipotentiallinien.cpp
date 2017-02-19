#include "Äquipotentiallinien.h"



Äquipotentiallinien::Äquipotentiallinien()
{
}

Äquipotentiallinien::Äquipotentiallinien(std::shared_ptr<sf::RenderWindow> Window, std::vector<Punktladung>* teilchen)
	: dael_Window(Window), Teilchen_vec(teilchen)
{
	m_Color = sf::Color::Green;
}

Äquipotentiallinien::~Äquipotentiallinien()
{
}

void Äquipotentiallinien::Update()
{
	Lines.clear();

	for (int i = 0; i != (*Teilchen_vec).size(); i++)
	{

		int Winkel = 360 / 6 * 1;
		sf::Vector2f Start_pos = (*Teilchen_vec)[i].pos + sf::Vector2f(std::cos(Winkel * M_PI / 180), std::sin(Winkel * M_PI / 180)) * (InConvert::Get_X_On_Sim(5.f) - InConvert::Get_X_On_Sim(0));

		auto t = Next_Pos(Start_pos, (*Teilchen_vec)[i].Q > 0);
		t = Next_Pos(t, (*Teilchen_vec)[i].Q > 0);
		t = Next_Pos(t, (*Teilchen_vec)[i].Q > 0);

		auto endPunkt = t;
		//Start der Äquipotentiallinie von t aus

	

	}

}

sf::Vector2f Äquipotentiallinien::NextPosÄLinien(sf::Vector2f pos)
{
	auto d = Physik::Potenzial_Viele((sf::Vector2f)pos, Teilchen_vec);
	

	//Am Ort
	auto eg = Physik::Potenzial_Viele((sf::Vector2f)pos, Teilchen_vec);
	if (eg == d)
	{
		return pos;
	}




	return sf::Vector2f(0, 0);
}

void Äquipotentiallinien::Draw()
{
	for (int i = 0; i != Lines.size(); i++)
	{

		dael_Window->draw(Lines[i]);

	}
	
}

sf::Vector2f Äquipotentiallinien::Next_Pos(sf::Vector2f pos, bool Positiv)
{
	sf::Vector2f Kraft_Vec = sf::Vector2f(0, 0);

	Kraft_Vec = Physik::Elektrische_Feldstärke_Vektoren_Viele(pos, Teilchen_vec);

	if (!Positiv)
	{
		Kraft_Vec *= -1.f;
	}

	if (Kraft_Vec.x != 0 || Kraft_Vec.y != 0)
	{
		sf::Vector2f out = Kraft_Vec / (float)(std::sqrt(std::pow(Kraft_Vec.x, 2) + std::pow(Kraft_Vec.y, 2)));
		out *= 0.01f;
		return pos + out;
	}
	else
		return pos + Kraft_Vec;
}