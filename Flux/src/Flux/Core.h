#pragma once

#ifdef F_PLATFORM_WINDOWS
	#ifdef F_BUILD_DLL
		#define FLUX_API __declspec(dllexport)
	#else
		#define FLUX_API __declspec(dllimport)
	#endif
#else
	#error Flux only supports Windows!
#endif