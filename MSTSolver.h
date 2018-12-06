/*
 * MSTSolver.h
 *
 *  Created on: Dec 1, 2018
 *      Author: daniel
 */

#ifndef MSTSOLVER_H_
#define MSTSOLVER_H_

#pragma once
#include "Graph.h"

class MSTSolver
{
public:
	struct Edge
	{
		int w;
		int s;
		int d;
	};
	virtual void solveMinimumSpanningTree(const Graph& G) = 0;
};





#endif /* MSTSOLVER_H_ */
