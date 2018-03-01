#include <iostream>
#include <stdio.h>
#include "ncurses.h"
#include "Display/DisplayNcurses.h"
#include <string.h>
#include "vizualization.cpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Give me only N or G" << std::endl;
		return (0);
	}
	if (strcmp(argv[1],"N") == 0)
		DisplayNcurses ncurs;
	else if (strcmp(argv[1],"G") == 0)
		vizualization();
	else {
		std::cout << "Give me only N or G" << std::endl;
		return (0);
	}
	return (0);
}
