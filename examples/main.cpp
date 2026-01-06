#include "../include/OvorlduleGraphics/Window.h"
#include <iostream>

using namespace Ovorldule;

int main ()
{
	Window window (WindowParameters ()
	                   .size (800, 600)
	                   .title ("Ovorldule graphics example"));
	window.setCloseCallback ([] ()
	                         { std::cout << "Window closed" << std::endl; });

	while (window.isOpen ())
	{
		window.work ();
	}

	return 0;
}