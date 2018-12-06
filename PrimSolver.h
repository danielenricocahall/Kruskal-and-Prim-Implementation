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
	virtual void solveMinimumSpanningTree(const Graph& G);
	Edge findMinimumAdjacentEdge(const Graph& G, const int v, const std::vector<bool>& visited);
};





#endif /* PRIMSOLVER_H_ */
