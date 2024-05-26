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
            friend bool isSubmatrixAtPosition(Graph &g1, Graph &g2, int startRow, int startCol);
            friend bool containsSubmatrix(Graph &g1, Graph &g2);

        public:
            Graph();
            void loadGraph(std::vector<std::vector<int>> graph);
            string printGraph();
            vector<int>::size_type getEdgesCount();
            vector<int>::size_type getVerticesCount();
            int getGraphValue(int i, int j);
            vector<int> getNeighbors(int vertex);
            bool getUndirected();

            /********************OPERATORS********************/
            friend ostream& operator<<(ostream& os, Graph &g);
            friend Graph operator+(Graph &g1, Graph &g2);
            friend void operator+=(Graph &g1, Graph &g2);
            friend void operator++(Graph &g1);
            friend void operator++(Graph &g1,int);

            friend Graph operator-(Graph &g1, Graph &g2);
            friend void operator-=(Graph &g1, Graph &g2);
            friend void operator--(Graph &g1);
            friend Graph operator--(Graph &g1,int);

            friend Graph operator*(Graph &g1, Graph &g2);
            friend void operator*=(Graph &g1, Graph &g2);
            friend void operator*=(Graph &g1, int scalar);
            friend void operator*(Graph &g1, int scalar);
            friend void operator*(int scalar, Graph &g1);

            friend void operator/= (Graph &g1, int scalar);

            friend Graph operator-(Graph &g1);
            friend Graph operator+(Graph &g1);

            friend bool operator==(Graph &g1, Graph &g2);
            friend bool operator!=(Graph &g1, Graph &g2);
            friend bool operator>(Graph &g1, Graph &g2);
            friend bool operator<(Graph &g1, Graph &g2);
            friend bool operator>=(Graph &g1, Graph &g2);
            friend bool operator<=(Graph &g1, Graph &g2);

           
    };
}

#endif