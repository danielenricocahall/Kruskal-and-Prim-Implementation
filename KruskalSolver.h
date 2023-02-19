#pragma once
#include "MSTSolver.h"
#include "Graph.h"


class KruskalSolver : public MSTSolver
{

public:
	KruskalSolver();
	virtual ~KruskalSolver();
	void solveMinimumSpanningTree(const Graph& G) override;
	static int find(const std::vector<unsigned int>& parent, unsigned int i);
	static void union1(std::vector<unsigned int>& parent, int i, int j);




};
