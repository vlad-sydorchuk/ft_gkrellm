//
// Created by Illia Lukianov on 11/12/17.
//

#include "OsModule.h"
#include <assert.h>

OsModule::OsModule() : AInfo<std::string*>::AInfo("OsInfo"){
	info = new std::string[3]();
	updateModule();
}

OsModule::~OsModule() {

}

OsModule::OsModule(OsModule const & copy) {
	*this = copy;
}

OsModule & OsModule::operator=(OsModule const &copy) {
	this->info = copy.info;
	this->moduleName = copy.moduleName;
	return *this;
}

void	OsModule::updateModule() {
	char line[256];
	int i = 0;

	FILE *sw_vers = popen("sw_vers", "r");
	while (fgets(line, sizeof(line), sw_vers) != NULL) {
		if (i > 2)
			break;
		info[i] = std::string(line);
		i++;
	}
	pclose(sw_vers);
}