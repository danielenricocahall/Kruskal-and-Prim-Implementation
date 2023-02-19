/*
 * PrimSolver.cpp
 *
 *  Created on: Dec 1, 2018
 *      Author: daniel
 */

#include "PrimSolver.h"
#include "GraphUtil.h"
#include <climits>


PrimSolver::PrimSolver()
= default;




PrimSolver::~PrimSolver()
= default;

MSTSolver::Edge PrimSolver::findMinimumAdjacentEdge(
		const Graph& G,
		const int v,
		const std::vector<bool>& visited)
{

	const unsigned int V = G.size();
	int min = INT_MAX;
	Edge e{};
	e.s = v;
	for(unsigned int u = 0; u < V; ++u)
	{
		if(G[v][u] < min && !visited[u])
		{
			min = G[v][u];
			e.d = u;
		}
	}

	e.w = min;

	return e;
}

void PrimSolver::solveMinimumSpanningTree(const Graph& G)
{
	const unsigned int V = G.size();

	std::vector<bool> visited;
	visited.resize(V);

	// O(V) for initialization
	for(unsigned int ii = 0; ii < V; ++ii)
	{
		visited[ii] = false;
	}

	visited[0] = true;
	std::vector<int> S;
	std::vector<Edge> F;
	unsigned int N = F.size();
	S.push_back(0);

	// O(|V|) loop
	while(N < V-1)
	{
		Edge e{};
		e.w = INT_MAX;
		// O(|V|)
		for(const auto &v: S)
		{
			// O(|V|)
			Edge min = findMinimumAdjacentEdge(G, v, visited);
			if(min.w < e.w)
			{
				e = min;
			}
		}
		S.push_back(e.d);
		F.push_back(e);

		visited[e.d] = true;
		N = F.size();
	}
	/*
	for(const auto &edge: F)
	{
		std::cout << "(" << edge.s << "," << edge.d << ")" << std::endl;
		std::cout << edge.w << std::endl;
	}*/


}
