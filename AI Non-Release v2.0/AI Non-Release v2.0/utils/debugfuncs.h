#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "strvector.h"
#include "../files/WordSetup.h"

#ifndef Word
typedef std::string Word;
#endif

namespace Debug
{
	void printVectorString(std::vector<std::string> vector)
	{
		for (unsigned int i = 0; i < vector.size(); i++)
		{
			std::cout << vector[i] << std::endl;
		}
	}

	void printStringVector(strvector vector)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			std::cout << vector[i] << std::endl;
		}
	}

	void printRawString(strvector vector)
	{
		std::cout << vector.getRawString() << std::endl;
	}

	int count = 1;

	void printWordReport()
	{
		std::cout << "_______________________________________________________________________________________________________________________\n" << "Word report #" << count << "\n" << "-----------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < Wordlist.size(); i++)
		{
			std::cout << Wordlist[i];
			int spacenum = 30 - Wordlist[i].size();
			for (int i = 0; i < spacenum; i++)
			{
				std::cout << " ";
			}
			std::cout << RelationIDs[i].getRawString() << std::endl;
		}
		std::cout << "_______________________________________________________________________________________________________________________\n";
		count++;
	}

}