#pragma once
#include <string>

class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain();
	Brain(const Brain &src);
	~Brain();

	Brain &operator=(const Brain &src);

	void setIdea(const std::string idea, int index);

	std::string getIdea(int index) const;
};