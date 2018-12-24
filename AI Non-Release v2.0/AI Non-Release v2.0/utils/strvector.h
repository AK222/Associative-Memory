#pragma once

#include <string>
#include <iostream>

class strvector
{
private:
	std::string StrVector = ".";
public:
	// GENERAL METHODS:
	strvector();
	~strvector();

	void set(std::string stringtoset);

	std::string operator[](unsigned int location);
	
	std::string first();
	std::string last();

	unsigned int find(std::string stringtofind);

	int size();
	bool empty();
	void clear();

	void push_back(std::string stringtopush);
	void pop_back();
	void remove(std::string stringtoremove);

	// METHODS SPECIFICALLY FORE THIS PROJECT:
	strvector getletters();
	strvector getnumbers();

	std::string getRawString();
private:
	std::string element(unsigned int location);

};

