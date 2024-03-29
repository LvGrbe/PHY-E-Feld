#include "GUI.h"

//Erstelle die Statischen Elemente
sfg::SFGUI GUI::gui_sfgui = sfg::SFGUI();
std::shared_ptr<sfg::Desktop> GUI::gui_Desktop = std::make_shared<sfg::Desktop>(sfg::Desktop());

GUI::GUI(std::shared_ptr<sf::RenderWindow> Window,Simulation sim)
{   
	last_auswahl = 0;
	gui_RenderWindow = Window;
	sim = sim;
	take_screenshot = false;
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

	//Window2 - Ladung Auswahl
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
	gui_Box2_horizontal2->Pack(Create_Input("X: ", gui_Entry_pos_x, "m"));
	gui_Box2_horizontal2->Pack(Create_Input("Y: ", gui_Entry_pos_y, "m"));
	gui_Box2_horizontal2->Pack(Create_Input("Q: ", gui_Entry_Ladung, "C"));
	gui_Box2_horizontal2->Pack(gui_button_Set);
	gui_Box2_vertical->Pack(GUI::gui_Box2_horizontal);
	gui_Box2_vertical->Pack(sfg::Separator::Create());
	gui_Box2_vertical->Pack(GUI::gui_Box2_horizontal2);
	gui_Desktop->Add(GUI::gui_Window2);

	//-----------------------------------------------------------

	//Window 3 - Fenster Einstellung
	gui_Window3 = sfg::Window::Create();
	gui_Box3_vertical = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_Box3_horizontal2 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_Box3_horizontal = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 10.f);
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

	//Input
	auto Vertikal1 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	auto Vertikal2 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	
	gui_Entry_pos_x_max->SetRequisition(sf::Vector2f(50, 0));
	gui_Entry_pos_x_scl->SetRequisition(sf::Vector2f(50, 0));
	gui_Entry_pos_x_min->SetRequisition(sf::Vector2f(50, 0));
	gui_Entry_pos_y_scl->SetRequisition(sf::Vector2f(50, 0));

	Vertikal1->Pack(Create_Input("x_max:", gui_Entry_pos_x_max, "m", 45));
	Vertikal1->Pack(Create_Input("x_scl:", gui_Entry_pos_x_scl, "m", 45));
	Vertikal2->Pack(Create_Input("x_min:", gui_Entry_pos_x_min, "m", 45));
	Vertikal2->Pack(Create_Input("y_scl:", gui_Entry_pos_y_scl, "m", 45));
	//Set Layout Einstellung
	gui_Window3->Add(gui_Box3_vertical);
	gui_Box3_vertical->Pack(gui_Box3_horizontal);
	gui_Box3_vertical->Pack(gui_Box3_horizontal2);
	gui_Box3_horizontal->Pack(Vertikal1);
	gui_Box3_horizontal->Pack(Vertikal2);

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
	gui_button_d_Windows = sfg::Button::Create();
	gui_button_d_Reset = sfg::Button::Create();
	gui_Window4->SetTitle("Darstellung");
	gui_Window4->SetPosition(sf::Vector2f(200, 400));
	gui_button_d_Pfeil->SetLabel("Pfeil");
	gui_button_d_Linien->SetLabel("Linien");
	gui_button_d_Reset->SetLabel("Keine");
	gui_button_d_Windows->SetLabel("Fenster ausblenden");
	//Signals
	gui_button_d_Pfeil->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Darstellung_Feld_Set, this));
	gui_button_d_Linien->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Darstellung_Feld_Linien, this));
	gui_button_d_Reset->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Darstellung_Keine, this));
	gui_button_d_Windows->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Darstellung_Fenster, this));

	gui_Window4->Add(gui_Box4);
	gui_Box4->Pack(gui_button_d_Pfeil);
	gui_Box4->Pack(gui_button_d_Linien);
	gui_Box4->Pack(gui_button_d_Windows);
	gui_Box4->Pack(gui_button_d_Reset);
	gui_Desktop->Add(gui_Window4);


	//Window 5
	gui_Window5 = sfg::Window::Create();
	gui_Box5 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
	gui_button_save = sfg::Button::Create();
	gui_button_load = sfg::Button::Create();
	gui_button_take_image = sfg::Button::Create();

	//Ini
	gui_Window5->SetTitle("Vorlagen und Image");
	gui_Window5->SetPosition(sf::Vector2f(300, 400));
	gui_button_save->SetLabel("Speichern");
	gui_button_load->SetLabel("Laden");
	gui_button_take_image->SetLabel("Bild");
	gui_button_save->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Save_Vorlage, this));
	gui_button_load->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::Load_Vorlage, this));
	gui_button_take_image->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::take_Imgae, this));


	gui_Window5->Add(gui_Box5);
	gui_Box5->Pack(gui_button_save);
	gui_Box5->Pack(gui_button_load);
	gui_Box5->Pack(gui_button_take_image);
	gui_Desktop->Add(gui_Window5);

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
	{ 
		return;
    }

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
	Simulation::aktuelle_Teilchen_zahl = 0;
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

			Simulation::aktuelle_Teilchen_zahl = 0;
			gui_comboBox->SelectItem(auswahl);
	}
}

