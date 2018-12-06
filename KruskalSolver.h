#pragma once
#include "MSTSolver.h"
#include "Graph.h"


class KruskalSolver : public MSTSolver
{

public:
	KruskalSolver();
	virtual ~KruskalSolver();
	virtual void solveMinimumSpanningTree(const Graph& G);
	int find(const std::vector<int>& parent, int i);
	void union1(std::vector<int>& parent, int i, int j);




};
