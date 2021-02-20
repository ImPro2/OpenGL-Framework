#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

#include "GLFramework/Core.h"

namespace GLFramework {

	struct WindowData
	{
		uint32_t Width;
		uint32_t Height;
		const char* Title;
		bool isVSync;
	};

	class Window
	{
	public:
		Window();
		~Window();

		void Init(WindowData data);
		void Init();

		void Update();

		// setters
		void SetTitle(const char* title);
		void SetSize(GlfrVec2u size);
		void SetVSync(bool isVSync);

		// accessors
		inline WindowData GetData() const { return m_Data; }
		inline GLFWwindow* GetNativeWindow() const { return m_Window; }
		
		// return true if the window is open
		inline bool IsOpen() const { return !glfwWindowShouldClose(m_Window); }

	private:
		// private methods
		void Create();
		void Present();
		void PollEvents();

	private:
		WindowData m_Data;

		GLFWwindow* m_Window;
	};

}