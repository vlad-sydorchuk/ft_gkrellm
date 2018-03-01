//
// Created by Illia Lukianov on 11/12/17.
//

#include "DisplayNcurses.h"

#include "../Modules/UserModule.h"
#include "../Modules/OsModule.h"
#include "../Modules/DataModule.h"
#include "../Modules/CpuModule.h"
#include "../Modules/RamModule.h"
#include "../Modules/NetModule.h"

DisplayNcurses::DisplayNcurses(DisplayNcurses const & copy) {
	*this = copy;
}

DisplayNcurses & DisplayNcurses::operator=(DisplayNcurses const &copy) {
	this->host = copy.host;
	this->os = copy.os;
	this->data = copy.data;
	this->cpu = copy.cpu;
	this->ram = copy.ram;
	this->net = copy.net;

	return *this;
}

DisplayNcurses::DisplayNcurses() : ADisplay::ADisplay("Ncurses") {
	dispInit();
}

DisplayNcurses::~DisplayNcurses() {

}

void	DisplayNcurses::dispInit() {
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	initscr();
	cbreak();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	scrollok(stdscr, TRUE);
	halfdelay(1);
	nodelay(stdscr, TRUE);
	getmaxyx(stdscr, Screen.y, Screen.x);
	clear();
	box(stdscr, 0, 0);
	host = new UserModule;
	os = new OsModule;
	data = new DataModule;
	cpu = new CpuModule;
	ram = new RamModule;
	net = new NetModule;
	displayOneModule();
//	displayModules();
	refresh();
}

void	DisplayNcurses::displayHostModule() {
	int in_char;
	while (1) {
		in_char = wgetch(stdscr);
		clear();
		if (in_char == 'b')
			return;
		updateDisplayInfo();
		mvwprintw(stdscr, Screen.y / 2 - 7, Screen.x / 2 - 15, host->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 - 6, Screen.x / 2 - 15, host->getInfo()[1].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 40, "b: Back to menu");
		refresh();
	}
}

void	DisplayNcurses::displayOsModule() {
	int in_char;
	while (1) {
		in_char = wgetch(stdscr);
		clear();
		if (in_char == 'b')
			return;
		updateDisplayInfo();
		mvwprintw(stdscr, Screen.y / 2 - 4, Screen.x / 2 - 15, os->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 - 3, Screen.x / 2 - 15, os->getInfo()[1].c_str());
		mvwprintw(stdscr, Screen.y / 2 - 2, Screen.x / 2 - 15, os->getInfo()[2].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 40, "b: Back to menu");
		refresh();
	}
}

void	DisplayNcurses::displayDataModule() {
	int in_char;
	while (1) {
		in_char = wgetch(stdscr);
		clear();
		if (in_char == 'b')
			return;
		updateDisplayInfo();
		mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 15, data->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 40, "b: Back to menu");
		refresh();
	}
}

void	DisplayNcurses::displayCpuModule() {
	int in_char;
	while (1) {
		in_char = wgetch(stdscr);
		clear();
		if (in_char == 'b')
			return;
		updateDisplayInfo();
		mvwprintw(stdscr, Screen.y / 2 + 2, Screen.x / 2 - 15, cpu->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 4, Screen.x / 2 - 15, cpu->getInfo()[1].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 5, Screen.x / 2 - 15, cpu->getInfo()[2].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 15, cpu->getInfo()[3].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 40, "b: Back to menu");
		refresh();
	}
}

void	DisplayNcurses::displayRamModule() {
	int in_char;
	while (1) {
		in_char = wgetch(stdscr);
		clear();
		if (in_char == 'b')
			return;
		updateDisplayInfo();
		mvwprintw(stdscr, Screen.y / 2 + 8, Screen.x / 2 - 15, ram->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 40, "b: Back to menu");
		refresh();
	}
}

