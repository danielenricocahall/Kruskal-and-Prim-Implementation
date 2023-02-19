/*
 * PrimsAlgorithm.h
 *
 *  Created on: Dec 1, 2018
 *      Author: daniel
 */

#ifndef PRIMSOLVER_H_
#define PRIMSOLVER_H_
#pragma once
#include "Graph.h"
#include "MSTSolver.h"
class PrimSolver : public MSTSolver
{
public:
	PrimSolver();
	virtual ~PrimSolver();
	void solveMinimumSpanningTree(const Graph& G) override;
	static Edge findMinimumAdjacentEdge(const Graph& G, int v, const std::vector<bool>& visited);
};





#endif /* PRIMSOLVER_H_ */
