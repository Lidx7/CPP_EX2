/*
 * Author: Lidor Borofker.
 * ID: 326065646
 * e-Mail: Lidor.borofker@windowslive.com
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Graph{
        private:
            int edges_count;
            int vertices_count;
            vector<vector<int>> curr_graph;
            bool undirected;

        public:
            Graph();
            void loadGraph(std::vector<std::vector<int>> graph);
            string printGraph();
            vector<int>::size_type getEdgesCount();
            vector<int>::size_type getVerticesCount();
            int getGraphValue(int i, int j);
            vector<int> getNeighbors(int vertex);
            bool getUndirected();

            Graph operator+(const Graph &g);
            Graph operator*(const Graph &g);
            Graph operator=(const Graph &g);
            Graph operator+=(const Graph &g);
            Graph operator*=(const Graph &g);
            bool operator==(const Graph &g);
            bool operator!=(const Graph &g);            
    };
}

#endif