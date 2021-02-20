#include "Application.h"

namespace GLFramework {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;

		// initialize m_IsRunning with true so that the window doesn't close
		m_IsRunning = true;

		// initialize the window
		m_Window.Init();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		OnCreate();

		while (m_IsRunning)
		{
			// make sure the window is open
			m_IsRunning = m_Window.IsOpen();

			// update the window
			m_Window.Update();

			// Update the client
			OnUpdate();

			// Process Events in client
			OnEvent();
		}
	}

	void Application::Destroy()
	{
		OnDestroy();
	}

	// non application stuff
	GlfrVec2u GetWindowSize()
	{
		uint32_t width = Application::GetInstance()->GetWindow().GetData().Width;
		uint32_t height = Application::GetInstance()->GetWindow().GetData().Height;

		return  { width, height };
	}

	const char* GetWindowTitle()
	{
		return Application::GetInstance()->GetWindow().GetData().Title;
	}

	bool GetWindowVSync()
	{
		return Application::GetInstance()->GetWindow().GetData().isVSync;
	}

	void SetWindowSize(GlfrVec2u size)
	{
		Application::GetInstance()->GetWindow().SetSize(size);
	}

	void SetWindowTitle(const char* title)
	{
		Application::GetInstance()->GetWindow().SetTitle(title);
	}

	void SetWindowVSync(bool enabled)
	{
		Application::GetInstance()->GetWindow().SetVSync(enabled);
	}
}