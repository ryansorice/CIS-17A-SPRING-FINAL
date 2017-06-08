#include "Team.h"



Team::Team(std::string name) : _name(name)
{
}

Team::~Team()
{
}

void Team::AddPlayer(std::shared_ptr<Trainee> _players)
{
	players.push_back(_players);
}

std::string Team::ViewPlayers()
{
	std::string crew;
	for (auto player : players) 
	{
		crew+=player->getName() + '\n';
	}
	return crew;
}
