#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include "../utils/strvector.h"

#ifndef Word
typedef std::string Word;
#endif

strvector Wordlist;
std::vector<strvector> RelationIDs;
/*
READ:
RELATION IDS:

NUMBERS: CORRESPOND TO THE INDEX OF THE INTERCHANGEABLE WORDS IN WORDLIST.
LETTERS: CORRESPOND TO THE INDEX OF THE RELATED WORDS IN WORDLIST SO THAT THE LETTERS REPRESENT THE DIGITS OF OF THEIR INDEX.
*/
char letters[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
/*
this way if one word is interchangeable with another but the other is not interchangeable with the first, the first is a type of the second 

*/

int findWordID(Word word)
{
	for (int i = 0; i < Wordlist.size(); i++)
	{
		std::string str = Wordlist[i];
		if (word == str)
			return i;
	}
	return -1;
}


strvector findInterchangeableWords(Word word)
{
	strvector result;
	strvector relations;
	std::string i = RelationIDs[findWordID(word)].getRawString();
	relations.set(i);
	i = relations.getnumbers().getRawString();
	relations.set(i);
	for (int j = 0; j < relations.size(); j++)
	{
		result.push_back(relations[j]);
	}
	return result;
}
//NEED TO TEST THE FUNCTION ABOVE AND THE FUNCTION BELOW.
strvector findRelatedWords(Word word)
{
	strvector result;
	strvector relations;
	std::string i = RelationIDs[findWordID(word)].getRawString();
	relations.set(i);
	i = relations.getletters().getRawString();
	relations.set(i);
	for (int j = 0; j < relations.size(); j++)
	{
		for (int k = 0; k < relations.size(); k++)
		{
			std::string str = relations[k];
			for (int j = 0; j < 10; j++)
			{
				std::replace(str.begin(), str.end(), letters[j], std::to_string(j)[0]);
			}
			std::stringstream ss(str);
			int x = 0;
			ss >> x;
			result.push_back(Wordlist[x]);
		}
	}
	return result;
}