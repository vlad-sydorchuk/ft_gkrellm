//
// Created by Illia Lukianov on 11/11/17.
//

#ifndef RUSH01_USERINFO_H
#define RUSH01_USERINFO_H


#include "AInfo.h"

class UserModule : public AInfo<std::string*> {
public:
	UserModule();
	~UserModule();
	UserModule(UserModule const & copy);
	UserModule &operator=(UserModule const & copy);
	void		updateModule();
private:

};


#endif //RUSH01_USERINFO_H
