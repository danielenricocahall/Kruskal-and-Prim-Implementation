/*
 * GraphUtil.cpp
 *
 *  Created on: Nov 30, 2018
 *      Author: daniel
 */



#include "GraphUtil.h"
#include <cstdlib>
#include <random>
#include <climits>
#include <algorithm>

Graph GraphUtil::generateRandomGraph(const unsigned int V,
		const unsigned int range,
		const double edgeProbability)
{
    std::random_device r;

	std::bernoulli_distribution distribution(edgeProbability);
	std::default_random_engine generator(r());

	Graph G;
	G.resize(V);
	for(unsigned int ii = 0; ii < V; ++ii)
	{
		G[ii].resize(V);
		std::fill(G[ii].begin(), G[ii].end(), INT_MAX);

	}
	for(unsigned int ii = 0; ii < V; ++ii)
	{
		for(unsigned int jj = 0; jj < V; ++jj)
		{
			if (ii != jj && G[jj][ii] == INT_MAX && distribution(generator))
			{
				G[ii][jj] = rand() % range + 1;
				G[jj][ii] = G[ii][jj];
			}
		}
	}

	return G;

}
bool GraphUtil::allVerticesReached(const std::vector<bool>& visited)
{
    return std::all_of(visited.begin(), visited.end(), [](const bool v){ return v; });
}
