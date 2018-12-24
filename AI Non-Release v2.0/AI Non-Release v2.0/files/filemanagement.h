#pragma once

#include <string>
#include <fstream>

#include "WordSetup.h"
#include "../utils/strvector.h"

#ifndef Word
typedef std::string Word;
#endif

// Use this to upload and download information
void UPLOAD()
{
	std::ifstream inFile;
	inFile.open("files/Words.txt", std::ifstream::in);
	while (!inFile.eof())
	{
		std::string inFileinput;
		std::getline(inFile, inFileinput);
		if (inFileinput != "")
		{
			Wordlist.push_back(inFileinput);
		}
	}
	inFile.close();
	inFile.open("files/RelationID.txt", std::ifstream::in);
	while (!inFile.eof())
	{
		std::string inFileinput;
		strvector convertedinput;
		std::getline(inFile, inFileinput);
		if (inFileinput != "")
		{
			convertedinput.set(inFileinput);
			RelationIDs.push_back(convertedinput);
		}
	}
	inFile.close();
}

void DOWNLOAD()
{
	std::ofstream outFile;
	outFile.open("files/Words.txt", std::ofstream::out | std::ofstream::trunc);
	outFile << Wordlist[0];
	for (int i = 1; i < Wordlist.size(); i++)
	{
		outFile << "\n" << Wordlist[i];
	}
	outFile.close();
	outFile.open("files/RelationID.txt", std::ofstream::out | std::ofstream::trunc);
	outFile << RelationIDs[0].getRawString();
	for (unsigned int i = 1; i < RelationIDs.size(); i++)
	{
		outFile << "\n" << RelationIDs[i].getRawString();
	}
	outFile.close();
}