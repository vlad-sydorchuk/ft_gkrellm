//
// Created by Illia Lukianov on 11/11/17.
//

#ifndef RUSH01_INFO_H
#define RUSH01_INFO_H


#include <string>
#include <sys/sysctl.h>
#include "IModule.h"

template <class T>
class AInfo : public IModule {
public:
	AInfo() {};
	AInfo(std::string moduleName) : moduleName(moduleName) {};
	virtual ~AInfo() {};
	std::string getModuleName() {
		return this->moduleName;
	}
	T			getInfo() {
		return this->info;
	}
	void				deleteInfo() {
		delete [] info;
		info = nullptr;
	}
	virtual void		updateModule() = 0;

protected:
	std::string moduleName;
	T info;

};


#endif //RUSH01_INFO_H
