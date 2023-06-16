#include "Log.h"

Log& Log::Get()
{
	static Log log;
	return log;
}
Log::Log()
{
	spdlog::set_pattern("%^[%T] [%n] %v%$");
	m_Logger = spdlog::stdout_color_mt("EasyGL");
	m_Logger->set_level(spdlog::level::debug);
	spdlog::set_pattern("%^[%T] [%n] %v%$");
	m_CoreLogger = spdlog::stdout_color_mt("EasyGL");
	m_CoreLogger->set_level(spdlog::level::debug);
}
Log::~Log()
{
}