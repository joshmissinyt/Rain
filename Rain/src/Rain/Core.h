#pragma once

#ifdef RN_PLATFORM_WINDOWS
	#ifdef RN_BUILD_DLL
		#define RAIN_API __declspec(dllexport)
	#else
		#define RAIN_API __declspec(dllimport)
	#endif
#else
	#error Rain only supports Windows!
#endif

#ifdef RN_DEBUG
	#define RN_ENABLE_ASSERTS
#endif

#ifdef RN_ENABLE_ASSERTS
	#define RN_ASSERT(x, ...) { if (!(x)) { RN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RN_CORE_ASSERT(x, ...) { if (!(x)) { RN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RN_ASSERT(x, ...)
	#define RN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)