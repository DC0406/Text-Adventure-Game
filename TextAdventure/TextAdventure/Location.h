#pragma once
#include <string>
#include <vector>

using namespace std;


class Location
{
private:
	string name;
	string description;
	string far_description;
	vector<Location*> pathways;

public:
	Location(string i_name, string i_description, string i_far_description);
	string getName();
	string getDescription();
	string getFarDescription();

	void addPathway(Location& new_pathway);
	vector<Location*> getPathways();

};