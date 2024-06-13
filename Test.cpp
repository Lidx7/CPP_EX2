#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;
using ariel::Graph;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace ariel;

/*TODO: Add more relevant test cases here
initiate a readme file
*/

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    g3.loadGraph(expectedGraph);
    CHECK(g4.printGraph() == g3.printGraph());
    g1 *= g2;
    CHECK(g4.printGraph() == g1.printGraph());
}
TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g2 - g1;
    vector<vector<int>> expectedGraph = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}};
    CHECK(g3.printGraph() == "[0, 0, 1]\n[0, 0, 1]\n[1, 1, 0]\n");
}

TEST_CASE("Test graph assignment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    g2 = g1;
    CHECK(g2.printGraph() == g1.printGraph());
}

TEST_CASE("Test graph post ++ operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    
    ariel::Graph g2 = g1++;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g3.loadGraph(expectedGraph);
    CHECK(g1.printGraph() == (g3).printGraph());
    CHECK(g1.printGraph() != g2.printGraph());
    g2++;
    CHECK(g2.printGraph() == g3.printGraph());
}

TEST_CASE("Test graph pre ++ operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = ++g1;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g3.loadGraph(expectedGraph);
    CHECK(g2.printGraph() == (g3).printGraph());
    CHECK(g1.printGraph() == g2.printGraph());

}

TEST_CASE("Test graph ++/-- operators on a nill Graph"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g4;
    vector<vector<int>> nillGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g4.loadGraph(nillGraph);
    g1--;
    CHECK(g1.printGraph() == g4.printGraph());
    g1++;
    CHECK(g1.printGraph() == g4.printGraph());


}

TEST_CASE("Test graph pre -- operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);
    
    ariel::Graph g2 = --g1;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(expectedGraph);
    CHECK(g1.printGraph() == (g3).printGraph());
    CHECK(g1.printGraph() == g2.printGraph());
}

TEST_CASE("Test graph post -- operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);
    
    ariel::Graph g2 = g1--;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(expectedGraph);
    CHECK(g1.printGraph() == (g3).printGraph());
    CHECK(g1.printGraph() != g2.printGraph());
    g2--;
    CHECK(g2.printGraph() == g3.printGraph());
}

TEST_CASE("Test graph addition assignment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 += g2;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g3.loadGraph(expectedGraph);
    CHECK(g1.printGraph() == g3.printGraph());
}

TEST_CASE("Test graph subtraction assignment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g2 -= g1;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}};
    g3.loadGraph(expectedGraph);
    CHECK(g2.printGraph() == g3.printGraph());
}

TEST_CASE("Test graph multiplication assignment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 *= g2;
    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    g3.loadGraph(expectedGraph);
    CHECK(g1.printGraph() == (g3).printGraph());
}

TEST_CASE("Test graph equality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(weightedGraph);
    bool ans = g1 == g1;
    CHECK(ans);
    CHECK(&g2 == &g2);
    CHECK(g1 == g2);
}

TEST_CASE("Test graph inequality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 != g2);
    CHECK(g2 != g1);
    CHECK_FALSE(g1 != g1);
    CHECK_FALSE(g2 != g2);
}

TEST_CASE("Test graph less than operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 < g2);
    CHECK_FALSE(g2 < g1);
    CHECK_FALSE(g1 < g1);
    CHECK_FALSE(g2 < g2);
}

TEST_CASE("Test graph greater than operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK_FALSE(g1 > g2);
    CHECK(g2 > g1);
    CHECK_FALSE(g1 > g1);
    CHECK_FALSE(g2 > g2);
}

TEST_CASE("Test graph less than or equal to operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 <= g2);
    CHECK_FALSE(g2 <= g1);
    CHECK(g1 <= g1);
    CHECK(g2 <= g2);
}

TEST_CASE("Test graph greater than or equal to operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK_FALSE(g1 >= g2);
    CHECK(g2 >= g1);
    CHECK(g1 >= g1);
    CHECK(g2 >= g2);
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);

    
    CHECK_THROWS(g1 /= 0);
}
TEST_CASE("Test graph comparison with nil graph"){

    ariel::Graph nilGraph;
    ariel::Graph expectedNil;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    expectedNil.loadGraph(nil);
    CHECK(nilGraph-- == expectedNil);
    CHECK(nilGraph++ == expectedNil);
    CHECK(--nilGraph == expectedNil);
    CHECK(++nilGraph == expectedNil);
}

TEST_CASE("Test graph addition with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    ariel::Graph g3 = g1 + nilGraph;
    CHECK(g3.printGraph() == g1.printGraph());
}

TEST_CASE("Test graph subtraction with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    ariel::Graph g3 = g1 - nilGraph;
    CHECK(g3.printGraph() == g1.printGraph());
}

TEST_CASE("Test graph multiplication with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    ariel::Graph g3 = g1 * nilGraph;
    CHECK(g3.printGraph() == nilGraph.printGraph());
}

TEST_CASE("Test graph equality with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    CHECK_FALSE(g1 == nilGraph);
    CHECK_FALSE(nilGraph == g1);
    CHECK(g1 == g1);
    CHECK(nilGraph == nilGraph);
}

TEST_CASE("Test graph inequality with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    CHECK(g1 != nilGraph);
    CHECK(nilGraph != g1);
    CHECK_FALSE(g1 != g1);
    CHECK_FALSE(nilGraph != nilGraph);
}

TEST_CASE("Test graph less than operator with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    CHECK_FALSE(g1 < nilGraph);
    CHECK(nilGraph < g1);
    CHECK_FALSE(g1 < g1);
    CHECK_FALSE(nilGraph < nilGraph);
}

TEST_CASE("Test graph greater than operator with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    CHECK(g1 > nilGraph);
    CHECK_FALSE(nilGraph > g1);
    CHECK_FALSE(g1 > g1);
    CHECK_FALSE(nilGraph > nilGraph);
}

TEST_CASE("Test graph less than or equal to operator with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    CHECK_FALSE(g1 <= nilGraph);
    CHECK(nilGraph <= g1);
    CHECK(g1 <= g1);
    CHECK(nilGraph <= nilGraph);
}

TEST_CASE("Test graph greater than or equal to operator with nil graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph nilGraph;
    vector<vector<int>> nil = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    nilGraph.loadGraph(nil);
    CHECK(g1 >= nilGraph);
    CHECK_FALSE(nilGraph >= g1);
    CHECK(g1 >= g1);
    CHECK(nilGraph >= nilGraph);
}

