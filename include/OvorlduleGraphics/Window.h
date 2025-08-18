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

		void setSize (const Vector2i& size);
		void setSize (const int& width, const int& height);
		void setSize (const int& size);

		bool shouldClose () const;
		void swapBuffers ();
		void pollEvents ();

		// Запрет копирования
		Window (const Window&) = delete;
		Window& operator= (const Window&) = delete;

	private:
		GLFWwindow* m_window = nullptr;

		static bool m_glfwInitialized;
		static int m_windowCount; // Счётчик окон

		static void initGLFW ();
		static void terminateGLFW ();

		// Приватный конструктор для делегирования
		Window (int width, int height, const std::string& title);
};
} // namespace Ovorldule