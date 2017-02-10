#pragma once
#include <sstream>
#include <algorithm>
#include "Math_PH.h"
#include "Punktladung.h"
#include "Simulation.h"
#include "InConvert.h"
#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <memory>

class GUI
{
public:
	GUI(std::shared_ptr<sf::RenderWindow> Window,Simulation sim);
	GUI();
	~GUI();


	static sfg::SFGUI gui_sfgui;
	static std::shared_ptr<sfg::Desktop> gui_Desktop;
	//Grid
	std::vector<sf::VertexArray> gridvar;
	std::vector<sf::VertexArray> grid();
private:
	
	Simulation sim;
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
   //Window 3
   std::shared_ptr<sfg::Window>  gui_Window3;
   std::shared_ptr<sfg::Box> gui_Box3_vertical;
   std::shared_ptr<sfg::Box> gui_Box3_horizontal2;
   std::shared_ptr<sfg::Box> gui_Box3_horizontal;
   //std::shared_ptr<sfg::Box> gui_Box3_horizontal3;
   std::shared_ptr<sfg::Button> gui_button_Set2;
   std::shared_ptr<sfg::Button> gui_button_löschen2;
   std::shared_ptr<sfg::Entry> gui_Entry_pos_x_max;
   std::shared_ptr<sfg::Entry> gui_Entry_pos_x_min;
   std::shared_ptr<sfg::Entry> gui_Entry_pos_x_scl;
   std::shared_ptr<sfg::Entry> gui_Entry_pos_y_scl;
   //Window 4
   std::shared_ptr<sfg::Window>  gui_Window4;
   std::shared_ptr<sfg::Box> gui_Box4;
   std::shared_ptr<sfg::Button> gui_button_d_Fähnchen;
   std::shared_ptr<sfg::Button> gui_button_d_Linien;

   int last_auswahl;

   bool Point_On_Window(sf::Vector2i pos);
    
   //Signal Funktion der GUI W1 & w	2
   void AdjustmentChange();
   void Button_Erstelle_Click();

   void ComboAuswahl();
   void AuswahlLöschen();
   void AllesLöschen();
   void Set();

   //Signal Funktion der GUI w3
   void Set_E();
   void Reset_E();
 
   //Signale w4
   void Darstellung_Feld_Set();
   void Darstellung_Feld_Linien();
};

