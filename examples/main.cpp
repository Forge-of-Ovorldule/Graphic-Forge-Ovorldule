#include "../include/OvorlduleGraphics/Window.h"
#include <iostream>

using namespace Ovorldule;

int main ()
{
	try
	{
		Window window (800, 600, "GraphicForgeOvorldule Example");

		while (!window.shouldClose ())
		{
			window.swapBuffers ();
			window.pollEvents ();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}