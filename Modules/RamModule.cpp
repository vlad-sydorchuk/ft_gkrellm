//
// Created by Illia Lukianov on 11/12/17.
//

#include "RamModule.h"

RamModule::RamModule() : AInfo<std::string*>::AInfo("RamModule"){
	info = new std::string;
	updateModule();
}

RamModule::~RamModule() {

}

RamModule::RamModule(RamModule const & copy) {
	*this = copy;
}

RamModule & RamModule::operator=(RamModule const &copy) {
	this->info = copy.info;
	this->moduleName = copy.moduleName;
	return *this;
}

void RamModule::updateModule() {
	FILE *in;
	char buffer[BUFFERLEN];
	if (!(in = popen("top -l 1 | grep -E \"^PhysMem\"", "r"))) {
		throw std::exception();
	}
	while (fgets(buffer, sizeof(buffer), in) != NULL) {
		info[0] = std::string(buffer);
		break ;
	}
	pclose(in);
}
