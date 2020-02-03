//Written by Keegan McGonigle
#include <iostream>
#include <stdlib.h>
#include "Streng.h"

int main()
{
	Streng stringA("I LIKE Jam");
	Streng stringB;
	Streng stringC("chicken");
	Streng stringD("012345678");
	Streng stringE("hello!!!! .   ,");
	Streng stringF("ok");
	Streng stringG("ok");

	std::cout << "String A: " << stringA << std::endl;
	std::cout << "String B: " << stringB << std::endl;
	std::cout << "String C: " << stringC << std::endl;
	std::cout << "String D: " << stringD << std::endl;
	std::cout << "String E: " << stringE << std::endl;
	std::cout << "String F: " << stringF << std::endl;
	std::cout << "String G: " << stringG << std::endl;
	std::cout << std::endl;

	std::cout << "String A Length: " << stringA.getLength();
	std::cout << std::endl;

	Streng concatination("Concatination is ");

	std::cout << "Concatination String: " << concatination << std::endl;
	std::cout << "Concatination String with StringC: " << concatination.concat(stringC) << std::endl;
	std::cout << "Concatination String with StringD: " << concatination.concat(stringD) << std::endl;

	std::cout << std::endl;

	if (stringF == stringG) {
		std::cout << "String F and string G are equal!" << std::endl;
	}

	if (stringF != stringA) {
		std::cout << "String F and string A are not equal!" << std::endl;
	}

	if (stringC > stringA) {
		std::cout << "String C comes before string A" << std::endl;
	}

	std::cout << "String C toUpper: " << stringC.toUpper() << std::endl;
	std::cout << "String A toLower: " << stringA.toLower() << std::endl;
	std::cout << "String D substring from 3: " << stringD.subString(3) << std::endl;
	std::cout << "String D substring from 4 to 7: " << stringD.subString(4,7) << std::endl;
	std::cout << "String A index of K: " << stringA.indexOf('K') << std::endl;
	std::cout << "String A index of Q: " << stringA.indexOf('Q') << std::endl;
	std::cout << "String E lst index of !: " << stringE.lastIndexOf('!') << std::endl;


}


