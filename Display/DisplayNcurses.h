//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_DISPLAYNCURSES_H
#define RUSH01_DISPLAYNCURSES_H


#include "ADisplay.h"
#include "ncurses.h"

typedef struct {
	int x;
	int y;
} cordScreen;

class DisplayNcurses : public ADisplay {
public:
	DisplayNcurses();
	~DisplayNcurses();
	void	dispInit();
	void	displayModules();
	void	updateDisplayInfo();
	void	displayOneModule();
	void	displayHostModule();
	void	displayOsModule();
	void	displayDataModule();
	void	displayCpuModule();
	void	displayRamModule();
	void	displayNetModule();
	void	displayMenu();
	DisplayNcurses(DisplayNcurses const & copy);
	DisplayNcurses &operator=(DisplayNcurses const & copy);

private:
	cordScreen Screen;
};


#endif //RUSH01_DISPLAYNCURSES_H
