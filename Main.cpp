#include <vector>
#include <fstream>
#include <string>
#include <iostream>

/** Program to create cleaned up txt file from junk word file via helper file with good words

	2575 word list with 'junk' words
	http://www-cs-faculty.stanford.edu/~knuth/sgb-words.txt

	20000 word list with 'commonly used' / 'good' words
	https://raw.githubusercontent.com/first20hours/google-10000-english/master/20k.txt

*/

int main()
{
	// First vector to contain the txt file with some 'junk' words
	std::vector<std::string> FiveWordsDirty;
	{
		std::cout << "Loading file 1 into vector" << std::endl;
		{

			// For getting the lines / item count of txt file
			std::ifstream Five_Word_File1("words5dirty.txt");
			int dfileitems = 0;
			for (std::string line; std::getline(Five_Word_File1, line);) {
				dfileitems++;
			}

			// Using previous dfileitems count to reserve space for vector and put words into it
			FiveWordsDirty.resize(dfileitems);
			int tempindex = 0;
			std::ifstream Five_Word_File1_2("words5dirty.txt");
			for (std::string line; std::getline(Five_Word_File1_2, line);)
			{
				if (line.empty())
				{
					continue;
				}
				FiveWordsDirty[tempindex] = line;
				tempindex++;
			}
		}
		std::cout << "Done loading file 1 into vector" << std::endl;
	}
	std::cout << "smaller vector size: " << FiveWordsDirty.size() << std::endl;


	// Second vector to contain the txt file with 'good' words
	std::vector<std::string> FiveWordsClean;
	{
		std::cout << "Loading file 2 into vector" << std::endl;
		{
			// Again to get item count for vector's size
			std::ifstream Five_Word_File2("words5clean.txt");
			int cfileitems = 0;
			for (std::string line; std::getline(Five_Word_File2, line);) {
				cfileitems++;
			}

			// Reserve space for vector and put words into it
			FiveWordsClean.resize(cfileitems);
			int tempindex = 0;
			std::ifstream Five_Word_File2_2("words5clean.txt");
			for (std::string line; std::getline(Five_Word_File2_2, line);)
			{
				if (line.empty())
				{
					continue;
				}

				if (line.length() != 5)
				{
					continue;
				}


				FiveWordsClean[tempindex] = line;
				tempindex++;
			}
		}
		std::cout << "Done loading file 2 into vector" << std::endl;
	}
	std::cout << "bigger vector size: " << FiveWordsClean.size() << std::endl;

	std::cout << "Vector 1 size: " << FiveWordsDirty.size() << std::endl;
	std::cout << "Vector 2 size: " << FiveWordsClean.size() << std::endl;


	// FiveWordsReady - vector for intersection / filtered words
	std::vector<std::string> FiveWordsReady;
	{
		int stillrun = true;
		int a = 0;
		std::ofstream ReadyFile("processed.txt");
		if (ReadyFile.is_open()) {
			while (stillrun) {
				for (int b = 0; b < FiveWordsClean.size(); b++)
				{
					if (a % 500 == 0) {
						std::cout << "a & b:  " << a << " & " << b << std::endl;
					}

					if (FiveWordsClean[b] == (FiveWordsDirty[a]))
					{
						ReadyFile << FiveWordsClean[b] << std::endl;
						break;
					}
				}
				a++;
				if (a == FiveWordsDirty.size()) stillrun = false;
			}
		}
		ReadyFile.close();


		std::cin.get();
		return 0;
	}
}