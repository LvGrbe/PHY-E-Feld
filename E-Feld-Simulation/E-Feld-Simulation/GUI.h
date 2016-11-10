#pragma once
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <memory>

class GUI
{
public:
	GUI();
	~GUI();

	static sfg::SFGUI gui_sfgui;
	static std::shared_ptr<sfg::Window>  gui_Window;
	static std::shared_ptr<sfg::Desktop> gui_Desktop;
	static std::shared_ptr<sfg::Box> gui_Box;
};

