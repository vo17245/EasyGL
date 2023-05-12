#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Log
{
public:
	~Log();
	static Log& Get();
	inline const std::shared_ptr<spdlog::logger>& GetLogger()const { return m_Logger; }
private:
	Log();
	std::shared_ptr<spdlog::logger> m_Logger;
};


//app log

#define INFO(...) Log::Get().GetLogger()->info(__VA_ARGS__)
#define ERROR(...) Log::Get().GetLogger()->error(__VA_ARGS__)
#define DEBUG(...) Log::Get().GetLogger()->debug(__VA_ARGS__)