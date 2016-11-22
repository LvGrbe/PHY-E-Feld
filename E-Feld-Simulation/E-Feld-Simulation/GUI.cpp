#include "GUI.h"

//Erstelle die Statischen Elemente
sfg::SFGUI GUI::gui_sfgui = sfg::SFGUI();
std::shared_ptr<sfg::Desktop> GUI::gui_Desktop = std::make_shared<sfg::Desktop>(sfg::Desktop());


GUI::GUI(std::shared_ptr<sf::RenderWindow> Window)
{   
	last_auswahl = 0;
	gui_RenderWindow = Window;

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
	
	//Füge die Letzten Teile zusammen
	gui_Window->Add(GUI::gui_Box);
	gui_Desktop->Add(GUI::gui_Window);
	
 //-----------------------------------------------------------------------

	//Window2
	gui_Window2 = sfg::Window::Create();
	gui_Box2_vertical = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	gui_Box2_horizontal = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
	gui_comboBox = sfg::ComboBox::Create();
	gui_button_alles_löschen = sfg::Button::Create();
	gui_button_löschen = sfg::Button::Create();

	//Init
	gui_Window2->SetTitle("Auswahl Ladungen");
	gui_Window2->SetPosition(sf::Vector2f(0,140));
	gui_button_alles_löschen->SetLabel("Lösch alles");
	gui_button_löschen->SetLabel("Lösche auswahl");

	//Set Signale
	gui_comboBox->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&GUI::ComboAuswahl,this));
	gui_button_alles_löschen->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::AllesLöschen, this));
	gui_button_löschen->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&GUI::AuswahlLöschen, this));

	//Erstellen
	gui_Window2->Add(GUI::gui_Box2_vertical);
	gui_Box2_horizontal->Pack(GUI::gui_comboBox);
	//gui_Box2_horizontal->Pack(GUI::gui_button_löschen); Fügt den Button  zum auswahl Löschen hinzu
	gui_Box2_horizontal->Pack(GUI::gui_button_alles_löschen);
	gui_Box2_vertical->Pack(GUI::gui_Box2_horizontal);
	gui_Box2_vertical->Pack(sfg::Separator::Create());
	gui_Desktop->Add(GUI::gui_Window2);

	//-----------------------------------------------------------
}

GUI::~GUI()
{
}

//Reaktion auf veränderung der Range
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			auto mouspos = sf::Mouse::getPosition(*gui_RenderWindow);
			Punktladung teil = Punktladung(gui_adjustment->GetValue(),mouspos);
			Simulation::Teilchen_vec.push_back(teil);
			std::stringstream ss;
			ss << (Simulation::Teilchen_vec.size() - 1);
			std::string str = "Ladung: " + ss.str();
			gui_comboBox->AppendItem(str);
			break;
 		}
	}
	
}


//Makiert das Aktuell ausgewählte Teilchen
void GUI::ComboAuswahl()
{
	Simulation::Teilchen_vec[last_auswahl].col = sf::Color::Blue;
	int auswahl = gui_comboBox->GetSelectedItem();
	Simulation::Teilchen_vec[auswahl].col = sf::Color::Red;
	last_auswahl = auswahl;
}

void GUI::AuswahlLöschen()
{
	int auswahl = gui_comboBox->GetSelectedItem();
	gui_comboBox->RemoveItem(auswahl);
	Simulation::Teilchen_vec.erase(Simulation::Teilchen_vec.begin() + auswahl);
}

void GUI::AllesLöschen()
{
	gui_comboBox->Clear();
	Simulation::Teilchen_vec.clear();
}
