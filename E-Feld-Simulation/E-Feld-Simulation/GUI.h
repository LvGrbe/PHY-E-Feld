#pragma once
#include "Math_PH.h"
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <memory>

class GUI
{
public:
	GUI();
	~GUI();

	static sfg::SFGUI gui_sfgui;
	static std::shared_ptr<sfg::Desktop> gui_Desktop;
private:
   std::shared_ptr<sfg::Window>  gui_Window;
   std::shared_ptr<sfg::Box> gui_Box;
   std::shared_ptr<sfg::Button> gui_button_create;
   std::shared_ptr<sfg::Scale> gui_scale;
   std::shared_ptr<sfg::Adjustment>  gui_adjustment;
   std::shared_ptr<sfg::Box> gui_scalebox;
   ;

};

