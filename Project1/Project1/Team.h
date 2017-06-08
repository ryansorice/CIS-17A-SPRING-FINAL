#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Trainee.h"

class Team
{
private:
	std::string _name;
	std::vector<std::shared_ptr<Trainee>> players;

public:
	std::vector<std::string> _history;

	Team(std::string name);
	~Team();

	std::string getName() { return _name; }
	std::string getMotto() { return "Go HARD or go HOME!"; }

	void AddPlayer(std::shared_ptr<Trainee> _players);
	std::string ViewPlayers();
	std::vector<std::shared_ptr<Trainee>> PlayerBatting();
	std::string MatchHistory();
};

