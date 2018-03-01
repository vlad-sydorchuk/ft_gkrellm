//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_IMODULE_H
#define RUSH01_IMODULE_H

#include <iostream>
#define BUFFERLEN 256

class IModule {
public:
	virtual std::string getModuleName() = 0;
	virtual void		updateModule() = 0;
};

#endif //RUSH01_IMODULE_H
