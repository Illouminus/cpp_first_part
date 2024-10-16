#pragma once
#include <string>
#include <fstream>

class Replace
{
private:
	std::string filename;
	std::string s1;
	std::string s2;

public:
	Replace(const std::string &filename, const std::string &s1, const std::string &s2);
	void execute() const;
};