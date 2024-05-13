#pragma once
#ifndef __BASE_H__
#define __BASE_H__

class Base
{
public:
	virtual ~Base();
	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif
