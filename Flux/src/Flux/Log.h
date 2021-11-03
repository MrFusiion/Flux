#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Flux {

	class FLUX_API Log
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

#ifdef FLUX_DEBUG
	// Core log macros
	#define FLUX_CORE_TRACE(...)    ::Flux::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define FLUX_CORE_INFO(...)     ::Flux::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define FLUX_CORE_WARN(...)     ::Flux::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define FLUX_CORE_ERROR(...)    ::Flux::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define FLUX_CORE_FATAL(...)    ::Flux::Log::GetCoreLogger()->critical(__VA_ARGS__)

	// Client log macros
	#define FLUX_TRACE(...)	      ::Flux::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define FLUX_INFO(...)	      ::Flux::Log::GetClientLogger()->info(__VA_ARGS__)
	#define FLUX_WARN(...)	      ::Flux::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define FLUX_ERROR(...)	      ::Flux::Log::GetClientLogger()->error(__VA_ARGS__)
	#define FLUX_FATAL(...)	      ::Flux::Log::GetClientLogger()->critical(__VA_ARGS__)

	#ifdef FLUX_ENABLE_ASSERTS
		#define FLUX_ASSERT(x, ...) { if(!(x)) { FLUX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define FLUX_CORE_ASSERT(x, ...) { if(!(x)) { FLUX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#else
		#define FLUX_ASSERT(x, ...)
		#define FLUX_CORE_ASSERT(x, ...)
	#endif
#else
	#define FLUX_CORE_TRACE(...)
	#define FLUX_CORE_INFO(...)
	#define FLUX_CORE_WARN(...)
	#define FLUX_CORE_ERROR(...)
	#define FLUX_CORE_FATAL(...)
	#define FLUX_TRACE(...)
	#define FLUX_INFO(...)  
	#define FLUX_WARN(...)
	#define FLUX_ERROR(...)
	#define FLUX_FATAL(...)
	#define FLUX_ASSERT(x, ...)
	#define FLUX_CORE_ASSERT(x, ...)
#endif