#include "Renderer.h"

//Dekelration des Smart_ptr zum Fenster
std::shared_ptr<sf::RenderWindow> Renderer::renderWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "E-Feld-Simulation"));
Simulation Renderer::sim = Simulation(Renderer::renderWindow);
GUI Renderer::gui = GUI(Renderer::renderWindow, Renderer::sim);

Renderer::Renderer()
{	
}

Renderer::~Renderer()
{
}

// Window loop funktion
int Renderer::run()
{    
	

	InConvert::set(renderWindow->getSize());
	//Grid
	gui.gridvar = gui.grid();
	
	m_gui_Timer.restart();

	while (renderWindow->isOpen())
	{

		sf::Event event;
		while (renderWindow->pollEvent(event))
		{
			gui.gui_Desktop->HandleEvent(event);

			if (event.type == sf::Event::Closed)
				renderWindow->close();
			else if (event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				renderWindow->setView(sf::View(visibleArea));

				InConvert::set(renderWindow->getSize());
				gui.gridvar = gui.grid();
				sim.aktuelle_Teilchen_zahl = 0;

			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				gui.OnMauseDown(sf::Mouse::getPosition(*renderWindow));
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				gui.OnMauseUp(sf::Mouse::getPosition(*renderWindow));
			}
			else if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				gui.OnMauseMove(sf::Mouse::getPosition(*renderWindow));
			}
			
		}
		
		gui.gui_Desktop->Update(m_gui_Timer.restart().asSeconds());


		renderWindow->clear(sf::Color::White);

		
		//Zeichne Grid
		for (int i = 0; i < gui.gridvar.size(); i++)
		{
			renderWindow->draw(gui.gridvar[i]);
		}

		//Zeichne Feldlinien
		if (sim.Draw_Pfeil_var || sim.Draw_Feldlinien_var)
		{
			sim.Draw_Feldlinin();
		}
		//Zeichen Teilchen
		sim.renderer_Teilchen();

		//Zeichne Pfeil
		if (sim.Draw_Pfeil_var)
		{
			sim.Draw_Pfeil();
		}

		if (!gui.take_screenshot)
		{
			gui.gui_sfgui.Display(*renderWindow);
		}
		else
		{
			take_screenshot();
			gui.take_screenshot = false;
		}

		renderWindow->display();

		renderWindow->resetGLStates();
	}

	return 0;
}

void Renderer::take_screenshot()
{
	sf::Image screenshot = renderWindow->capture();

	COMDLG_FILTERSPEC rgSpec[] =
	{
		{ L"JPG", L".jpg" },
		{ L"PNG", L".png" },
	};
	UINT type;

	IFileSaveDialog *savefile = NULL;
	HRESULT hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_INPROC_SERVER, IID_IFileDialog, (void**)&savefile);
	PWSTR pszFilePath;
	if (SUCCEEDED(hr))
	{
		savefile->SetFileTypes(2, rgSpec);
		savefile->Show(NULL);
		IShellItem *Item;
		hr = savefile->GetResult(&Item);
		if (SUCCEEDED(hr))
		{
			Item->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
			savefile->GetFileTypeIndex(&type);
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

	char szBuffer[255];
	WideCharToMultiByte(CP_ACP, 0, wcscat(pszFilePath, rgSpec[type -1].pszSpec), -1, szBuffer, sizeof(szBuffer), NULL, NULL);

	screenshot.saveToFile(szBuffer);
}


