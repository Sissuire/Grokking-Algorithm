#include "GrokkingAlgorithm.h"

namespace GrokkingAlgorithm
{
	void Ch8_GreedyAlgorithm()
	{
		std::set<std::string> states_needed = { "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };
		std::map<std::string, std::set<std::string>> stations;
		stations["kone"] = std::set < std::string > { "id", "nv", "ut" };
		stations["ktwo"] = std::set < std::string > {"wa", "id", "mt"};
		stations["kthree"] = std::set < std::string > {"or", "nv", "ca"};
		stations["kfour"] = std::set < std::string > {"nv", "ut"};
		stations["kfive"] = std::set < std::string > {"ca", "az"};

		std::set<std::string> final_stations;
		std::set<std::string> states_covered, inter_covered;
		std::string best_station;

		std::map<std::string, std::set<std::string>>::iterator iter;
		std::set<std::string>::iterator iter_covered;

		int counter = 0;
		const int MAX_ITERATIONS = 10000;
		while (!states_needed.empty())
		{
			states_covered.clear();

			/* search for local optimal solution */
			for (iter = stations.begin(); iter != stations.end(); ++iter)
			{
				inter_covered.clear();
				std::set_intersection(states_needed.begin(), states_needed.end(), iter->second.begin(), iter->second.end(), std::inserter(inter_covered, inter_covered.begin()));

				if (inter_covered.size() > states_covered.size())
				{
					best_station = iter->first;
					states_covered = inter_covered;
				}
			}

			/* store */
			final_stations.insert(best_station);
			
			/* remove */
			stations.erase(best_station);
			for (iter_covered = states_covered.begin(); iter_covered != states_covered.end(); ++iter_covered)
			{
				states_needed.erase(*iter_covered); // Even if no this value. It doesn't matter
			}

			++counter;

			if (counter > MAX_ITERATIONS)
				break;
		}

		if (counter > MAX_ITERATIONS)
			std::cout << "Can not find a solution !" << std::endl;
		else
		{
			std::cout << "An local optimal solution FOUND !" << std::endl;
			for (iter_covered = final_stations.begin(); iter_covered != final_stations.end(); ++iter_covered)
				std::cout << *iter_covered << "\t";
			std::cout << std::endl;
		}

		return;
	}
}