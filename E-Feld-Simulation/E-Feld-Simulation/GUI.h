#pragma once
#include <sstream>
#include <algorithm>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Simulation.h"
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
private:
	std::shared_ptr<sf::RenderWindow> gui_RenderWindow;
	//Window 1
   std::shared_ptr<sfg::Window>  gui_Window;
   std::shared_ptr<sfg::Box> gui_Box;
   std::shared_ptr<sfg::Button> gui_button_erstelle;
   std::shared_ptr<sfg::Scale> gui_scale;
   std::shared_ptr<sfg::Adjustment>  gui_adjustment;
   std::shared_ptr<sfg::Box> gui_scalebox;
   std::shared_ptr<sfg::Label> gui_scale_Label;
   //Window 2
   std::shared_ptr<sfg::Window>  gui_Window2;
   std::shared_ptr<sfg::Box> gui_Box2_vertical;
   std::shared_ptr<sfg::Box> gui_Box2_horizontal2;
   std::shared_ptr<sfg::Box> gui_Box2_horizontal;
   std::shared_ptr<sfg::ComboBox> gui_comboBox;
   std::shared_ptr<sfg::Button> gui_button_löschen;
   std::shared_ptr<sfg::Button> gui_button_alles_löschen;
   std::shared_ptr<sfg::Entry> gui_Entry_pos_x;
   std::shared_ptr<sfg::Entry> gui_Entry_pos_y;
   std::shared_ptr<sfg::Entry> gui_Entry_Ladung;
   std::shared_ptr<sfg::Button> gui_button_Set;
   int last_auswahl;


   //Signal Funktion der GUI
   void AdjustmentChange();
   void Button_Erstelle_Click();

   void ComboAuswahl();
   void AuswahlLöschen();
   void AllesLöschen();
   void Set();
};

