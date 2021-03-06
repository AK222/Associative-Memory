#include <iostream>
#include <string>
#include <fstream>

#include "read/read.h"
#include "files/WordSetup.h"
#include "files/filemanagement.h"
#include "utils/debugfuncs.h"

#ifndef Word
typedef std::string Word;
#endif

#define WaitforEnter std::cout << "\nPress enter to continue . . . " << std::endl; std::cin.get();

// NEED TO CREATE AN OVERRIDEwordgrouping function to so that the user can make the computer take things like ice cream in as one word.

int main()
{
	UPLOAD();
	std::cout << "Information successfully uploaded!" << std::endl << "\n";
	// MAIN CODE BELOW THIS POINT

	
	std::string sentence;
	std::getline(std::cin, sentence);
	Learn::learnfromsentence(sentence);
	WaitforEnter;
	Debug::printWordReport();
	WaitforEnter;
	
	Debug::printStringVector(findRelatedWords("ice cream"));
	WaitforEnter;
	

	// MAIN CODE ABOVE THIS POINT
	std::cout << "Cleaning up and downloading . . ." << std::endl;
	DOWNLOAD();
}