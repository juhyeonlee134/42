#include "Sed.hpp"
#include <iostream>
#include <fstream>

std::string Sed::convert(std::string &orgStr)
{
	size_t fIndex;

	while (1)
	{
		fIndex = orgStr.find(this->mInputStr);
		if (fIndex == std::string::npos)
		{
			break;
		}
		std::string prev = orgStr.substr(0, fIndex);
		std::string next = orgStr.substr(fIndex + this->mInputStr.length(), orgStr.length());
		orgStr = prev + this->mReplaceStr + next;
	}
	return orgStr;
}

Sed::Sed(std::string inputStr, std::string replaceStr)
	: mInputStr(inputStr),
	mReplaceStr(replaceStr)
{}

Sed::~Sed()
{}

void Sed::ConvertString(std::string fileName)
{
	std::ifstream orgFile;
	std::ofstream repFile;
	std::string repFileName = fileName + ".replace";
	std::string line;

	orgFile.open(fileName.c_str(), std::ios_base::in);
	if (!orgFile.is_open())
	{
		std::cerr << "Error: not found file" << std::endl;
		return;
	}
	repFile.open(repFileName.c_str(), std::ios_base::out | std::ios_base::trunc);
	while (std::getline(orgFile, line))
	{
		repFile << convert(line) << std::endl;
	}
}
