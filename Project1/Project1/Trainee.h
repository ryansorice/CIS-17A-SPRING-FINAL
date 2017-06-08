#pragma once
#include <string>


class Trainee
{
public:
	std::string _name;

	Trainee();
	Trainee(std::string name);
	~Trainee();

	std::string getName() { return _name; }
	std::string attack() { return getName() + " attacks with bare hands!"; } //change to player catch phrase
};

