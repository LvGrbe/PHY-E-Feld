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
#include <Windows.h>
#include <Shobjidl.h>
#include <fstream>

class GUI
{
public:
	GUI(std::shared_ptr<sf::RenderWindow> Window,Simulation sim);
	GUI();
	~GUI();

	static sfg::SFGUI gui_sfgui;
	static std::shared_ptr<sfg::Desktop> gui_Desktop;

	void Ladung_Auswählen(int NR);
	void Ladung_Endwählen();
	//Grid
	std::vector<sf::VertexArray> gridvar;
	std::vector<sf::VertexArray> grid();
	bool take_screenshot;
public: // Drag/Drop // Select

	void OnMauseDown(sf::Vector2i pos);
	void OnMauseUp(sf::Vector2i pos);
	void OnMauseMove(sf::Vector2i pos);

	void Fill_Set_Dialog();
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
   std::shared_ptr<sfg::Button> gui_button_d_Pfeil;
   std::shared_ptr<sfg::Button> gui_button_d_Linien;
   std::shared_ptr<sfg::Button> gui_button_d_Windows;
   std::shared_ptr<sfg::Button> gui_button_d_Reset;
   //Window 5
   std::shared_ptr<sfg::Window>  gui_Window5;
   std::shared_ptr<sfg::Box> gui_Box5;
   std::shared_ptr<sfg::Button> gui_button_save;
   std::shared_ptr<sfg::Button> gui_button_load;
   std::shared_ptr<sfg::Button> gui_button_take_image;

   // Selection
   int last_auswahl;
   int Move_auswahl = -1;

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
   void Darstellung_Fenster();
   void Darstellung_Keine();

   //Signale 5
   void Load_Vorlage();
   void Save_Vorlage();
   void take_Imgae();

private: // Helper Funktions
	std::shared_ptr<sfg::Box> Create_Input(std::string name, std::shared_ptr<sfg::Entry> input, std::string Einheit, float name_Alloc_Size = 20);
};

