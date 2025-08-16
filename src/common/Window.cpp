#include "../../include/OvorlduleGraphics/Window.h"
#include <stdexcept>
#include <iostream>

namespace Ovorldule
{

bool Window::glfwInitialized = false;
int Window::windowCount = 0;

static void glfwErrorCallback (int error, const char* description)
{
	std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

// Публичный конструктор
Window::Window (const WindowParameters& params)
    : Window (params.getSize ().width (), params.getSize ().height (), params.getTitle ())
{
}

// Приватный конструктор
Window::Window (int width, int height, const std::string& title)
{
	initGLFW ();

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
	windowCount++;
}

Window::~Window ()
{
	if (window)
	{
		glfwDestroyWindow (window);
		windowCount--;
	}

	if (windowCount == 0)
	{
		terminateGLFW ();
	}
}

void Window::initGLFW ()
{
	if (!glfwInitialized)
	{
		glfwSetErrorCallback (glfwErrorCallback);
		if (!glfwInit ())
		{
			throw std::runtime_error ("Failed to initialize GLFW");
		}
		glfwInitialized = true;
	}
}

void Window::terminateGLFW ()
{
	if (glfwInitialized && windowCount == 0)
	{
		glfwTerminate ();
		glfwSetErrorCallback (nullptr);
		glfwInitialized = false;
	}
}

bool Window::shouldClose () const
{
	return window ? glfwWindowShouldClose (window) : true;
}

void Window::swapBuffers ()
{
	if (window)
		glfwSwapBuffers (window);
}

void Window::pollEvents ()
{
	glfwPollEvents ();
}

} // namespace Ovorldule