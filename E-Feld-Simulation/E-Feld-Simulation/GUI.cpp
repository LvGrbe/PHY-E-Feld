#include "GUI.h"

//Erstelle die Statischen Elemente
sfg::SFGUI GUI::gui_sfgui = sfg::SFGUI();
std::shared_ptr<sfg::Desktop> GUI::gui_Desktop = std::make_shared<sfg::Desktop>(sfg::Desktop());

GUI::GUI(std::shared_ptr<sf::RenderWindow> Window,Simulation sim)
{   
	last_auswahl = 0;
	gui_RenderWindow = Window;
	sim = sim;

//---------------------------------------------------------------------------
	//Window
	//Erstellung der Elemente
	gui_Window = sfg::Window::Create();
	gui_Box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_button_erstelle = sfg::Button::Create();
	gui_scale = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	gui_scale_Label = sfg::Label::Create("Ladung : 0");

	//Init Einstellung
	gui_Window->SetTitle("Werkzeug-Box");

	//Set Einstellung Range
	gui_scale->SetRequisition(sf::Vector2f(80.f, 20.f));
	gui_adjustment = gui_scale->GetAdjustment();
	gui_adjustment->SetUpper(e * 8);
	gui_adjustment->SetLower(-e * 8);
	gui_adjustment->SetMajorStep(e);
	gui_adjustment->SetMinorStep(e);
	gui_adjustment->GetSignal(sfg::Adjustment::OnChange).Connect(std::bind(&GUI::AdjustmentChange, this));

	//Set Einstellung Button
	gui_button_erstelle->SetLabel("Erstelle");
	gui_button_erstelle->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Button_Erstelle_Click, this));

	//Einstellung scalebox
	gui_scalebox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	gui_scalebox->Pack(gui_scale, false, false);

	//PackBox for Window
	gui_Box->SetSpacing(5.f);
	gui_Box->Pack(gui_scale_Label);
	gui_Box->Pack(gui_scalebox);
	gui_Box->Pack(gui_button_erstelle);
	gui_Box->Pack(sfg::Separator::Create());
	
	//F�ge die Letzten Teile zusammen
	gui_Window->Add(GUI::gui_Box);
	gui_Desktop->Add(GUI::gui_Window);
	
 //-----------------------------------------------------------------------

	//Window2
	gui_Window2 = sfg::Window::Create();
	gui_Box2_vertical = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_Box2_horizontal2 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_Box2_horizontal = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
	gui_comboBox = sfg::ComboBox::Create();
	gui_button_alles_l�schen = sfg::Button::Create();
	gui_button_l�schen = sfg::Button::Create();
	gui_button_Set = sfg::Button::Create();
	gui_Entry_pos_x = sfg::Entry::Create();
	gui_Entry_pos_y = sfg::Entry::Create();
	gui_Entry_Ladung = sfg::Entry::Create();

	//Init
	gui_Window2->SetTitle("Auswahl Ladungen");
	gui_Window2->SetPosition(sf::Vector2f(0,140));
	gui_button_alles_l�schen->SetLabel("L�sch alles");
	gui_button_l�schen->SetLabel("L�sche auswahl");
	gui_button_Set->SetLabel("Set");
	gui_Entry_Ladung->SetText("Ladung");
	gui_Entry_pos_x->SetText("x:");
	gui_Entry_pos_y->SetText("y:");
	//Set Signale
	gui_comboBox->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&GUI::ComboAuswahl,this));
	gui_button_alles_l�schen->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::AllesL�schen, this));
	gui_button_l�schen->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::AuswahlL�schen, this));
	gui_button_Set->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Set, this));
	//Erstellen
	gui_Window2->Add(GUI::gui_Box2_vertical);
	gui_Box2_horizontal->Pack(GUI::gui_comboBox);
	//gui_Box2_horizontal->Pack(GUI::gui_button_l�schen); F�gt den Button  zum auswahl L�schen hinzu
	gui_Box2_horizontal->Pack(GUI::gui_button_alles_l�schen);
	gui_Box2_horizontal2->Pack(gui_Entry_pos_x);
	gui_Box2_horizontal2->Pack(gui_Entry_pos_y);
	gui_Box2_horizontal2->Pack(gui_Entry_Ladung);
	gui_Box2_horizontal2->Pack(gui_button_Set);
	gui_Box2_vertical->Pack(GUI::gui_Box2_horizontal);
	gui_Box2_vertical->Pack(sfg::Separator::Create());
	gui_Box2_vertical->Pack(GUI::gui_Box2_horizontal2);
	gui_Desktop->Add(GUI::gui_Window2);

	//-----------------------------------------------------------

	//Window 3
	gui_Window3 = sfg::Window::Create();
	gui_Box3_vertical = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_Box3_horizontal2 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	//gui_Box3_horizontal3 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_Box3_horizontal = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
	gui_button_l�schen2 = sfg::Button::Create();
	gui_button_Set2 = sfg::Button::Create();
	gui_Entry_pos_x_min = sfg::Entry::Create();
	gui_Entry_pos_x_max = sfg::Entry::Create();
	gui_Entry_pos_x_scl = sfg::Entry::Create();
	gui_Entry_pos_y_scl = sfg::Entry::Create();
	//Ini
	gui_Window3->SetTitle("Einstellung Fenster");
	gui_Window3->SetPosition(sf::Vector2f(0, 400));
	gui_button_l�schen2->SetLabel("L�sche Eingaben");
	gui_button_Set2->SetLabel("Set");
	gui_Entry_pos_x_min->SetText("x_min:");
	gui_Entry_pos_x_max->SetText("x_max:");
	gui_Entry_pos_x_scl->SetText("x_scl:");
	gui_Entry_pos_y_scl->SetText("y_scl:");
	//Signal window3
	gui_button_l�schen2->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Reset_E, this));
	gui_button_Set2->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Set_E, this));

	//Set Layout Einstellung
	gui_Window3->Add(gui_Box3_vertical);
	gui_Box3_vertical->Pack(gui_Box3_horizontal);
	gui_Box3_vertical->Pack(gui_Box3_horizontal2);
	gui_Box3_horizontal->Pack(gui_Entry_pos_x_max);
	gui_Box3_horizontal->Pack(gui_Entry_pos_x_min);
	gui_Box3_horizontal->Pack(gui_Entry_pos_x_scl);
	gui_Box3_horizontal->Pack(gui_Entry_pos_y_scl);
	gui_Box3_vertical->SetSpacing(5.);
	gui_Box3_vertical->Pack(gui_Box3_horizontal2);
	gui_Box3_horizontal2->Pack(gui_button_Set2);
	gui_Box3_horizontal2->Pack(gui_button_l�schen2);
	gui_Desktop->Add(gui_Window3);
    
	//
	//Window 4
	gui_Window4 = sfg::Window::Create();
	gui_Box4 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
	gui_button_d_Pfeil = sfg::Button::Create();
	gui_button_d_Linien = sfg::Button::Create();
	gui_button_d_Reset = sfg::Button::Create();
	gui_Window4->SetTitle("Darstellung");
	gui_Window4->SetPosition(sf::Vector2f(200, 400));
	gui_button_d_Pfeil->SetLabel("Pfeil");
	gui_button_d_Linien->SetLabel("Linien");
	gui_button_d_Reset->SetLabel("Keine");
	//Signals
	gui_button_d_Pfeil->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Darstellung_Feld_Set, this));
	gui_button_d_Linien->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Darstellung_Feld_Linien, this));
	gui_button_d_Reset->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Darstellung_Keine, this));

	gui_Window4->Add(gui_Box4);
	gui_Box4->Pack(gui_button_d_Pfeil);
	gui_Box4->Pack(gui_button_d_Linien);
	gui_Box4->Pack(gui_button_d_Reset);
	gui_Desktop->Add(gui_Window4);
}

