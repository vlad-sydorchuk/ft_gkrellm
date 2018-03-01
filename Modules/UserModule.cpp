//
// Created by Illia Lukianov on 11/11/17.
//

#include <iostream>
#include <zconf.h>
#include "UserModule.h"

UserModule::UserModule() : AInfo<std::string*>::AInfo("UserHostModule") {
	info = new std::string[2]();
	updateModule();
}

UserModule::~UserModule() {

}

UserModule::UserModule(UserModule const & copy) {
	*this = copy;
}

UserModule & UserModule::operator=(UserModule const &copy) {
	this->info = copy.info;
	this->moduleName = copy.moduleName;
	return *this;
}

void 	UserModule::updateModule() {
	char hostname[BUFFERLEN];
	char username[BUFFERLEN];

	gethostname(hostname, BUFFERLEN);
	getlogin_r(username, BUFFERLEN);

	info[0] = "Host Name: ";
	info[0] += std::string(hostname);
	info[1] = "User Name: ";
	info[1] += std::string(username);
}