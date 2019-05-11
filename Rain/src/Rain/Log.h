#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Rain {

	class RN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Logging Macros
#define RN_CORE_TRACE(...)    ::Rain::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RN_CORE_INFO(...)     ::Rain::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RN_CORE_WARN(...)     ::Rain::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RN_CORE_ERROR(...)    ::Rain::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RN_CORE_CRITICAL(...) ::Rain::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logging Macros
#define RN_TRACE(...)    ::Rain::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RN_INFO(...)     ::Rain::Log::GetClientLogger()->info(__VA_ARGS__)
#define RN_WARN(...)     ::Rain::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RN_ERROR(...)    ::Rain::Log::GetClientLogger()->error(__VA_ARGS__)
#define RN_CRITICAL(...) ::Rain::Log::GetClientLogger()->critical(__VA_ARGS__)