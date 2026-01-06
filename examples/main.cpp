#include "../include/OvorlduleGraphics/Window.h"
#include <iostream>

using namespace Ovorldule;

int main ()
{
	Window window;
	window.setSize (Vector2i (1920, 1080));
	window.setTitle ("Ovorldule graphics example");
	window.setCloseCallback ([] ()
	                         { std::cout << "Window closed" << std::endl; });

	while (window.isOpen ())
	{
		window.work ();
	}

	return 0;
}