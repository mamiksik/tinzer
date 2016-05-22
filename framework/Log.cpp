//
// Created by Martin Mikšík
//

#include <iostream>
#include <cstdarg>
#include "Log.h"
#include "../app/Config.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void Log::dump(int logLevel, const char *string, ...)
{
	if (logLevel >= LOG_LEVEL) {
		va_list args;
		va_start(args, string);

		switch (logLevel) {
			case Log::Debug:
				printf(ANSI_COLOR_GREEN);
				break;

			case Log::Info:
				printf(ANSI_COLOR_BLUE);
				break;

			case Log::Warning:
				printf(ANSI_COLOR_YELLOW);
				break;

			case Log::Error:
				printf(ANSI_COLOR_RED);
				break;

			default:
				break;
		}

		vprintf(string, args);
		printf(ANSI_COLOR_RESET "\n");
		va_end(args);
	}
}

int Log::logLevel()
{
	return LOG_LEVEL;
}