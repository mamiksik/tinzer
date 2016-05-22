//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_CLOG_H
#define KETCHUPHOUSE_CLOG_H

#include <cstdio>
#include <cstdarg>

class Log
{
public:
	enum
	{
		All = 0, Debug, Info, Warning, Error
	};

	static void dump(int logLevel, const char *string, ...);

protected:
	static int logLevel();
};

#endif //KETCHUPHOUSE_CLOG_H
