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
