/*
 * Author: Lidor Borofker.
 * ID: 326065646
 * e-Mail: Lidor.borofker@windowslive.com
 */

#include "Graph.hpp"
#include <iostream>
using namespace std;

using namespace ariel;

    Graph::Graph() : edges_count(0), vertices_count(0), curr_graph(), undirected(false){}

    void Graph::loadGraph(std::vector<std::vector<int>> given_graph){
        if(given_graph.empty()){
            throw invalid_argument("The graph is empty");
        }
        if(given_graph.size() != given_graph[0].size()){
            throw invalid_argument("The graph is not a square matrix");
        }

        curr_graph = given_graph;
        vertices_count = given_graph.size();
        int found_edges = 0;
        bool is_undirected = true;

        for(vector<int>::size_type i=0; i < vertices_count; i++){
            for(vector<int>::size_type j=0; j < vertices_count; j++){
                curr_graph[i][j] = given_graph[i][j];
                if(curr_graph[i][j] != 0){
                    found_edges++;
                }
                if(curr_graph[i][j] != curr_graph[j][i]){
                    is_undirected = false;
                }
            }
        }

        if(is_undirected){
            found_edges /= 2;
            undirected = true;
        }

        edges_count = found_edges;
    }

    //TODO: change this function from void to returning a string, and make sure the formatting is right
    string Graph::printGraph(){
        string ans = "";

        vector<int>::size_type i=0, j=0;
        for(i=0; i < vertices_count; i++){
            ans += "{";

            for(j=0; j < vertices_count-1; j++){
                ans += curr_graph[i][j] + ", ";
            }

            ans += curr_graph[i][j+1];
            ans += "},\n";
        }

        return ans;
    }

    vector<int>::size_type Graph::getEdgesCount(){
        return (vector<int>::size_type)edges_count;
    }

    vector<int>::size_type Graph::getVerticesCount(){
        return (vector<int>::size_type)vertices_count;
    }

    int Graph::getGraphValue(int i, int j){
        return (int)curr_graph[(vector<int>::size_type)i][(vector<int>::size_type)j];
    }

    bool Graph::getUndirected(){
        return undirected;
    }

    vector<int> Graph::getNeighbors(int v) {
        vector<int>::size_type vertex = (vector<int>::size_type)v;
        vector<int> neighbors;
        for (vector<int>::size_type i = 0; i < curr_graph[vertex].size(); ++i) {
            if (curr_graph[vertex][i] == 1) { 
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }
