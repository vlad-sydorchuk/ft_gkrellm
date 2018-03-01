//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_OSMODULE_H
#define RUSH01_OSMODULE_H

#include "AInfo.h"

class OsModule : public AInfo<std::string*> {
public:
	OsModule();
	~OsModule();
	OsModule(OsModule const & copy);
	OsModule &operator=(OsModule const & copy);
	void 	updateModule();
};


#endif //RUSH01_OSMODULE_H
