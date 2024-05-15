/*
 * Author: Lidor Borofker.
 * ID: 326065646
 * e-Mail: Lidor.borofker@windowslive.com
 */

#include "Algorithms.hpp"
#include "Graph.hpp"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using namespace ariel;



    Algorithms::Algorithms(){
        curr_graph = vector<vector<int>>();
    }


    bool Algorithms::isConnected(Graph g) {
        vector<bool> visited(g.getVerticesCount(), false);

        dfs(g, 0, -1, visited);

        for (bool v : visited) {
            if (!v)
                return false;
        }

        return true;
    }

    string Algorithms::shortestPath(Graph g, vector<int>::size_type start, vector<int>::size_type end) {
        vector<int> distances = vector<int>(g.getVerticesCount(), INT32_MAX);
        vector<bool> included_stp = vector<bool>(g.getVerticesCount(), false);
        distances[start] = 0;

        for (vector<bool>::size_type i = 0; i < g.getVerticesCount() - 1; i++) {
            vector<int>::size_type u = (vector<int>::size_type)minDistance(distances, included_stp);
            included_stp[u] = true;

            for (vector<int>::size_type j = 0; j < g.getVerticesCount(); j++) {
                if (g.getGraphValue(u, j) != 0 && !included_stp[j] && distances[u] != INT32_MAX &&
                    distances[j] > distances[u] + g.getGraphValue(u, j)) {
                    distances[j] = distances[u] + g.getGraphValue(u, j);
                }
            }
            if (u == end)
                break;
        }

        if (distances[end] == INT32_MAX)
            return "-1";

        string ans = to_string(end);
        vector<int>::size_type current = end;
        while (current != start) {
            for (vector<int>::size_type j = 0; j < g.getVerticesCount(); j++) {
                if (g.getGraphValue(j, current) != 0 && distances[current] == distances[j] + g.getGraphValue(j, current)) {
                    ans = to_string(j) + "->" + ans;
                    current = j;
                    break;
                }
            }
        }

        return ans;
    }

    bool Algorithms::isContainsCycle(Graph g) {
        if(g.getUndirected()){
            vector<int> adj[g.getVerticesCount()];
            for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
                for(vector<int>::size_type j=0; j < g.getVerticesCount(); j++){
                    if(g.getGraphValue(i, j) != 0){
                        adj[i].push_back(j);
                    }
                }
            }
            vector<bool> visited(g.getVerticesCount(), false);

            for (vector<int>::size_type i = 0; i < g.getVerticesCount(); ++i) {
                if (!visited[i] && isCyclicUndirected(adj, i, g.getVerticesCount(), visited)) { 
                    return true;
                }
            }

            return false;
        }
        vector<bool> visited(g.getVerticesCount(), false);

        for (vector<int>::size_type i = 0; i < g.getVerticesCount(); ++i) {
            if (!visited[i] && dfs(g, i, -1, visited)) { 
                return true;
            }
        }

        return false;
    }

    bool Algorithms::isCyclicUndirected(vector<int> adj[], int start, vector<bool>::size_type vertex, vector<bool>& visited){
        queue<int> q;

        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            if (visited[(vector<bool>::size_type)vertex] == 1) {
                return true;
            }
            visited[(vector<bool>::size_type)vertex] = 1;
            for (int i : adj[vertex]) {
                if (visited[(vector<bool>::size_type)i] == 0) {
                    q.push(i);
                }
            }
        }
        return false;
    }

    string Algorithms::isBipartite(Graph g){
        if(hasLoopbacks(g)){
            return "The graph is not bipartite";
        }
        vector<int> color = vector<int>(g.getVerticesCount(), -1);
        color[0] = 1;

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            vector<int>::size_type curr = (vector<int>::size_type)q.front();
            q.pop();

            for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
                if(g.getGraphValue(curr, i) != 0){
                    if(color[i] == -1){
                        color[i] = 1 - color[curr];
                        q.push(i);
                    }       
                    else if(g.getGraphValue(curr, i) && color[i] == color[curr]){ 
                        return "0"; //The graph is not bipartite
                    }
                }
            }
        }
        
        //printing the two sets
        string ans = "The graph is bipartite: A={";
        bool first = true;
        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            if(color[i] == 1){
                if(first){
                    ans += to_string(i);
                    first = false;
                }
                else{
                    ans += ", " + to_string(i);
                }
            }
        }
        ans += "}, B={";
        first = true;
        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            if(color[i] == 0){
                if(first){
                    ans += to_string(i);
                    first = false;
                }
                else{
                    ans += ", " + to_string(i);
                }
            }
        }
        ans += "}";

        return ans;
    }

    string Algorithms::negativeCycle(Graph g){
        vector<int> distances = vector<int>(g.getVerticesCount(), INT32_MAX); //initializing the "distances" vector with the closest value we can get to infinity
        bellmanFord(g, 0, distances);

        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            for(vector<int>::size_type j=0; j < g.getVerticesCount(); j++){
                if(g.getGraphValue(i, j) != 0 && distances[j] > distances[i] + g.getGraphValue(i, j)){
                    return "The graph contains a negative cycle";
                    
                }
            }
        }

        return "The graph does not have a negative cycle";
    }


                                        /************************
                                         *   Helper functions   *
                                         ************************/

    bool Algorithms::dfs(Graph& g, vector<bool>::size_type v, int parent, vector<bool>& visited) {
        visited[v] = true;

        for (int neighbor : g.getNeighbors(v)) {
            if (!visited[(vector<bool>::size_type)neighbor]) {
                if (dfs(g, (vector<bool>::size_type)neighbor, v, visited))
                    return true;
            } else if (neighbor != parent || parent == -1) {
                return true;
            }
        }
        return false;
    }


    //Please note that before calling the function for the first time, the "distances" vector should be initialized with the maximum possible value
    void Algorithms::bellmanFord(Graph g, vector<int>::size_type start, vector<int> &distances){ 
        distances[start] = 0;
        for(vector<int>::size_type i=0; i < g.getVerticesCount() - 1; i++){
            for(vector<int>::size_type j=0; j < g.getEdgesCount(); j++){
                if(g.getGraphValue(i, j) != 0 && distances[j] > distances[i] + g.getGraphValue(i, j)){
                    distances[j] = distances[i] + g.getGraphValue(i, j);
                }
            }
        }
    }
    
    //cecks for loopbacks in the graph
    bool Algorithms::hasLoopbacks(Graph g){
        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            if(g.getGraphValue(i, i) != 0){
                return true;
            }
        }

        return false;
    }

    int Algorithms::minDistance(vector<int> distances, vector<bool> visited){
        int min = INT32_MAX;
        int min_index = -1;

        for(vector<int>::size_type i=0; i < distances.size(); i++){
            if(!visited[i] && distances[i] <= min){
                min = distances[i];
                min_index = i;
            }
        }

        return min_index;
    }

    /************************************************************************************************************************/
