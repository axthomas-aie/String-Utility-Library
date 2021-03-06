#include "SUL.h"


#include <iostream>



const size_t sul::alphabetLength = 26;

const char sul::lowerc[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
							   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

const char sul::upperc[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'K', 'L', 'M',
                               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };









void sul::toUpperCase(std::string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		for (int n = 0; n < alphabetLength; ++n)
		{
			if (s[i] == lowerc[n])
			{
				s[i] = upperc[n];
				break;
			}
		}
	}
}

void sul::toLowerCase(std::string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		for (int n = 0; n < alphabetLength; ++n)
		{
			if (s[i] == upperc[n])
			{
				s[i] = lowerc[n];
				break;
			}
		}
	}
}

std::string sul::getWord(std::string s, size_t idx)
{
	std::string ret = "";
	size_t startidx = 0;
	size_t spaceidx = s.find(' ');

	while (idx > 0 && spaceidx != s.npos)
	{
		startidx = spaceidx + 1;
		spaceidx = s.find(' ', startidx);

		--idx;
	}

	if (idx == 0)
	{
		ret = s.substr(startidx, spaceidx - startidx);
	}

	return ret;
}

void sul::eraseWord(std::string& s, size_t idx)
{
	size_t startidx = 0;
	size_t spaceidx = s.find(' ');

	while (idx > 0 && spaceidx != s.npos)
	{
		startidx = spaceidx + 1;
		spaceidx = s.find(' ', startidx);

		--idx;
	}

	if (idx == 0)
	{
		s.erase(startidx, spaceidx - startidx + 1);
	}
}











void sul::test::runAllTests()
{
	helloWorld();
	printAlphabet();
	caseChanges();
	testGetWord();
	testEraseWord();
}

void sul::test::helloWorld()
{
	std::cout << "Hello world!" << std::endl;

	std::cin.get();
}

void sul::test::printAlphabet()
{
	for (int i = 0; i < sul::alphabetLength; ++i)
	{
		std::cout << sul::lowerc[i] << ' ' << sul::upperc[i] << std::endl;
	}

	std::cin.get();
}

void sul::test::caseChanges()
{
	std::string base = "Example String.";
	std::string ubase(base);
	std::string lbase(base);
	toUpperCase(ubase);
	toLowerCase(lbase);

	std::cout << "Base string:" << base << std::endl;
	std::cout << "toUpperCase(base):" << ubase << std::endl;
	std::cout << "toLowerCase(base):" << lbase << std::endl;

	std::cin.get();
}

void sul::test::testGetWord()
{
	std::string base = "It's just an example sentence.";

	std::cout << "Base string:" << base << std::endl;
	std::cout << "Word 0:'" << getWord(base, 0) << "'" << std::endl;
	std::cout << "Word 1:'" << getWord(base, 1) << "'" << std::endl;
	std::cout << "Word 2:'" << getWord(base, 2) << "'" << std::endl;
	std::cout << "Word 3:'" << getWord(base, 3) << "'" << std::endl;
	std::cout << "Word 4:'" << getWord(base, 4) << "'" << std::endl;
	std::cout << "Word 5:'" << getWord(base, 5) << "'" << std::endl;
	std::cout << "Word 10:'" << getWord(base, 10) << "'" << std::endl;

	std::cin.get();
}

void sul::test::testEraseWord()
{
	std::string base = "It's just an example sentence.";
	std::string zero(base);
	std::string three(base);
	std::string four(base);
	std::string ten(base);

	eraseWord(zero, 0);
	eraseWord(three, 3);
	eraseWord(four, 4);
	eraseWord(ten, 10);

	std::cout << "Base string:" << base << std::endl;
	std::cout << "Erase 0:'" << zero << "'" << std::endl;
	std::cout << "Erase 3:'" << three << "'" << std::endl;
	std::cout << "Erase 4:'" << four << "'" << std::endl;
	std::cout << "Erase 10:'" << ten << "'" << std::endl;

	std::cin.get();
}
