/*
 * GraphUtil.h
 *
 *  Created on: Nov 30, 2018
 *      Author: daniel
 */

#ifndef GRAPHUTIL_H_
#define GRAPHUTIL_H_

#include "Graph.h"
class GraphUtil
{
public:
	static Graph generateRandomGraph(unsigned int V,
			unsigned int range,
			double edgeProbability);

	static bool allVerticesReached(const std::vector<bool>& visited);
};





#endif /* GRAPHUTIL_H_ */
