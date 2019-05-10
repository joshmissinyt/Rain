#pragma once

#ifdef RN_PLATFORM_WINDOWS
	#ifdef RN_BUILD_DLL
		#define RN_API __declspec(dllexport)
	#else
		#define RN_API __declspec(dllimport)
	#endif
#else
	#error Rain only supports Windows!
#endif