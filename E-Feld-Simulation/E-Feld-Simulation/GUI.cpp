#include "GUI.h"

//Erstelle die Statischen Elemente
sfg::SFGUI GUI::gui_sfgui = sfg::SFGUI();
std::shared_ptr<sfg::Window> GUI::gui_Window = sfg::Window::Create();
std::shared_ptr<sfg::Desktop> GUI::gui_Desktop = std::make_shared<sfg::Desktop>(sfg::Desktop());
std::shared_ptr<sfg::Box> GUI::gui_Box = sfg::Box::Create();

GUI::GUI()
{
	
}


GUI::~GUI()
{
}
