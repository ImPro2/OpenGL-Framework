#pragma once

#include "Application/Application.h"
#include "Log/Log.h"

extern void GLFramework::OnCreate();
extern void GLFramework::OnUpdate();
extern void GLFramework::OnEvent();
extern void GLFramework::OnDestroy();

int main()
{
	GLFramework::Log::Init();
	CORE_INFO("Successfully initialized Log");


	auto app = new GLFramework::Application();
	app->Run();
	app->Destroy();
}