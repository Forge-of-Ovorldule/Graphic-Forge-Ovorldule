#include "../../include/OvorlduleGraphics/Window.h"
#include <stdexcept>
#include <iostream>

namespace Ovorldule
{

bool Window::m_glfwInitialized = false;
int Window::m_windowCount = 0;

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

	m_window = glfwCreateWindow (width, height, title.c_str (), nullptr, nullptr);
	if (!m_window)
	{
		throw std::runtime_error ("Failed to create GLFW window");
	}

	glfwMakeContextCurrent (m_window);
	m_windowCount++;
}

Window::~Window ()
{
	if (m_window)
	{
		glfwDestroyWindow (m_window);
		m_windowCount--;
	}

	if (m_windowCount == 0)
	{
		terminateGLFW ();
	}
}

void Window::initGLFW ()
{
	if (!m_glfwInitialized)
	{
		glfwSetErrorCallback (glfwErrorCallback);
		if (!glfwInit ())
		{
			throw std::runtime_error ("Failed to initialize GLFW");
		}
		m_glfwInitialized = true;
	}
}

void Window::terminateGLFW ()
{
	if (m_glfwInitialized && m_windowCount == 0)
	{
		glfwTerminate ();
		glfwSetErrorCallback (nullptr);
		m_glfwInitialized = false;
	}
}

bool Window::shouldClose () const
{
	return m_window ? glfwWindowShouldClose (m_window) : true;
}

void Window::swapBuffers ()
{
	if (m_window)
		glfwSwapBuffers (m_window);
}

void Window::pollEvents ()
{
	glfwPollEvents ();
}

void Window::setSize (const Vector2i& size)
{
	glfwSetWindowSize (m_window, size.width (), size.height ());
}
void Window::setSize (const int& width, const int& height)
{
	glfwSetWindowSize (m_window, width, height);
}
void Window::setSize (const int& size)
{
	glfwSetWindowSize (m_window, size, size);
}

} // namespace Ovorldule