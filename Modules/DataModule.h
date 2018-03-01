//
// Created by Illia Lukianov on 11/12/17.
//

#ifndef RUSH01_DATAMODULE_H
#define RUSH01_DATAMODULE_H

#include "AInfo.h"

class DataModule : public AInfo<std::string*> {
public:
	DataModule();
	~DataModule();
	DataModule(DataModule const & copy);
	DataModule &operator=(DataModule const & copy);
	void updateModule();
};


#endif //RUSH01_DATAMODULE_H
