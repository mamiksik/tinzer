#include "app/threads/Bootstrap.h"

INIReader reader("settings.ini");

int main(int argc, char *argv[])
{
	Bootstrap bootstrap;

	bootstrap.init();
	return 0;
}