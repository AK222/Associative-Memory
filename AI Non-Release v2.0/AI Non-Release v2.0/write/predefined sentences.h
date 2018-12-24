#pragma once

#include <string>
#include <iostream>

#ifndef Word
typedef std::string Word;
#endif

namespace DefCreators
{
	void atypeofsomething(Word todefine, Word def)
	{
		std::cout << "Definition of " << todefine << ": " << "a type of " << def << "." << std::endl;
	}
}