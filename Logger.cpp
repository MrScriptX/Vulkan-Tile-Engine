#include "Logger.h"


Logger::Logger()
{
}

void Logger::start()
{
	std::fstream file;

	try
	{
		file.open("Log/log.txt", std::fstream::out | std::fstream::trunc);
		file.close();
	}
	catch(std::ios_base::iostate& error)
	{
		throw std::runtime_error("log.txt couldn't be opened!");
	}
}

void Logger::registerError(std::string& error)
{
	std::fstream file;

	try
	{
		file.open("Log/log.txt", std::fstream::out | std::fstream::rdstate | std::fstream::app);
		file << &error;
		file.close();
	}
	catch (std::ios_base::iostate& error)
	{
		throw std::runtime_error("log.txt couldn't be opened!");
	}
}