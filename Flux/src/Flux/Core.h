#pragma once

#ifdef FLUX_PLATFORM_WINDOWS
	#ifdef FLUX_BUILD_DLL
		#define FLUX_API __declspec(dllexport)
	#else
		#define FLUX_API __declspec(dllimport)
	#endif
#else
	#error Flux only supports Windows!
#endif

#define BIT(x) (1 << x)

#define FLUX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#define FLUX_BOOL_STR(b) (std::string)(b ? "True" : "False")