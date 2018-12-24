#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "../utils/debugfuncs.h"

#ifndef NullStrVec
strvector nullstrvec;
#define NullStrVec nullstrvec
#endif

#ifndef Word
typedef std::string Word;
#endif

namespace Read
{
	void switchfirstlettercase(Word word)
	{
		if (word[0] > 96)
		{
			word[0] -= 32;
		}
		else
		{
			word[0] += 32;
		}
	}

	std::vector<Word> SentenceBreakdown(std::string sentencein)
	{
		std::istringstream ss(sentencein);
		std::vector<Word> wordlist;
		char punctuation[] = { ' ', ',', '!', '?', ':', ';', '\"', '\'' };
		while (ss)
		{
			Word word;
			ss >> word;
			for (int i = 0; i < 8; i++)
			{
				word.erase(std::remove(word.begin(), word.end(), punctuation[i]), word.end());
			}
			if (word[0] < 96)
			{
				word[0] += 32;
			}

			wordlist.push_back(word);
		}
		std::cout << "Words: " << std::endl;
		Debug::printVectorString(wordlist);
		std::string answer;
		bool _continue = false;
		/*
		while (_continue == false)
		{
			std::cout << "Are there any words that should be interpretted together? (like ice cream should be interpretted as \"ice cream\" and not \"ice\" and \"cream\"). Answer y for yes and n for no." << std::endl;
			std::cin >> answer;
			if (answer == "y")
			{
				std::cout << "Enter the words that need to be interpretted together one by one, separated by commas. They should be together in the sentence, or this won't work!" << std::endl;
				std::cin >> answer;
				std::istringstream ss2(sentencein);
				std::vector<Word> wordlist2;
				while (ss2)
				{
					Word word;
					ss2 >> word;
					word.erase(std::remove(word.begin(), word.end(), ','), word.end());
					if (word[0] < 96)
					{
						word[0] += 32;
					}

					wordlist2.push_back(word);
					for (int i = 0; i < wordlist.size(); i++)
						if (wordlist2[0] == wordlist[i])
							

					return -1;
				}
			}
			else if (answer == "n")
			{
				_continue = true;
			}
			else
			{
				std::cout << "I'm taking that as a no.";
				_continue = true;
			}
		}
		*/
		return wordlist;
	}

	//THIS FUNCTION IS T0 BE RUN ONLY ONCE PER WORD!!
	void EstablishConnectionWithOtherWords(Word word)
	{
		int ID = findWordID(word);
		if (RelationIDs[ID].getRawString() != ".")
		{
			std::cerr << "Establish Connection With Other Words has already been run! If this was a mistake, please manually edit the txt file!";
			std::cin.get();
			exit(1);
		}

		std::string answer;
		for (int i = 0; i < Wordlist.size() && i != ID; i++)
		{
			std::cout << "Is " << word << " interchangeable or related to " << Wordlist[i] << "? Answer \'0\' for interchangeable and \'1\' for related. If none of the above, enter something other than 0 or 1.";
			std::cin >> answer;
			if (answer == "0")
			{
				RelationIDs[ID].push_back(std::to_string(i));
				bool _continue = false;
				while (_continue == false)
				{
					std::cout << "Is \"" << Wordlist[i] << "\" interchangeable with \"" << word << "\"? Enter y for yes and n for no.";
					std::cin >> answer;
					if (answer == "y")
					{
						RelationIDs[i].push_back(std::to_string(ID));
						_continue = true;
					}
					else if (answer == "n")
					{
						_continue = true;
					}
					else
					{
						_continue = false;
					}
				}
			}
			else if (answer == "1")
			{
				std::string numi = std::to_string(i);
				for (int j = 0; j < 10; j++)
				{
					std::replace(numi.begin(), numi.end(), std::to_string(j)[0], letters[j]);
				}
				RelationIDs[ID].push_back(numi);
				std::string numID = std::to_string(ID);
				for (int j = 0; j < 10; j++)
				{
					std::replace(numID.begin(), numID.end(), std::to_string(j)[0], letters[j]);
				}
				RelationIDs[i].push_back(numID);
			}
		}
	}

}

namespace Learn
{
	void learnfromsentence(std::string sentence)
	{
		std::vector<Word> Tempwordlist = Read::SentenceBreakdown(sentence);
		for (int i = 0; i < Tempwordlist.size(); i++)
		{
			if (findWordID(Tempwordlist[i]) == -1 && Tempwordlist[i] != "")
			{
				std::string reply;
				bool _continue = false;
				while (_continue == false)
				{
					std::cout << "Is\"" << Tempwordlist[i] << "\"  supposed to be capitalized normally? Enter y for yes and n for no." << std::endl;
					std::cin >> reply;
					if (reply == "y")
					{
						Read::switchfirstlettercase(Tempwordlist[i]);
						_continue = true;
					}
					else if (reply == "n")
					{
						_continue = true;
					}
					else
					{
						_continue = false;
					}
				}

				Wordlist.push_back(Tempwordlist[i]);
				RelationIDs.push_back(NullStrVec);
				Read::EstablishConnectionWithOtherWords(Tempwordlist[i]);
			}
			else
			{
				std::string response;
				std::cout << "I have already seen the word " << Tempwordlist[i] << "!" << std::endl;
				std::cout << "Do you want me to give you my definition? Type y for yes and n for no.";
				std::cin >> response;
				if (response == "y")
				{
					std::cout << std::endl; // Need to put the define function here later. ( After I create it ;) )
				}
				else if (response == "n")
				{
					std::cout << std::endl;
				}
				else
				{
					std::cout << std::endl << "I'm taking that as a no." << std::endl;
				}
			}
		}
	}
}