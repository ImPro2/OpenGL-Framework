#include "Window.h"

#include <glad/glad.h>

namespace GLFramework {

	Window::Window()
	{
	}

	Window::~Window()
	{
	}

	void Window::Init(WindowData data)
	{
		m_Data = data;

		Create();
	}

	void Window::Init()
	{
		m_Data.Height = 600;
		m_Data.Width = 800;
		m_Data.Title = "OpenGL Framework";
		m_Data.isVSync = false;

		Create();
	}

	void Window::Create()
	{
		GLFR_CORE_ASSERT(glfwInit(), "Failed to initialize GLFW");
		CORE_INFO("Successfully Initialized GLFW");

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, nullptr, nullptr);

		GLFR_CORE_ASSERT(m_Window != NULL, "Failed to Initialize window");

		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GLFR_CORE_ASSERT(status, "Failed to initialize Glad");
		CORE_INFO("Successfully initialized Glad");

		SetVSync(m_Data.isVSync);

		CORE_INFO("Successfully Created Window {0}: Width: {1}, Height: {2}, VSync: {3}", m_Data.Title, m_Data.Width, m_Data.Height, m_Data.isVSync);
	}

	void Window::Update()
	{
		Present();
		PollEvents();
	}

	void Window::SetTitle(const char* title)
	{
		glfwSetWindowTitle(m_Window, title);
	}

	void Window::SetSize(GlfrVec2u size)
	{
		glfwSetWindowSize(m_Window, size.x, size.y);
	}

	void Window::SetVSync(bool isVSync)
	{
		if (isVSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void Window::Present()
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

}