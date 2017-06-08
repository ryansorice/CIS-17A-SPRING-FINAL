/* 
	Author: Ryan Sorice
	CIS 17A - Final Project
	Lane Game
*/

//System libraries
#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <cstdlib>

//User Libraries
#include "Trainee.h"
#include "Fielder.h"
#include "Batter.h"
#include "Team.h"

using namespace std;

//Function Prototypes
void AddBatters(const shared_ptr<Team>);
void AddFielders(const shared_ptr<Team>);
void PlayBall(const shared_ptr<Team>);

int main() 
{
	//random number seed
	srand(static_cast<unsigned int>(time(0)));

	//Intro + Create team name
	cout << "Welcome to /a/ Baseball-like game! \n" << "First, what will be your team's name? ";
	string tName;
	getline(cin, tName);
	auto team = make_shared<Team>(tName);
	system("cls");

	cout << "Your team has a total of 6 players; (the ideal being 3 batters and 3 fielders).\n" << "How many are batters? (The rest will be fielders) ";
	system("pause");
	
	//ADD BATTERS TO TEAM
	int b;
	cin >> b;
	system("cls");
	b = b + 1;
	switch (b)
	{
		case 6: AddBatters(team);
		case 5: AddBatters(team);
		case 4: AddBatters(team);
		case 3: AddBatters(team);
		case 2: AddBatters(team);
		case 1: AddBatters(team);
		default: break;
	}

	//ADD FIELDERS TO TEAM
	b = b - 1;
	int f = 6 - b;
	int f1 = f;
	while ( f != 0 )
	{
		AddFielders(team);
		f--;
	}

	//Run the game
	int gameOver = 0;
	while (gameOver != 1 && gameOver != 2)
	{
		cout << "1) View Team\n2) Play Game\n3) Match History\n4) Quit Game\n";
		int n = -1, level=1;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			system("cls");
			cout << "Team Name: " << team->getName() << endl << endl;
			cout << "Team Motto: " << team->getMotto() << endl << endl;
			cout << "Your team has " << b << " Batter(s) and " << f1 << " Fielder(s).\n";
			cout<< "Roster: " << team->ViewPlayers() << endl;
			system("pause"); system("cls");
			break;
		}
		case 2:
		{
			PlayBall(team);
			break;
		}
		case 3: 
		{
			break;
		}
		case 4:
		{
			//Game over with a Quit; No victory
			system("cls");
			cout << "Goodbye!\n";
			system("pause");
			gameOver = 1; break;
		}
		default: "Invalid entry!\n"; break;
		}
		//Game over with a Victory
		if (level==6) gameOver = 2;
		
	}
	//Victory screen
	if (gameOver == 2) cout << "Congratulations! Your team" << team->getName() << " are the champions!\n";
	
	return 0;
}

void PlayBall(const shared_ptr<Team> team)
{
	system("cls");
	//Coin toss
	int coin = 0,
		toss = rand() % 2 + 1;;
	cout << "Coin Toss! (1 for heads, 2 for tails)\n";
	cin >> coin;

	if (toss == 1)
	{
		cout << "Heads!\n";
		if (coin == 1) cout << "Your team bats first.\n";
		else cout << "Your team takes the field first.\n";
		system("pause");
	}
	else if (toss == 2)
	{
		cout << "Tails!\n";
		if (coin == 2) cout << "Your team bats first.\n";
		else cout << "Your team takes the field first.\n";
		system("pause");
	}

	//Game Menu
	int x = 0;
	while (x != 1 && x != 2)
	{
		system("cls");
		cout << "1) Bat/Field\n2) The Count\n3) Score\n4) Surrender\n";
		int n = 0;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			cout << "Game Over!\n";
			x = 1;
			system("pause");
		}
		default: break;
		}
	}
}

//Add Batters to team function
void AddBatters(const shared_ptr<Team> team)
{
	cout << "Batter's name? ";
	string name;
	getline(cin, name);
	auto playerPtr = make_shared<Batter>(name);
	team->AddPlayer(playerPtr);
	system("cls");
}

//Add Fielders to team function
void AddFielders(const shared_ptr<Team> team)
{
	cout << "Fielder's name? ";
	string name;
	getline(cin, name);
	auto playerPtr = make_shared<Fielder>(name);
	team->AddPlayer(playerPtr);
	system("cls");
}