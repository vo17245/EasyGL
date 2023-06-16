#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Log
{
public:
	~Log();
	static Log& Get();
	inline const std::shared_ptr<spdlog::logger>& GetLogger()const { return m_Logger; }
	inline const std::shared_ptr<spdlog::logger>& GetCoreLogger()const {return m_CoreLogger;}
private:
	Log();
	std::shared_ptr<spdlog::logger> m_Logger;
	std::shared_ptr<spdlog::logger> m_CoreLogger;
};


//log

#define EZ_INFO(...) Log::Get().GetLogger()->info(__VA_ARGS__)
#define EZ_ERROR(...) Log::Get().GetLogger()->error(__VA_ARGS__)
#define EZ_DEBUG(...) Log::Get().GetLogger()->debug(__VA_ARGS__)

//core log

#define EZ_CORE_INFO(...) Log::Get().GetCoreLogger()->info(__VA_ARGS__)
#define EZ_CORE_ERROR(...) Log::Get().GetCoreLogger()->error(__VA_ARGS__)
#define EZ_CORE_DEBUG(...) Log::Get().GetCoreLogger()->debug(__VA_ARGS__)

