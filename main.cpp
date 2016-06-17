#include <iostream>
#include <thread>


#include "app/threads/Boostrap.h"


using namespace std;

int main(int argc, char *argv[])
{
	Boostrap boostrap;

	boostrap.init();
	return 0;
}