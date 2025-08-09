#include "../../include/OvorlduleGraphics/Window.h"
#include <stdexcept>

namespace Ovorldule
{

bool Window::glfwInitialized = false;

Window::Window (int width, int height, const std::string& title)
{
	initGLFW ();

	// Настройка параметров окна
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow (width, height, title.c_str (), nullptr, nullptr);
	if (!window)
	{
		throw std::runtime_error ("Failed to create GLFW window");
	}

	glfwMakeContextCurrent (window);
}

Window::~Window ()
{
	glfwDestroyWindow (window);
	terminateGLFW ();
}

void Window::initGLFW ()
{
	if (!glfwInitialized)
	{
		if (!glfwInit ())
		{
			throw std::runtime_error ("Failed to initialize GLFW");
		}
		glfwInitialized = true;
	}
}

void Window::terminateGLFW ()
{
	if (glfwInitialized)
	{
		glfwTerminate ();
		glfwInitialized = false;
	}
}

bool Window::shouldClose () const
{
	return glfwWindowShouldClose (window);
}

void Window::swapBuffers ()
{
	glfwSwapBuffers (window);
}

void Window::pollEvents ()
{
	glfwPollEvents ();
}

} // namespace Ovorldule