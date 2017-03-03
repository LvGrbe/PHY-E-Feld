#include "Darstellung_Feldlinien.h"

std::mutex mutex_Lines;


Darstellung_Feldlinien::Darstellung_Feldlinien()
{
}

Darstellung_Feldlinien::Darstellung_Feldlinien(std::shared_ptr<sf::RenderWindow> Window, std::vector<Punktladung>* teilchen)
	: dFl_RenderWindow(Window), Teilchen_vec(teilchen), m_Color(sf::Color(50, 205, 50))
{
}


Darstellung_Feldlinien::~Darstellung_Feldlinien()
{
}

void Darstellung_Feldlinien::Update()
{
	

	std::vector<std::thread> t;

	for (int i = 0; i != (*Teilchen_vec).size(); i++)
	{
		//efl = i;
		t.push_back(std::thread(&Darstellung_Feldlinien::thread_draw, this, std::ref(Teilchen_vec), i, 20));
	}
	for (int x = 0; x != (*Teilchen_vec).size(); x++)
	{

		t[x].join();
	}

}

void Darstellung_Feldlinien::Draw()
{
	for (int l = 0; l != (*Teilchen_vec).size(); l++)
	{
		for (int i = 0; i != (*Teilchen_vec)[l].Lines.size(); i++)
		{

			dFl_RenderWindow->draw((*Teilchen_vec)[l].Lines[i]);

		}
	}


}

void Darstellung_Feldlinien::thread_draw(std::vector<Punktladung>* Teilchenv,int teilchen, int anzahl_linien)
{
	(*Teilchenv)[teilchen].Lines.clear();
	int count = 0;

	for (int n = 0; n != anzahl_linien; n++)
	{
		int Winkel = 360 / anzahl_linien * n;
		sf::Vector2f Start_pos = (*Teilchenv)[teilchen].pos + sf::Vector2f(std::cos(Winkel * M_PI / 180), std::sin(Winkel * M_PI / 180)) * (InConvert::Get_X_On_Sim(5.f) - InConvert::Get_X_On_Sim(0));

		mutex_Lines.lock();
		(*Teilchen_vec)[teilchen].Lines.push_back(sf::VertexArray(sf::PrimitiveType::LineStrip));
		(*Teilchen_vec)[teilchen].Lines[count].append(sf::Vertex(InConvert::To_Screen(Start_pos), m_Color));

		bool ende = false;
		for (int s = 0; s != 3000 && (*Teilchen_vec)[teilchen].Q != 0 && !ende; s++)
		{
			
			auto t = Next_Pos(Start_pos, (*Teilchen_vec)[teilchen].Q > 0);
			(*Teilchen_vec)[teilchen].Lines[count].append(sf::Vertex(InConvert::To_Screen(t), m_Color));
			Start_pos = t;
			
			for (int T = 0; T != (*Teilchen_vec).size(); T++)
			{
				if ((*Teilchen_vec)[teilchen].OnPoint(Start_pos) && T != teilchen)
				{
					ende = true;
					break;
				}
			}

		}
		
		count++;
		mutex_Lines.unlock();
	}

}

sf::Vector2f Darstellung_Feldlinien::Next_Pos(sf::Vector2f pos, bool Positiv)
{
	sf::Vector2f Kraft_Vec = sf::Vector2f(0,0);
	
	Kraft_Vec = Physik::Elektrische_Feldstärke_Vektoren_Viele(pos, Teilchen_vec);

	if (!Positiv)
	{
		Kraft_Vec *= -1.f;
	}

	if (Kraft_Vec.x != 0 || Kraft_Vec.y != 0)
	{
		sf::Vector2f out = Kraft_Vec / (float)(std::sqrt(std::pow(Kraft_Vec.x, 2) + std::pow(Kraft_Vec.y, 2)));
		//out *= 0.01f;
		out *= InConvert::Get_X_On_Sim(1) - InConvert::Get_X_On_Sim(0);
		return pos + out;
	}
	else
		return pos + Kraft_Vec;
}
