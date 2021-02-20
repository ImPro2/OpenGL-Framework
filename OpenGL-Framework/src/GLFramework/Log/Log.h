#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace GLFramework {

	class Log
	{
	public:
		static bool Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define CORE_TRACE(...) ::GLFramework::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)  ::GLFramework::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)  ::GLFramework::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) ::GLFramework::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) ::GLFramework::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define LOG_TRACE(...) ::GLFramework::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)  ::GLFramework::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)  ::GLFramework::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::GLFramework::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::GLFramework::Log::GetClientLogger()->critical(__VA_ARGS__)