GUI::GUI()
{
}

GUI::~GUI()
{
}


bool GUI::Point_On_Window(sf::Vector2i pos)
{
	if (gui_Window->GetAllocation().contains(sf::Vector2f(pos)))
		return true;
	else if (gui_Window2->GetAllocation().contains(sf::Vector2f(pos)))
		return true;
	else if (gui_Window3->GetAllocation().contains(sf::Vector2f(pos)))
		return true;
	else if (gui_Window4->GetAllocation().contains(sf::Vector2f(pos)))
		return true;
	else
		return false;
}

//Reaktion auf ver�nderung der Range
void GUI::AdjustmentChange()
{
	std::stringstream sstr;
	sstr << gui_adjustment->GetValue();
	gui_scale_Label->SetText(sstr.str());
}

void GUI::Button_Erstelle_Click()
{
	while (true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !Point_On_Window(sf::Mouse::getPosition(*gui_RenderWindow)))
		{
			auto mouspos = sf::Mouse::getPosition(*gui_RenderWindow);
			Punktladung teil = Punktladung(gui_adjustment->GetValue(), InConvert::To_Sim(sf::Vector2f(mouspos)));
			Simulation::Teilchen_vec.push_back(teil);
			std::stringstream ss;
			ss << (Simulation::Teilchen_vec.size() - 1);
			std::string str = "Ladung: " + ss.str();
			gui_comboBox->AppendItem(str);
			break;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			break;
	}
	
}


