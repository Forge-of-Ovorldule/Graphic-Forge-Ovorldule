#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace Ovorldule
{

class Window
{
	public:
		Window (int width, int height, const std::string& title);
		~Window ();

		bool shouldClose () const;
		void swapBuffers ();
		void pollEvents ();

	private:
		GLFWwindow* window;

		static void initGLFW ();
		static void terminateGLFW ();
		static bool glfwInitialized;
};

} // namespace Ovorldule