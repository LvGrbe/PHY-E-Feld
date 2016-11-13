#pragma once
#include "Math_PH.h"
#include "Teilchen.h"
#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <memory>

class GUI
{
public:
	GUI(std::shared_ptr<sf::RenderWindow> Window);
	~GUI();

	static sfg::SFGUI gui_sfgui;
	static std::shared_ptr<sfg::Desktop> gui_Desktop;
	static std::vector<Teilchen> Teilchen_vec;
private:
   std::shared_ptr<sf::RenderWindow> gui_RenderWindow;
   std::shared_ptr<sfg::Window>  gui_Window;
   std::shared_ptr<sfg::Box> gui_Box;
   std::shared_ptr<sfg::Button> gui_button_erstelle;
   std::shared_ptr<sfg::Scale> gui_scale;
   std::shared_ptr<sfg::Adjustment>  gui_adjustment;
   std::shared_ptr<sfg::Box> gui_scalebox;
   std::shared_ptr<sfg::Label> gui_scale_Label;

   //Signal Funktion der GUI
   void AdjustmentChange();
   void Button_Erstelle_Click();

};

