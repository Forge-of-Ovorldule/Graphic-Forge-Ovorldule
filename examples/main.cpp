#include "../include/OvorlduleGraphics/Window.h"
#include <iostream>

using namespace Ovorldule;

int main ()
{
	Window window;
	window.setSize (Vector2i (1920, 1080));
	window.setTitle ("The best library");

	while (!window.shouldClose ())
	{
		window.swapBuffers ();
		window.pollEvents ();
	}
	return 0;
}