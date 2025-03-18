#include "Location.h"

Location::Location(string i_name, string i_description, string i_far_description) {
	name = i_name;
	description = i_description;
	far_description = i_far_description;
	pathways = {};
}

string Location::getName()
{
	return name;
}

string Location::getDescription()
{
	return description;
}

string Location::getFarDescription()
{
	return far_description;
}

void Location::addPathway(Location& new_pathway)
{
	pathways.push_back(&new_pathway);
}

vector<Location*> Location::getPathways()
{
	return pathways;
}