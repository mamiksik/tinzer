#include <iostream>
#include <thread>


#include "app/threads/Bootstrap.h"


using namespace std;

int main(int argc, char *argv[])
{
	Bootstrap bootstrap;

	bootstrap.init();
	return 0;
}