
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Team{
	string name;
	string sport;
	string coach;
	double rating;
	
};
void showTeam(Team team) {
	cout << "Name of sport  : " << team.name << endl;
	cout << "View of sport  :" << team.sport << endl;
	cout << "Coach : " << team.coach<< endl;
	cout << "Rating  : " << team.rating << endl;

}
void enterTeam(Team &team) {
	cout << "Enter name of sport : " << team.name << endl;
	getline(cin, team.name);
	
	cout << "Enter a view of sport : " << team.sport << endl;
	getline(cin, team.sport);

	cout << "Enter coach : " << team.coach << endl;

	getline(cin, team.coach);
	cout << "Enter rating : " << endl;
	cin >> team.rating;


}
void add(vector<Team> teams) {
	Team newTeams;
		cout << "Enter a name of command : ";
		getline(cin, newTeams.name);
		cout << "Enter a view of sport : ";
		getline(cin, newTeams.sport);
		cout << "Enter coach : ";
		getline(cin, newTeams.coach);
		cout << "Enter your ating : ";
		cin >> newTeams.rating;
		teams.push_back(newTeams);

}

void Savetofile(vector<Team>& teams, const string& path) {
	ofstream file(path,ios::app);
	if (file.is_open()) {
		for (auto team : teams) {
			file << team.name << "." << team.sport << "." << team.coach << "." << team.rating << endl;

		}
	
		file.close();}
	else {
		cout << "Error open file" << endl;
		}
	
}
void ShowNeams(const vector<Team>& teams)
{
	cout << "Books : " << endl;
	for (auto team : teams)
	{
		showTeam(team);
	}
	cout << " -------------------- \n";
}
void loadfromfile(vector<Team>&teams,const string &filename) {
	ifstream file(filename);
	if (file.is_open()) {
		teams.clear();
		string line;
		while (getline(file, line)) {
			Team team;
			size_t pos = 0;
			pos = line.find(",");
			team.name = line.substr(0, pos);
			line.erase(0, pos + 1);
			pos = line.find(",");
			team.sport = line.substr(0, pos);
			line.erase(0, pos + 1);
			pos = line.find(",");
			team.coach = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			
			team.rating = stod(line);

			teams.push_back(team);

		}
		file.close();
		cout << "Data loaded from file" << endl;
	}
	else {
		cout << "Error opening file" << endl;
	}
}
		
void search(const vector<Team>& teams, string name) {
	for (auto team : teams) {
		if (team.name == name) {
			showTeam(team);
		}
	}
	}

int main()
{
	vector<Team>teams;
	string filename = "team.txt";
	Team myteam;
	Team newTeams;
	
	enterTeam(myteam);
	teams.push_back(myteam);
	Savetofile(teams, filename);
	showTeam(myteam);
	ShowNeams(teams);

	
	
}

