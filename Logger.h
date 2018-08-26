#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>
#include <fstream>
#include <memory>



class Logger
{
public:
	Logger();

	static void start();
	static void registerError(std::string& error);
};

#endif //!_LOGGER_H