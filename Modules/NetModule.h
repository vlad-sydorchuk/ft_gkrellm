//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_NETMODULE_H
#define RUSH01_NETMODULE_H

#include "AInfo.h"

class NetModule : public AInfo<std::string*> {
public:
	NetModule();
	~NetModule();
	NetModule(NetModule const & copy);
	NetModule &operator=(NetModule const & copy);
	void updateModule();
};


#endif //RUSH01_NETMODULE_H
