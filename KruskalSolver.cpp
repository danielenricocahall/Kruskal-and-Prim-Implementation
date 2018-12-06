/*
 * KruskalSolver.cpp
 *
 *  Created on: Dec 1, 2018
 *      Author: daniel
 */

#include "KruskalSolver.h"
#include <algorithm>
#include <climits>
#include <iostream>

KruskalSolver::KruskalSolver()
{

}

KruskalSolver::~KruskalSolver()
{

}

int KruskalSolver::find(const std::vector<int>& parent, int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void KruskalSolver::union1(std::vector<int>& parent, int i, int j)
{
    int a = find(parent,i);
    int b = find(parent, j);
    parent[a] = b;
}


void KruskalSolver::solveMinimumSpanningTree(const Graph& G)
{
	std::vector<Edge> edges;

	// O(|V|^2) for building an initial set of nodes
	const unsigned int V = G.size();
	for(unsigned int ii = 0; ii < V; ++ii)
	{
		for(unsigned int jj = ii; jj < V; ++jj)
		{
			Edge e;
			e.s = ii;
			e.d = jj;
			e.w = G[ii][jj];
			if(e.w != INT_MAX)
			{
				edges.push_back(e);
			}
		}
	}

	// set up a collection of visited vertices O(|V|)
	std::vector<bool> visited;
	visited.resize(V);
	for(unsigned int ii = 0; ii < V; ++ii)
	{
		visited[ii] = false;
	}

	// set up a collection of parent vertices O(|V|)
	std::vector<int> parent;
	parent.resize(V);
	for(unsigned int ii = 0; ii < V; ++ii)
	{
		parent[ii] = ii;
	}

	// sort all edges in ascending order
	// O(E log E)
	std::sort(edges.begin(), edges.end(), [&](const Edge& a, const Edge& b){return a.w < b.w;});

	// O(|V|^2)
	std::vector<Edge> F;
	for(Edge &e: edges)
	{
		if(find(parent,e.s) != find(parent,e.d) && G[e.s][e.d] != INT_MAX)
		{
			F.push_back(e);
			union1(parent,e.s, e.d);
		}
	}

	// Total: O(|V|^2) + 2O(|V|) + O(|E log E|)



}