//Makiert das Aktuell ausgew�hlte Teilchen
void GUI::ComboAuswahl()
{
	if (Simulation::Teilchen_vec.size() < last_auswahl)
		return;

	/*Simulation::Teilchen_vec[last_auswahl].col = sf::Color::Blue;
	int auswahl = gui_comboBox->GetSelectedItem();
	last_auswahl = auswahl;
	Simulation::Teilchen_vec[auswahl].col = sf::Color::Red;*/

	int auswahl = gui_comboBox->GetSelectedItem();
	Ladung_Ausw�hlen(auswahl);

	std::stringstream ss;
	ss << Simulation::Teilchen_vec[auswahl].pos.x;
	gui_Entry_pos_x->SetText(ss.str());
	ss.str("");
	ss << Simulation::Teilchen_vec[auswahl].pos.y;
	gui_Entry_pos_y->SetText(ss.str());
	ss.str("");
	ss << Simulation::Teilchen_vec[auswahl].Q;
	gui_Entry_Ladung->SetText(ss.str());
	ss.str("");
}

void GUI::AuswahlL�schen()
{
	int auswahl = gui_comboBox->GetSelectedItem();
	gui_comboBox->RemoveItem(auswahl);
	Simulation::Teilchen_vec.erase(Simulation::Teilchen_vec.begin() + auswahl);
}

void GUI::AllesL�schen()
{
	gui_comboBox->Clear();
	Simulation::Teilchen_vec.clear();
	gui_Entry_Ladung->SetText("Ladung");
	gui_Entry_pos_x->SetText("x:");
	gui_Entry_pos_y->SetText("y:");
}

void GUI::Set()
{
	int auswahl = gui_comboBox->GetSelectedItem();
	if (auswahl < 0)
	{
	}
	else
	{
		Simulation::Teilchen_vec[auswahl].pos.x = std::stof(gui_Entry_pos_x->GetText().toAnsiString().c_str());
		Simulation::Teilchen_vec[auswahl].pos.y = std::stof(gui_Entry_pos_y->GetText().toAnsiString().c_str());
		Simulation::Teilchen_vec[auswahl].Q = std::stof(gui_Entry_Ladung->GetText().toAnsiString().c_str()); //Nicht sehr genau bisher her keine Nachkommer stellen

		Ladung_Endw�hlen();
		gui_Entry_Ladung->SetText("Ladung");
		gui_Entry_pos_x->SetText("x:");
		gui_Entry_pos_y->SetText("y:");


	}
}

void GUI::Set_E()
{
	
	InConvert::set(std::stof(gui_Entry_pos_x_max->GetText().toAnsiString().c_str()), std::stof(gui_Entry_pos_x_min->GetText().toAnsiString().c_str()), std::stof(gui_Entry_pos_x_scl->GetText().toAnsiString().c_str()), std::stof(gui_Entry_pos_y_scl->GetText().toAnsiString().c_str()));

	gridvar = grid();

}

void GUI::Reset_E()
{
}

void GUI::Darstellung_Feld_Set()
{
	sim.Draw_Feldlinien_var = false;
	sim.Draw_Pfeil_var = true;
}

void GUI::Darstellung_Feld_Linien()
{
	sim.Draw_Feldlinien_var = true;
	sim.Draw_Pfeil_var = false;
}

void GUI::Darstellung_Keine()
{
	sim.Draw_Pfeil_var = false;
	sim.Draw_Feldlinien_var = false;
}


void GUI::Ladung_Ausw�hlen(int NR)
{
	if (Simulation::Teilchen_vec.size() == 0)
		return;

	if (!(last_auswahl > Simulation::Teilchen_vec.size()) )
	{
		Simulation::Teilchen_vec[last_auswahl].Ausgewaehlt = false;
	}
	if (!(NR > Simulation::Teilchen_vec.size()))
	{
		last_auswahl = NR;
		Simulation::Teilchen_vec[NR].Ausgewaehlt = true;
	}
}

void GUI::Ladung_Endw�hlen()
{
	if (!(last_auswahl > Simulation::Teilchen_vec.size()))
	{
		Simulation::Teilchen_vec[last_auswahl].Ausgewaehlt = false;
	}
}