void GUI::Set_E()
{

		InConvert::set(std::stof(gui_Entry_pos_x_max->GetText().toAnsiString().c_str()), std::stof(gui_Entry_pos_x_min->GetText().toAnsiString().c_str()), std::stof(gui_Entry_pos_x_scl->GetText().toAnsiString().c_str()), std::stof(gui_Entry_pos_y_scl->GetText().toAnsiString().c_str()));

		gridvar = grid();

}

void GUI::Reset_E()
{
	gui_Entry_pos_x_min->SetText("x_min:");
	gui_Entry_pos_x_max->SetText("x_max:");
	gui_Entry_pos_x_scl->SetText("x_scl:");
	gui_Entry_pos_y_scl->SetText("y_scl:");
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

void GUI::Darstellung_Fenster()
{
	gui_Window->Show(false);
	gui_Window2->Show(false);
	gui_Window3->Show(false);

}

void GUI::Darstellung_Keine()
{
	sim.Draw_Pfeil_var = false;
	sim.Draw_Feldlinien_var = false;

	gui_Window->Show(true);
	gui_Window2->Show(true);
	gui_Window3->Show(true);
}

void GUI::Load_Vorlage()
{ 
	sim.Teilchen_vec.clear();
	IFileOpenDialog *openfile = NULL;
	HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_IFileDialog, (void**)&openfile);
	PWSTR pszFilePath;
	if (SUCCEEDED(hr))
	{
			openfile->Show(NULL);

			IShellItem *Item;
			hr = openfile->GetResult(&Item);
			if (SUCCEEDED(hr))
			{
				Item->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
			}
			else
			{
				openfile->Release();
				return;
			}
			openfile->Release();
	}
	else
	{
		MessageBoxA(NULL, "Error Create FileOpenDialog", "Error", MB_OK);
		return;
	}
	CoUninitialize();

	std::fstream f;
	std::string s;
	f.open(pszFilePath, std::ios::in);
	while (!f.eof())
	{

		getline(f, s);
		if (s != "")
		{
			
			std::string ladung = s.substr(0, s.find(','));
			s.erase(0, s.find(',') + sizeof(','));
			std::string x = s.substr(0, s.find(','));
			s.erase(0, s.find(',') + sizeof(','));
			std::string y = s.substr(0, s.find(';'));

			sim.Teilchen_vec.push_back(Punktladung(std::stof(ladung.c_str()), sf::Vector2f(std::stof(x.c_str()), std::stof(y.c_str()))));
			std::stringstream ss;
			ss << (Simulation::Teilchen_vec.size() - 1);
			std::string str = "Ladung: " + ss.str();
			gui_comboBox->AppendItem(str);
		}
		
	}
	f.close();
	Simulation::aktuelle_Teilchen_zahl = 0;
}

void GUI::Save_Vorlage()
{
	COMDLG_FILTERSPEC a;
	a.pszName = L"Text";
	a.pszSpec = L".txt";

	IFileSaveDialog *savefile = NULL;
	HRESULT hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_INPROC_SERVER, IID_IFileDialog, (void**)&savefile);
	PWSTR pszFilePath;
	if (SUCCEEDED(hr))
	{
		savefile->SetFileTypes(1, &a);
		savefile->Show(NULL);
		IShellItem *Item;
		hr = savefile->GetResult(&Item);
		if (SUCCEEDED(hr))
		{
			Item->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
		}
		else
		{
			savefile->Release();
			return;
		}
		savefile->Release();
	}
	else
	{
		MessageBoxA(NULL, "Error Create FileSaveDialog", "Error", MB_OK);
		return;
	}
	CoUninitialize();

	std::fstream f;
	wcscat(pszFilePath, a.pszSpec);
	f.open(pszFilePath, std::ios::out | std::ios::trunc);
	for (int i = 0; i < sim.Teilchen_vec.size(); i++)
	{
		f << sim.Teilchen_vec[i].Q << "," << sim.Teilchen_vec[i].pos.x << "," << sim.Teilchen_vec[i].pos.y << ";" << "\n";
	}
	f.close();

}

void GUI::take_Imgae()
{
	take_screenshot = true;
}

std::shared_ptr<sfg::Box> GUI::Create_Input(std::string name, std::shared_ptr<sfg::Entry> input, std::string Einheit, float name_Alloc_Size )
{
	auto out = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 1.f);
	auto a = sfg::Label::Create(name);
	auto b = sfg::Label::Create(Einheit);

	a->SetRequisition(sf::Vector2f(name_Alloc_Size, 0));
	b->SetRequisition(sf::Vector2f(10, 0));

	out->Pack(a, false);
	out->Pack(input);
	out->Pack(b, false);
	
	return out;
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
	if (Move_auswahl != -1)
	{
		//Redraw
		Simulation::aktuelle_Teilchen_zahl = 0;
	}

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


