/*
 * Author: Lidor Borofker.
 * ID: 326065646
 * e-Mail: Lidor.borofker@windowslive.com
 */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Algorithms{
        private:
            vector<vector<int>> curr_graph;
            static bool dfs(Graph& g, vector<bool>::size_type v, int parent, vector<bool>& visited);
            static void bellmanFord(ariel::Graph g, vector<int>::size_type start, vector<int> &distances);
            static bool hasLoopbacks(ariel::Graph g);
            static int minDistance(vector<int> distances, vector<bool> visited);
            static bool isCyclicUndirected(vector<int> adj[], int start, vector<bool>::size_type vertex, vector<bool>& visited);
            
        public:
            Algorithms();
            static bool isConnected(ariel::Graph g);
            static string shortestPath(ariel::Graph g, vector<int>::size_type start, vector<int>::size_type end);
            static bool isContainsCycle(ariel::Graph g);
            static string isBipartite(ariel::Graph g);
            static string negativeCycle(ariel::Graph g);
    };
}

#endif