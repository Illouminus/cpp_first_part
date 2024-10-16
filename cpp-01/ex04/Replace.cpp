#include "Replace.hpp"
#include <iostream>

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2) : filename(filename), s1(s1), s2(s2) {};

void Replace::execute() const
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << " for reading." << std::endl;
		return;
	}

	std::string new_filename = filename + ".replace";

	std::ofstream outfile(new_filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot open file " << new_filename << " for writing." << std::endl;
		infile.close();
		return;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();
}