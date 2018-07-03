#include "GrokkingAlgorithm.h"

namespace GrokkingAlgorithm
{
	bool Ch6_BreadthFirstSearch()
	{
		/*
		* ========== Breadth First Search (BFS) ==============
		*
		* a simple demo to illustrate BFS
		*
		*/

		/* initialize a personal relationship network by hash map */
		std::map<std::string, std::vector<std::string>> relationNet{ { "you", { "alice", "bob", "claire" } },
		{ "bob", { "anuj", "peggy" } }, { "alice", { "peggy" } }, { "claire", { "thom", "jonny" } },
		{ "anuj", {} }, { "peggy", {} }, { "thom", {"you"} }, { "jonny", {} } };

		/* creat a counter */
		std::map < std::string, int> counter;

		/* assume the right one */
		std::set<std::string> seller{"jonny", "doggy", "catty"};

		std::queue<std::string> search_queue;
		std::vector<std::string>::iterator iter;

		/* add your first layer relationship*/
		for (iter = relationNet["you"].begin(); iter != relationNet["you"].end(); ++iter)
		{
			search_queue.push(*iter);
		}

		/* search */
		bool flag = false;
		std::string person;
		++counter["your"];
		while (!search_queue.empty())
		{
			/* get the first one */
			person = search_queue.front();
			search_queue.pop();

			/* check if trapped in loop */
			if (counter[person])
				continue;

			/* found or not */
			if (seller.find(person) != seller.end())
			{
				std::cout << person << "is a seller!" << std::endl;
				flag = true;
				break;
			}
			else
			{
				++counter[person];
				for (iter = relationNet[person].begin(); iter != relationNet[person].end(); ++iter)
					search_queue.push(*iter);
			}
		}

		if (!flag)
			std::cout << "Not found!" << std::endl;

		return flag;
	}
}
