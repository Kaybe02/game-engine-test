#pragma once

#include <memory>


#include "Core.h"
#include "spdlog/spdlog.h"

namespace Kaybe {

	class KAYBE_API Log
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


//Core log macros
#define KB_CORE_ERROR(...)	     ::Kaybe::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KB_CORE_WARN(...)        ::Kaybe::Log::GetCoreLogger()->warn(__VA_ARGS__)	
#define KB_CORE_INFO(...)        ::Kaybe::Log::GetCoreLogger()->info(__VA_ARGS__)	
#define KB_CORE_TRACE(...)       ::Kaybe::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KB_CORE_FATAL(...)       ::Kaybe::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define KB_ERROR(...)			 ::Kaybe::Log::GetClientLogger()->error(__VA_ARGS__)
#define KB_WARN(...)			 ::Kaybe::Log::GetClientLogger()->warn(__VA_ARGS__)	
#define KB_INFO(...)			 ::Kaybe::Log::GetClientLogger()->info(__VA_ARGS__)	
#define KB_TRACE(...)			 ::Kaybe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KB_FATAL(...)			 ::Kaybe::Log::GetClientLogger()->fatal(__VA_ARGS__)


