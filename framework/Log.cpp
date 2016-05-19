//
// Created by Martin Mikšík
//

#include <iostream>
#include "Log.h"
#include "../app/Config.h"

void Log::dump(int logLevel, const char *szFormat, ...)
{
	if (logLevel >= LOG_LEVEL) {
		va_list args;
		va_start(args, szFormat);

		while (*szFormat != '\0') {
			if (*szFormat == 'd') {
				int i = va_arg(args, int);
				std::cout << i << '\n';
			} else if (*szFormat == 'c') {
				// note automatic conversion to integral type
				int c = va_arg(args, int);
				std::cout << static_cast<char>(c) << '\n';
			} else if (*szFormat == 'f') {
				double d = va_arg(args, double);
				std::cout << d << '\n';
			}
			++szFormat;
		}

		va_end(args);
	}
}

int Log::logLevel()
{
	return LOG_LEVEL;
}