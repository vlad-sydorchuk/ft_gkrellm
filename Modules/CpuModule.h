//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_CPUMODULE_H
#define RUSH01_CPUMODULE_H

#include "AInfo.h"

class CpuModule : public AInfo<std::string*> {
public:
	CpuModule();
	~CpuModule();
	CpuModule(CpuModule const & copy);
	CpuModule &operator=(CpuModule const & copy);
	void updateModule();
};


#endif //RUSH01_CPUMODULE_H
