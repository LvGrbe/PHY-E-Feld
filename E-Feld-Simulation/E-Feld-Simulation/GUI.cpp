#include "GUI.h"

//Erstelle die Statischen Elemente
sfg::SFGUI GUI::gui_sfgui = sfg::SFGUI();
std::shared_ptr<sfg::Desktop> GUI::gui_Desktop = std::make_shared<sfg::Desktop>(sfg::Desktop());


GUI::GUI()
{   
	//Erstellung der Elemente
	gui_Window = sfg::Window::Create();
	gui_Box = sfg::Box::Create();
	gui_button_create = sfg::Button::Create();
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

	//Pack Window
	gui_scalebox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	gui_scalebox->Pack(gui_scale, false, false);
	gui_Box->Pack(gui_scale_Label);
	gui_Box->Pack(gui_scalebox);
	gui_Window->Add(GUI::gui_Box);
	gui_Desktop->Add(GUI::gui_Window);

}


GUI::~GUI()
{
}

void GUI::AdjustmentChange()
{
	std::stringstream sstr;
	sstr << gui_adjustment->GetValue();
	gui_scale_Label->SetText(sstr.str());
}
