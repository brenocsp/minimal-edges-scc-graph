#ifndef KOSARAJU_H
#define KOSARAJU_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//scc = strongly connected components
class SCC {
    public:
        SCC(vector<vector<int>> graph, int numOfVertexes);
        void identifyVertexesSCC();
        void generateSCCgraph();
        void printNumMinimalEdges();

    private:
        //métodos privados
        vector<vector<int>> reverseGraph(vector<vector<int>> graph, int numOfVertexes);
        void fillOrderDFS(int vertex, bool* visited, vector<int>& fillOrderStack);
        void DFS(vector<vector<int>> graph, int vertex, bool* visitedVertexes);
        int getNumSinks(vector<vector<int>> graph, int numOfVertexes);
        int getNumSources(vector<vector<int>> graph, int numOfVertexes);

        //atributos privados
        int _numOfVertexes;
        int _numSCC;
        vector<vector<int>> _graph;
        vector<int> _vertexesSCC; // vetor no qual cada vértice possui um id que representa a qual SCC ele faz parte
        vector<vector<int>> _SCCgraph; // grafo que representa cada SCC do grafo original como vértices e as arestas conforme o grafo original
};

#endif