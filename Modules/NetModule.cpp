//
// Created by Illia Lukianov on 11/12/17.
//

#include "NetModule.h"

NetModule::NetModule() : AInfo<std::string*>::AInfo("RamModule"){
	info = new std::string;
	updateModule();
}

NetModule::~NetModule() {

}

NetModule::NetModule(NetModule const & copy) {
	*this = copy;
}

NetModule & NetModule::operator=(NetModule const &copy) {
	this->info = copy.info;
	this->moduleName = copy.moduleName;
	return *this;
}

void NetModule::updateModule() {
	FILE *in;
	char buffer[BUFFERLEN];
	if (!(in = popen("top -l 1 | grep -E \"^Networks\"", "r"))) {
		throw std::exception();
	}
	while (fgets(buffer, sizeof(buffer), in) != NULL) {
		info[0] = std::string(buffer);
		break ;
	}
	pclose(in);
}