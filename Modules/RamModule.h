//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_RAMMODULE_H
#define RUSH01_RAMMODULE_H

#include "AInfo.h"

class RamModule : public AInfo<std::string*> {
public:
	RamModule();
	~RamModule();
	RamModule(RamModule const & copy);
	RamModule &operator=(RamModule const & copy);
	void updateModule();
};


#endif //RUSH01_RAMMODULE_H