void	DisplayNcurses::displayNetModule() {
	int in_char;
	while (1) {
		in_char = wgetch(stdscr);
		clear();
		if (in_char == 'b')
			return;
		updateDisplayInfo();
		mvwprintw(stdscr, Screen.y / 2 + 10, Screen.x / 2 - 15, net->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 40, "b: Back to menu");
		refresh();
	}
}

void	DisplayNcurses::displayMenu() {
	mvwprintw(stdscr, Screen.y / 2 - 7, Screen.x / 2 - 40, "Menu: ");
	mvwprintw(stdscr, Screen.y / 2 - 6, Screen.x / 2 - 40, "1: Name User/Host");
	mvwprintw(stdscr, Screen.y / 2 - 5, Screen.x / 2 - 40, "2: OS Name");
	mvwprintw(stdscr, Screen.y / 2 - 4, Screen.x / 2 - 40, "3: Data");
	mvwprintw(stdscr, Screen.y / 2 - 3, Screen.x / 2 - 40, "4: Cpu");
	mvwprintw(stdscr, Screen.y / 2 - 2, Screen.x / 2 - 40, "5: Ram");
	mvwprintw(stdscr, Screen.y / 2 - 1, Screen.x / 2 - 40, "6: Net");
	mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 40, "7: All Modules");
	mvwprintw(stdscr, Screen.y / 2 + 1, Screen.x / 2 - 40, "q: Quit");
}
void	DisplayNcurses::displayOneModule() {
	int in_char;
	while (1) {
		displayMenu();
		in_char = wgetch(stdscr);
		updateDisplayInfo();
		if (in_char == '1') {
			clear();
			mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 20, "LOADING...");
			refresh();
			displayHostModule();
		} else if (in_char == '2') {
			clear();
			mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 20, "LOADING...");
			refresh();
			displayOsModule();
		} else if (in_char == '3') {
			clear();
			mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 20, "LOADING...");
			refresh();
			displayDataModule();
		} else if (in_char == '4') {
			clear();
			mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 20, "LOADING...");
			refresh();
			displayCpuModule();
		} else if (in_char == '5') {
			clear();
			mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 20, "LOADING...");
			refresh();
			displayRamModule();
		} else if (in_char == '6') {
			clear();
			mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 20, "LOADING...");
			refresh();
			displayNetModule();
		} else if (in_char == '7') {
			clear();
			mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 20, "LOADING...");
			refresh();
			displayModules();
		} else if (in_char == 'q') {
			clear();
			refresh();
			exit(0);
		}
	}
}

void	DisplayNcurses::updateDisplayInfo() {
	host->updateModule();
	os->updateModule();
	data->updateModule();
	cpu->updateModule();
	ram->updateModule();
	net->updateModule();
}

void	DisplayNcurses::displayModules()  {
	int in_char;
	while (1) {
		in_char = wgetch(stdscr);
		clear();
		if (in_char == 'b')
			return;
		updateDisplayInfo();
		mvwprintw(stdscr, Screen.y / 2 - 7, Screen.x / 2 - 15, host->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 - 6, Screen.x / 2 - 15, host->getInfo()[1].c_str());
		mvwprintw(stdscr, Screen.y / 2 - 4, Screen.x / 2 - 15, os->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 - 3, Screen.x / 2 - 15, os->getInfo()[1].c_str());
		mvwprintw(stdscr, Screen.y / 2 - 2, Screen.x / 2 - 15, os->getInfo()[2].c_str());
		mvwprintw(stdscr, Screen.y / 2, Screen.x / 2 - 15, data->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 2, Screen.x / 2 - 15, cpu->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 4, Screen.x / 2 - 15, cpu->getInfo()[1].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 5, Screen.x / 2 - 15, cpu->getInfo()[2].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 15, cpu->getInfo()[3].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 8, Screen.x / 2 - 15, ram->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 10, Screen.x / 2 - 15, net->getInfo()[0].c_str());
		mvwprintw(stdscr, Screen.y / 2 + 6, Screen.x / 2 - 40, "b: Back to menu");
		refresh();
	}
}