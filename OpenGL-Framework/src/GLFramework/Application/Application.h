#pragma once

#include "GLFramework/Window/Window.h"

namespace GLFramework {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		void Destroy();

		// accessors
		inline Window GetWindow() { return m_Window; }
		inline static Application* GetInstance() { return s_Instance; }

	private:
		bool m_IsRunning;
		Window m_Window;

		static Application* s_Instance;
	};

	// Functions for CLIENT to use

	// accessors
	GlfrVec2u GetWindowSize();
	const char* GetWindowTitle();
	bool GetWindowVSync();

	// setters
	void SetWindowSize(GlfrVec2u size);
	void SetWindowTitle(const char* title);
	void SetWindowVSync(bool enabled);

	// Defined in CLIENT
	void OnCreate();
	void OnUpdate();
	void OnEvent();
	void OnDestroy();

}