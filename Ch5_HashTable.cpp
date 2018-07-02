#include "GrokkingAlgorithm.h"


namespace GrokkingAlgorithm
{
	void Ch5_HashTable()
	{
		/*
		* ========== Hash Table ==============
		*
		* a simple demo to use 'map'('unorder_map')
		*
		*/

		/* initialize a map | <name, age> */
		std::map<std::string, int> mapping{ { "Allen", 32 }, { "Bob", 22 }, {"Alice", 28} };


		std::string input;
		int age;
		char flag;
		std::map < std::string, int>::iterator iter;

		

		while (true)
		{
			std::cout << "Input Name to Search: ('q' to quit)" << std::endl;
			std::cin >> input;

			if (input == "q")
				break;

			iter = mapping.find(input);

			if (iter == mapping.end())
			{
				std::cout << "No such name. \n Will you add this one? (Y/N)" << std::endl;
				std::cin >> flag;
				if (flag == 'Y')
				{
					std::cout << "Please input the age:" << std::endl;
					std::cin >> age;

					mapping.insert(std::pair<std::string, int>(input, age));
					std::cout << "Done!" << std::endl;
				}
				std::cout << std::endl;
				continue;
			}
			std::cout << "Age: " << age << std::endl << std::endl;
		}

		std::cout << "\nAll in map are as follows:" << std::endl;
		for (iter = mapping.begin(); iter != mapping.end(); ++iter)
		{
			std::cout << "Name: " << iter->first << ",\tAge: " << iter->second << std::endl;
		}

		return;
	}
}