/*
 * Copyright 2025 Forge-of-Ovorldule and Mr_Soul-Forest(https://github.com/Mr-Soul-Forest)
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
#include <functional>
#include "Vectors.h"
#include "WindowParameters.h"

namespace Ovorldule
{
class Window
{
	public:
		using CloseCallback = std::function<void ()>;

		bool m_isFullscreen = false;
		Vector2i m_windowedSize;
		Vector2i m_windowedPos;

		explicit Window (const WindowParameters& params = WindowParameters ());
		~Window ();

		void setSize (const Vector2i& size);
		void setSize (const int& width, const int& height);
		void setSize (const int& size);
		void setSize (const WindowParameters& params = WindowParameters ());
		void setResizable (bool resizable);

		const bool isOpen () const;

		void setTitle (const std::string title);
		void setTitle (const WindowParameters& params = WindowParameters ());

		const Vector2i getSize () const;
		const int getWidth () const;
		const int getHeight () const;

		void work ();

		void close ();
		void setCloseCallback (CloseCallback callback);

		void setFullscreen (bool fullscreen);
		void toggleFullscreen ();

		Window (const Window&) = delete;
		Window& operator= (const Window&) = delete;

	private:
		GLFWwindow* m_window = nullptr;

		static bool m_glfwInitialized;
		static int m_windowCount;

		CloseCallback m_onClose = nullptr;

		void swapBuffers ();
		void pollEvents ();

		bool shouldClose () const;

		static void initGLFW ();
		static void terminateGLFW ();

		Window (int width, int height, const std::string& title);
};
} // namespace Ovorldule