//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_ADISPLAY_H
#define RUSH01_ADISPLAY_H

#include "IDisplayModules.h"
#include <string>
class UserModule;
class OsModule;
class DataModule;
class CpuModule;
class RamModule;
class NetModule;

class ADisplay : public IDisaplyModules {
public:
	ADisplay() {};
	ADisplay(std::string dispName) : dispName(dispName) {};
	virtual ~ADisplay() {};
	std::string getModuleName() {
		return this->dispName;
	};
	virtual void dispInit() = 0;

protected:
	std::string	dispName;
	UserModule *host;
	OsModule *os;
	DataModule *data;
	CpuModule *cpu;
	RamModule *ram;
	NetModule *net;
};


#endif //RUSH01_ADISPLAY_H
