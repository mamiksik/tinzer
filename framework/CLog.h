//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_CLOG_H
#define KETCHUPHOUSE_CLOG_H


#include <cstdarg>
#include <iostream>
#include "../app/Config.h"

class CLog
{
public:
	CLog();

	enum
	{
		All = 0, Debug, Info, Warning, Error, Fatal, None
	};

	//static void write(int level, const std::string message);
};


#endif //KETCHUPHOUSE_CLOG_H
