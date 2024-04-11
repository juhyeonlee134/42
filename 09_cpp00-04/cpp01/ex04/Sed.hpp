#pragma once
#ifndef __SED_H__
#define __SED_H__

#include <string>

class Sed
{
private:
	std::string mInputStr;
	std::string mReplaceStr;
	std::string convert(std::string &orgStr);
public:
	Sed(std::string inputStr, std::string replaceStr);
	~Sed();
	void ConvertString(std::string fileName);
};

#endif