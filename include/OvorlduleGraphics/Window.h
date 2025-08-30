/*
 * Copyright 2025 Forge-of-Ovorldule
 * https://github.com/Forge-of-Ovorldule
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

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
		void setSize (const WindowParameters& params = WindowParameters ());

		void swapBuffers ();
		void pollEvents ();

		const bool isOpen () const;

		void setTitle (const std::string title);
		void setTitle (const WindowParameters& params = WindowParameters ());

		const Vector2i getSize () const;
		const int getWidth () const;
		const int getHeight () const;

		// Запрет копирования
		Window (const Window&) = delete;
		Window& operator= (const Window&) = delete;

	private:
		bool shouldClose () const;

		GLFWwindow* m_window = nullptr;

		static bool m_glfwInitialized;
		static int m_windowCount; // Счётчик окон

		static void initGLFW ();
		static void terminateGLFW ();

		// Приватный конструктор для делегирования
		Window (int width, int height, const std::string& title);
};
} // namespace Ovorldule