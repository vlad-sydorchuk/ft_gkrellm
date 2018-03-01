//
// Created by Illia Lukianov on 11/12/17.
//

#include "DataModule.h"
#include <ctime>

DataModule::DataModule() : AInfo<std::string*>::AInfo() {
	info = new std::string;
	updateModule();
}

DataModule::~DataModule() {

}

DataModule::DataModule(DataModule const & copy) {
	*this = copy;
}

DataModule & DataModule::operator=(DataModule const &copy) {
	this->info = copy.info;
	this->moduleName = copy.moduleName;
	return *this;
}

void DataModule::updateModule() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	info[0] = std::string(buf);
}
