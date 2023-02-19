/*
 * Driver.cpp
 *
 *  Created on: Nov 30, 2018
 *      Author: daniel
 */


#include "GraphUtil.h"
#include "Graph.h"
#include "KruskalSolver.h"
#include "PrimSolver.h"
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>
#include <ctime>
#include <chrono>
#include <numeric>
#include <iostream>
#include <thread>
#include <climits>
#include <sstream>

int main()
{
	auto * ps = new PrimSolver();
	auto * ks = new KruskalSolver();

	const unsigned int R = 10;

	const unsigned int MC = 5;
	const std::vector<int> V = {100, 200, 400, 800, 1600, 3200};
	const std::vector<double> P = {0.3};

	std::ofstream resultfile;
	resultfile.open ("Results_"+ std::to_string(P.at(0)) + ".csv");
	resultfile << "V, Probability, Prim Time (s), Kruskal Time (s) \n";

	for(const auto &v: V)
	{
		std::cout << "V = " << v << std::endl;
		for(const auto &p: P)
		{
			std::vector<double> prim_times_elapsed;
			std::vector<double> kruskal_times_elapsed;

			for(unsigned int ii = 0; ii < MC; ++ii)
			{
				Graph G = GraphUtil::generateRandomGraph(v, R, p);
				const auto t_start = std::chrono::high_resolution_clock::now();
				ps->solveMinimumSpanningTree(G);
				const auto t_end = std::chrono::high_resolution_clock::now();
				prim_times_elapsed.push_back(std::chrono::duration<double, std::milli>(t_end-t_start).count());
				std::cout << "Finished Prim Run #" << ii << std::endl;
			}
			double prim_average = std::accumulate( prim_times_elapsed.begin(), prim_times_elapsed.end(), 0.0)/prim_times_elapsed.size();

			prim_average /= 1000;
			for(unsigned int ii = 0; ii < MC; ++ii)
			{
				Graph G = GraphUtil::generateRandomGraph(v, R, p);
				const auto t_start = std::chrono::high_resolution_clock::now();
				ks->solveMinimumSpanningTree(G);
				const auto t_end = std::chrono::high_resolution_clock::now();
				kruskal_times_elapsed.push_back(std::chrono::duration<double, std::milli>(t_end-t_start).count());
				std::cout << "Finished Kruskal Run #" << ii << std::endl;

			}
			double kruskal_average = std::accumulate( kruskal_times_elapsed.begin(), kruskal_times_elapsed.end(), 0.0)/kruskal_times_elapsed.size();
			kruskal_average /= 1000;
			resultfile << v << "," << p << "," << prim_average << "," << kruskal_average <<  "\n";



		}
	}
	resultfile.close();





	//ks->solveMinimumSpanningTree(G);*/

	return 0;
}
