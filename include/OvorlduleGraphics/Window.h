#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include "Vectors.h"
#include "WindowParameters.h"

namespace Ovorldule
{
class Window
{
	public:
		explicit Window (const WindowParameters& params = WindowParameters ());
		~Window ();

		bool shouldClose () const;
		void swapBuffers ();
		void pollEvents ();

		// Запрет копирования
		Window (const Window&) = delete;
		Window& operator= (const Window&) = delete;

	private:
		GLFWwindow* window = nullptr;

		static void initGLFW ();
		static void terminateGLFW ();
		static bool glfwInitialized;
		static int windowCount; // Счётчик окон

		// Приватный конструктор для делегирования
		Window (int width, int height, const std::string& title);
};
} // namespace Ovorldule