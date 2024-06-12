/*
 * Author: Lidor Borofker.
 * ID: 326065646
 * e-Mail: Lidor.borofker@windowslive.com
 */

#include "Graph.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

namespace ariel{
    Graph::Graph() : edges_count(0), vertices_count(0), curr_graph(), undirected(false){}
    Graph::Graph(const Graph& other) : edges_count(other.edges_count), vertices_count(other.vertices_count), curr_graph(other.curr_graph), undirected(other.undirected) {}


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
            ans += "[";
            ans += to_string(curr_graph[i][0]);

            for(j=1; j < vertices_count; j++){
                ans += ", " + to_string(curr_graph[i][j]);
            }
            ans += "]\n";
        }
        return ans;
    }

    vector<int>::size_type Graph::getEdgesCount(){
        return (vector<int>::size_type)edges_count;
    }
    vector<int>::size_type Graph::getEdgesCount() const{
        return (vector<int>::size_type)edges_count;
    }

    vector<int>::size_type Graph::getVerticesCount(){
        return (vector<int>::size_type)vertices_count;
    }
    vector<int>::size_type Graph::getVerticesCount() const{
        return (vector<int>::size_type)vertices_count;
    }

    int Graph::getGraphValue(int i, int j){
        return (int)curr_graph[(vector<int>::size_type)i][(vector<int>::size_type)j];
    }
    int Graph::getGraphValue(int i, int j) const{
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


                                        /***********************
                                         *      Operators      *
                                         ***********************/


    /*********************************PRINTING*********************************/
    
    ostream& operator<<(ostream& os, Graph &g){
        os << g.printGraph();
        return os;
    }

    /*********************************ADDITION*********************************/

    Graph operator+(Graph &g1, Graph &g2){
        if(g1.getVerticesCount() != g2.getVerticesCount()){
            throw invalid_argument("The graphs aren't the same size");
        }

        Graph new_graph;
        vector<vector<int>> adding;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(g1.getGraphValue(i, j) + g2.getGraphValue(i, j));
            }
            adding.push_back(row);
        }

        new_graph.loadGraph(adding);
        return new_graph;
    }

    void operator+=(Graph &g1, Graph &g2){
        if(g1.getVerticesCount() != g2.getVerticesCount()){
            throw invalid_argument("The graphs aren't the same size");
        }

        vector<vector<int>> adding;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(g1.getGraphValue(i, j) + g2.getGraphValue(i, j));
            }
            adding.push_back(row);
        }

        g1.loadGraph(adding);
    }

    Graph operator++(Graph &g1, int) {
        Graph temp = g1;
        

        vector<vector<int>> adding;
        for(vector<int>::size_type i = 0; i < g1.getVerticesCount(); i++) {
            vector<int> row;
            for(vector<int>::size_type j = 0; j < g1.getVerticesCount(); j++) {
                if (g1.getGraphValue(i, j) != 0) {
                    row.push_back(1 + g1.getGraphValue(i, j));
                } else {
                    row.push_back(0);
                }
            }
            adding.push_back(row);
        }

        g1.loadGraph(adding);
        return temp;
    }


    Graph& operator++(Graph &g1) {
        
        vector<vector<int>> adding;
        for(vector<int>::size_type i = 0; i < g1.getVerticesCount(); i++) {
            vector<int> row;
            for(vector<int>::size_type j = 0; j < g1.getVerticesCount(); j++) {
                if(g1.getGraphValue(i, j) != 0) {
                    row.push_back(1 + g1.getGraphValue(i, j));
                } else {
                    row.push_back(0);
                }
            }
            adding.push_back(row);
        }

        g1.loadGraph(adding);
        return g1;
    }



    /*********************************SUBTRACTION**********************************/

    Graph operator-(Graph &g1, Graph &g2){
        if(g1.getVerticesCount() != g2.getVerticesCount()){
            throw invalid_argument("The graphs aren't the same size");
        }

        Graph new_graph;
        vector<vector<int>> subtracting;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(g1.getGraphValue(i, j) - g2.getGraphValue(i, j));
            }
            subtracting.push_back(row);
        }

        new_graph.loadGraph(subtracting);
        return new_graph;
    }

    void operator-=(Graph &g1, Graph &g2){
        if(g1.getVerticesCount() != g2.getVerticesCount()){
            throw invalid_argument("The graphs aren't the same size");
        }

        vector<vector<int>> subtracting;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(g1.getGraphValue(i, j) - g2.getGraphValue(i, j));
            }
            subtracting.push_back(row);
        }

        g1.loadGraph(subtracting);
    }

    Graph operator--(Graph &g1, int) {
        Graph temp = g1;
        

        vector<vector<int>> adding;
        for(vector<int>::size_type i = 0; i < g1.getVerticesCount(); i++) {
            vector<int> row;
            for(vector<int>::size_type j = 0; j < g1.getVerticesCount(); j++) {
                if (g1.getGraphValue(i, j) != 0) {
                    row.push_back(g1.getGraphValue(i, j) - 1);
                } else {
                    row.push_back(0);
                }
            }
            adding.push_back(row);
        }

        g1.loadGraph(adding);
        return temp;
    }


    Graph& operator--(Graph &g1) {
        
        vector<vector<int>> adding;
        for(vector<int>::size_type i = 0; i < g1.getVerticesCount(); i++) {
            vector<int> row;
            for(vector<int>::size_type j = 0; j < g1.getVerticesCount(); j++) {
                if(g1.getGraphValue(i, j) != 0) {
                    row.push_back(g1.getGraphValue(i, j) - 1);
                } else {
                    row.push_back(0);
                }
            }
            adding.push_back(row);
        }

        g1.loadGraph(adding);
        return g1;
    }


    /*********************************MULTIPLICATION**********************************/
    
    Graph operator*(Graph &g1, Graph &g2){
        if(g1.getVerticesCount() != g2.getVerticesCount()){
            throw invalid_argument("The graphs aren't the same size");
        }

        vector<int>::size_type n = g1.getVerticesCount();
        Graph new_graph;
        vector<vector<int>> multiplying(n, vector<int>(n, 0)); // Initialize a n x n matrix with 0

        for(vector<int>::size_type i = 0; i < n; i++){
            for(vector<int>::size_type j = 0; j < n; j++){
                int sum = 0;
                for(vector<int>::size_type k = 0; k < n; k++){
                    sum += g1.getGraphValue(i, k) * g2.getGraphValue(k, j);
                }
                multiplying[i][j] = sum; // Set the computed sum for position (i, j)
            }
        }

        new_graph.loadGraph(multiplying);
        return new_graph;
    }

    void operator*=(Graph &g1, Graph &g2){
        if(g1.getVerticesCount() != g2.getVerticesCount()){
            throw invalid_argument("The graphs aren't the same size");
        }

        vector<int>::size_type n = g1.getVerticesCount();
        Graph new_graph;
        vector<vector<int>> multiplying(n, vector<int>(n, 0)); // Initialize a n x n matrix with 0

        for(vector<int>::size_type i = 0; i < n; i++){
            for(vector<int>::size_type j = 0; j < n; j++){
                int sum = 0;
                for(vector<int>::size_type k = 0; k < n; k++){
                    sum += g1.getGraphValue(i, k) * g2.getGraphValue(k, j);
                }
                multiplying[i][j] = sum; // Set the computed sum for position (i, j)
            }
        }

        g1.loadGraph(multiplying);
    }

    void operator*=(Graph &g1, int scalar){
        vector<vector<int>> multiplying;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(scalar * g1.getGraphValue(i, j));
            }
            multiplying.push_back(row);
        }

        g1.loadGraph(multiplying);
    }

    Graph operator*(Graph &g1, int scalar){
        Graph new_graph;
        vector<vector<int>> multiplying;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(scalar * g1.getGraphValue(i, j));
            }
            multiplying.push_back(row);
        }

        new_graph.loadGraph(multiplying);
        return new_graph;
    }

    /*TODO: check if this function is actually necessary, or is the function above is enough (is the placement of the scalar is important?) */
    Graph operator*(int scalar, Graph &g1){
        Graph new_graph;
        vector<vector<int>> multiplying;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(scalar * g1.getGraphValue(i, j));
            }
            multiplying.push_back(row);
        }

        new_graph.loadGraph(multiplying);
        return new_graph;
    }

    void operator/= (Graph &g1, int scalar){
        vector<vector<int>> dividing;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(g1.getGraphValue(i, j) / scalar);
            }
            dividing.push_back(row);
        }

        g1.loadGraph(dividing);
    }

    /*********************************UNARY**********************************/

    Graph operator-(Graph &g1){
        Graph new_graph;
        vector<vector<int>> subtracting;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(-1 * g1.getGraphValue(i, j));
            }
            subtracting.push_back(row);
        }
        new_graph.loadGraph(subtracting);
        return new_graph;
    }

    Graph operator+(Graph &g1){
        Graph new_graph;
        vector<vector<int>> adding;
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            vector<int> row;
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                row.push_back(1 * g1.getGraphValue(i, j));
            }
            adding.push_back(row);
        }
        new_graph.loadGraph(adding);
        return new_graph;
    }

   

    /*********************************COMPARISON**********************************/

    bool operator==(const Graph g1, const Graph g2){
        if(g1.getVerticesCount() != g2.getVerticesCount()){
            return false;
        }
        
        for(vector<int>::size_type i=0; i < g1.getVerticesCount(); i++){
            for(vector<int>::size_type j=0; j < g1.getVerticesCount(); j++){
                if(g1.getGraphValue(i, j) != g2.getGraphValue(i, j)){
                    return false;
                }
            }
        }

        return true;
    }

    bool operator!=(const Graph g1, const Graph g2){
        return !(g1 == g2);
    }

    bool operator>(const Graph g1, const Graph g2){
        if(g1 == g2){
            return false;
        }
        if(containsSubmatrix(g1, g2)){
            return true;
        }
        else if(g1.getEdgesCount() != g2.getEdgesCount()){

            if(g1.getEdgesCount() > g2.getEdgesCount()){
                return true;
            }
            else if(g1.getVerticesCount() > g2.getVerticesCount()){
                return true;
            }
        }

        return false;
    }

    bool operator<(const Graph g1, const Graph g2){
        if(g2 == g1){
            return false;
        }
        if(containsSubmatrix(g2, g1)){
            return true;
        }
        else if(g2.getEdgesCount() != g1.getEdgesCount()){

            if(g2.getEdgesCount() > g1.getEdgesCount()){
                return true;
            }
            else if(g2.getVerticesCount() > g1.getVerticesCount()){
                return true;
            }
        }

        return false;
    }

    bool operator>=(const Graph g1, const Graph g2){
        return (g1 == g2 || g1 > g2);
    }

    bool operator<=(const Graph g1, const Graph g2){
        return (g1 == g2 || g1 < g2);
    }


    // Function to check if the submatrix is found at a given starting position
    bool isSubmatrixAtPosition(const Graph &g1, const Graph &g2, vector<int>::size_type startRow, vector<int>::size_type startCol) {
        int subRows = g1.getVerticesCount();
        int subCols = g1.getVerticesCount();
        
        for (vector<int>::size_type i = 0; i < subRows; ++i) {
            for (vector<int>::size_type j = 0; j < subCols; ++j) {
                if (g1.getGraphValue((startRow + i),(startCol + j)) != g2.getGraphValue(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Function to check if a matrix contains a given submatrix
    bool containsSubmatrix(const Graph &g1, const Graph &g2) {
        int rows = g1.getVerticesCount();
        int cols = g1.getVerticesCount();
        int subRows = g2.getVerticesCount();
        int subCols = g2.getVerticesCount();

        if(subRows > rows || subCols > cols){
            return false;
        }

        // Loop through each possible starting point
        for (vector<int>::size_type i = 0; i <= rows - subRows; ++i) {
            for (vector<int>::size_type j = 0; j <= cols - subCols; ++j) {
                if (isSubmatrixAtPosition(g1, g2, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
}