std::vector<sf::VertexArray> GUI::grid()
{
	std::vector<sf::VertexArray> vec_vertex;

	sf::VertexArray  vec_Vec2f_X_A(sf::Lines, 2);
	sf::VertexArray  vec_Vec2f_Y_A(sf::Lines, 2);
	std::vector<sf::Vector2f> vec_Vec2f_X_Scal_A;
	std::vector<sf::Vector2f> vec_Vec2f_Y_Scal_A;


	vec_Vec2f_X_A[0] = sf::Vector2f(InConvert::Get_X_On_Screen(InConvert::mXMAX), InConvert::Get_Y_On_Screen(0));
	vec_Vec2f_X_A[1] = sf::Vector2f(InConvert::Get_X_On_Screen(InConvert::mXMIN), InConvert::Get_Y_On_Screen(0));
	vec_Vec2f_X_A[0].color = sf::Color::Black;
	vec_Vec2f_X_A[1].color = sf::Color::Black;

	vec_Vec2f_Y_A[0] = sf::Vector2f(InConvert::Get_X_On_Screen(0), InConvert::Get_Y_On_Screen(InConvert::mYMAX));
	vec_Vec2f_Y_A[1] = sf::Vector2f(InConvert::Get_X_On_Screen(0), InConvert::Get_Y_On_Screen(InConvert::mYMIN));
	vec_Vec2f_Y_A[0].color = sf::Color::Black;
	vec_Vec2f_Y_A[1].color = sf::Color::Black;

	vec_vertex.push_back(vec_Vec2f_Y_A);
	vec_vertex.push_back(vec_Vec2f_X_A);

	for (float i = 0; i < InConvert::mXMAX; i += InConvert::mSCALX)
	{

		sf::VertexArray line(sf::Lines, 2);
		line[0] = sf::Vector2f(InConvert::Get_X_On_Screen(i), InConvert::Get_Y_On_Screen(0) + 8);
		line[1] = sf::Vector2f(InConvert::Get_X_On_Screen(i), InConvert::Get_Y_On_Screen(0) - 8);
		line[0].color = sf::Color::Black;
		line[1].color = sf::Color::Black;

		vec_vertex.push_back(line);

	}

	for (float i = 0; i > InConvert::mXMIN; i -= InConvert::mSCALX)
	{

		sf::VertexArray line(sf::Lines, 2);
		line[0] = sf::Vector2f(InConvert::Get_X_On_Screen(i), InConvert::Get_Y_On_Screen(0) + 8);
		line[1] = sf::Vector2f(InConvert::Get_X_On_Screen(i), InConvert::Get_Y_On_Screen(0) - 8);
		line[0].color = sf::Color::Black;
		line[1].color = sf::Color::Black;

		vec_vertex.push_back(line);

	}

	for (float i = 0; i < InConvert::mYMAX; i += InConvert::mSCALY)
	{

		sf::VertexArray line(sf::Lines, 2);
		line[0] = sf::Vector2f(InConvert::Get_X_On_Screen(0) - 8, InConvert::Get_Y_On_Screen(i));
		line[1] = sf::Vector2f(InConvert::Get_X_On_Screen(0) + 8, InConvert::Get_Y_On_Screen(i));
		line[0].color = sf::Color::Black;
		line[1].color = sf::Color::Black;

		vec_vertex.push_back(line);

	}

	for (float i = 0; i > InConvert::mYMIN; i -= InConvert::mSCALY)
	{

		sf::VertexArray line(sf::Lines, 2);
		line[0] = sf::Vector2f(InConvert::Get_X_On_Screen(0) - 8, InConvert::Get_Y_On_Screen(i));
		line[1] = sf::Vector2f(InConvert::Get_X_On_Screen(0) + 8, InConvert::Get_Y_On_Screen(i));
		line[0].color = sf::Color::Black;
		line[1].color = sf::Color::Black;

		vec_vertex.push_back(line);


	}
	return vec_vertex;

}

void GUI::OnMauseDown(sf::Vector2i pos)
{
	sf::Vector2f Sim_Pos = InConvert::To_Sim(sf::Vector2f(pos));

	int Ladung = -1;
	for (int i = 0; i != Simulation::Teilchen_vec.size(); i++)
	{
		if (Simulation::Teilchen_vec[i].OnPoint(sf::Vector2f(Sim_Pos)))
		{
			Ladung = i;
			break;
		}
	}
	

	if (Ladung != -1)
	{
		this->Ladung_Ausw�hlen(Ladung);
		this->Fill_Set_Dialog();

		Move_auswahl = Ladung;
	}

}

void GUI::OnMauseUp(sf::Vector2i pos)
{
	

	Move_auswahl = -1;
}

void GUI::OnMauseMove(sf::Vector2i pos)
{

	if (Move_auswahl != -1 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		Simulation::Teilchen_vec[Move_auswahl].pos = InConvert::To_Sim(sf::Vector2f(pos));
	}

	Fill_Set_Dialog();
}

void GUI::Fill_Set_Dialog()
{
	if (Simulation::Teilchen_vec.size() < last_auswahl + 1)
		return;
	gui_comboBox->SelectItem(last_auswahl);

	std::stringstream ss;
	ss << Simulation::Teilchen_vec[last_auswahl].pos.x;
	gui_Entry_pos_x->SetText(ss.str());
	ss.str("");
	ss << Simulation::Teilchen_vec[last_auswahl].pos.y;
	gui_Entry_pos_y->SetText(ss.str());
	ss.str("");
	ss << Simulation::Teilchen_vec[last_auswahl].Q;
	gui_Entry_Ladung->SetText(ss.str());
	ss.str("");
}


