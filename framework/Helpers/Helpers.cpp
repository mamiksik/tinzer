//
// Created by Martin Mikšík
//

#include "Helpers.h"

#include <chrono>
#include <thread>
#include <stdio.h>
#include <stdarg.h>
#include <fstream>
#include <sstream>

#include "../../app/Config.h"


void Helpers::delay(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


void Helpers::dump(int logLevel, const char *string, ...)
{
	if (logLevel >= LOG_LEVEL) {
		va_list args;
		va_start(args, string);

		switch (logLevel) {
			case Helpers::Debug:
				printf(ANSI_COLOR_GREEN);
				break;

			case Helpers::Info:
				printf(ANSI_COLOR_CYAN);
				break;

			case Helpers::Warning:
				printf(ANSI_COLOR_YELLOW);
				break;

			case Helpers::Error:
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


vector<Structure::Coordinate> Helpers::loadData(std::string path)
{
	vector<Structure::Coordinate> data;

	ifstream file(path);
	string str;
	while (getline(file, str)) {

		istringstream stream(str);
		int x;
		int y;
		double rotation;

		stream >> x;
		stream >> y;
		stream >> rotation;

		data.push_back(Structure::Coordinate(x, y, rotation));
	}

	return data;
}