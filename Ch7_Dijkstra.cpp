#include "GrokkingAlgorithm.h"

namespace GrokkingAlgorithm
{
	std::map<std::string, int>::iterator find_lowest_cose_node(std::map < std::string, int> &cost, std::map<std::string, int> &counter)
	{
		std::map<std::string, int>::iterator iter = cost.begin(), ret = cost.end();
		int minCost = INT_MAX;

		while (iter != cost.end())
		{
			if (iter->second <= minCost  && counter[iter->first] == 0)
			{
				ret = iter;
				minCost = iter->second;
			}
			++iter;
		}

		return ret;
	}

	std::pair<std::vector<std::string>, int> Ch7_Dijkstra(std::map<std::string, std::map<std::string, int>> &graph)
	{
		/*
		* Solution to Dijkstra algorithm
		* 
		* Params:
		* 		- graph, a graph contains nodes and neighbors as well as weights
		*
		* Out:
		* 		return a map, the first points to the routine and second points to the cost.
		*
		* Note:
		* 		- Dijkstra can only handle directed acyclic graph (DAG) with non-negative side.
		*/

		/* cost map to update routine */
		std::map<std::string, int> cost;

		/* parent map to store parent node */
		std::map<std::string, std::string> parent;

		/* counter map to record processed node */
		std::map<std::string, int> counter;

		/* result */
		std::pair<std::vector<std::string>, int> ret;
		
		if (graph.empty())
			return ret;

		/* start from "start" */
		std::map<std::string, int > neighbor = graph["start"];
		std::map<std::string, int>::iterator iter_neighbor;

		/* create cost & parent */
		cost["fin"] = INT_MAX;
		parent["fin"] = "";
		for (iter_neighbor = neighbor.begin(); iter_neighbor != neighbor.end(); ++iter_neighbor)
		{
			cost[iter_neighbor->first] = iter_neighbor->second;
			parent[iter_neighbor->first] = "start";
		}	
		++counter["start"];

		std::map<std::string, int>::iterator iter_minCost;
		iter_minCost = find_lowest_cose_node(cost, counter);

		int costVal, prevCost;
		while (iter_minCost != cost.end())
		{
			neighbor = graph[iter_minCost->first];
			prevCost = iter_minCost->second;

			for (iter_neighbor = neighbor.begin(); iter_neighbor != neighbor.end(); ++iter_neighbor)
			{
				costVal = prevCost + iter_neighbor->second;

				/* update if have none || optimal route found */
				if (cost.find(iter_neighbor->first) == cost.end() || costVal < cost[iter_neighbor->first])
				{
					cost[iter_neighbor->first] = costVal;
					parent[iter_neighbor->first] = iter_minCost->first;
				}
			}

			++counter[iter_minCost->first];

			iter_minCost = find_lowest_cose_node(cost, counter);
		}

		ret.second = cost["fin"];
		ret.first.push_back("fin");
		while (ret.first.back() != "start")
			ret.first.push_back(parent[ret.first.back()]);
		return ret;
	}
}