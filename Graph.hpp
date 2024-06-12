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

//TODO: try to reduce the duplicated const functions.
namespace ariel{
    class Graph{
        private:
            int edges_count;
            int vertices_count;
            vector<vector<int>> curr_graph;
            bool undirected;
            friend bool isSubmatrixAtPosition(const Graph &g1, const Graph &g2, int startRow, int startCol);
            friend bool containsSubmatrix(const Graph &g1, const Graph &g2);

        public:
            Graph();
            Graph(const Graph& other);
            void loadGraph(std::vector<std::vector<int>> graph);
            string printGraph();
            vector<int>::size_type getEdgesCount();
            vector<int>::size_type getEdgesCount() const;
            vector<int>::size_type getVerticesCount();
            vector<int>::size_type getVerticesCount() const;
            int getGraphValue(int i, int j);
            int getGraphValue(int i, int j) const;
            vector<int> getNeighbors(int vertex);
            bool getUndirected();

            /********************OPERATORS********************/
            friend ostream& operator<<(ostream& os, Graph &g);
            
            friend Graph operator+(Graph &g1, Graph &g2);
            friend void operator+=(Graph &g1, Graph &g2);
            friend Graph& operator++(Graph &g1);
            friend Graph operator++(Graph &g1, int);

            friend Graph operator-(Graph &g1, Graph &g2);
            friend void operator-=(Graph &g1, Graph &g2);
            friend Graph& operator--(Graph &g1);
            friend Graph operator--(Graph &g1, int);

            friend Graph operator*(Graph &g1, Graph &g2);
            friend void operator*=(Graph &g1, Graph &g2);
            friend void operator*=(Graph &g1, int scalar);
            friend Graph operator*(Graph &g1, int scalar);
            friend Graph operator*(int scalar, Graph &g1);

            friend void operator/= (Graph &g1, int scalar);

            friend Graph operator-(Graph &g1);
            friend Graph operator+(Graph &g1);

            friend bool operator==(const Graph g1, const Graph g2);
            friend bool operator!=(const Graph g1, const Graph g2);
            friend bool operator>(const Graph g1, const Graph g2);
            friend bool operator<(const Graph g1, const Graph g2);
            friend bool operator>=(const Graph g1, const Graph g2);
            friend bool operator<=(const Graph g1, const Graph g2);

           
    };
}

#endif