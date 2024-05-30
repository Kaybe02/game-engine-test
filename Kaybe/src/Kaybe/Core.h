#pragma once

#ifdef KB_PLATFORM_WINDOWS
	#ifdef KB_BUILD_DLL
		#define KAYBE_API __declspec(dllexport)
	#else
		#define KAYBE_API __declspec(dllimport)
	#endif
#else
	#error Kaybe only supports Windows!
#endif // 

