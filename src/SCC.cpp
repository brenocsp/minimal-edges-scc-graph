#include "SCC.hpp"

SCC::SCC(vector<vector<int>> graph, int numOfVertexes) {
    _graph = graph;
    _numOfVertexes = numOfVertexes;
    _numSCC = 0;
}

void SCC::fillOrderDFS(int vertex, bool* visitedVertexes, vector<int>& fillOrderStack) {
    visitedVertexes[vertex] = true;
    for (int i : _graph[vertex]) {
        if (visitedVertexes[i] == false) {
            fillOrderDFS(i, visitedVertexes, fillOrderStack);
        }
    }
    fillOrderStack.insert(fillOrderStack.begin(), vertex);
}

vector<vector<int>> SCC::reverseGraph(vector<vector<int>> graph, int numOfVertexes) {
    vector<vector<int>> reversedGraph(numOfVertexes);
    for (int i = 0; i < numOfVertexes; i++) {
        for (int j : graph[i]) {
            reversedGraph[j].push_back(i);
        }
    }
    return reversedGraph;
}

void SCC::DFS(vector<vector<int>> graph, int vertex, bool* visitedVertexes) {
    visitedVertexes[vertex] = true;
    _vertexesSCC[vertex] = _numSCC-1;
    for (int i : graph[vertex]) {
        if (visitedVertexes[i] == false) {
            DFS(graph, i, visitedVertexes);
        }
    }
}

void SCC::identifyVertexesSCC() {
    vector<int> fillOrderStack;
    bool visitedVertexes[_numOfVertexes] = {0};
    for (int i = 0; i < _numOfVertexes; i++) {
        if (visitedVertexes[i] == false) {
            fillOrderDFS(i, visitedVertexes, fillOrderStack);
        }
    }    

    vector<vector<int>> reversedGraph = reverseGraph(_graph, _numOfVertexes);
    _vertexesSCC.resize(_numOfVertexes);

    memset(visitedVertexes, false, sizeof(visitedVertexes));
    for (int i = 0; i < _numOfVertexes; i++) {
        int currentVertex = fillOrderStack[i];
        if (visitedVertexes[currentVertex] == false) {
            _numSCC++;
            DFS(reversedGraph, currentVertex, visitedVertexes);
        }
    }
}

bool SCC::graphContains(vector<vector<int>> graph, int origin, int destination) {
    for (int i : graph[origin]) {
        if (i == destination) return true;
    }
    return false;
}

void SCC::generateSCCgraph() {
    _SCCgraph.resize(_numSCC);
    for (int i = 0; i < _numOfVertexes; i++) {
        for (int j : _graph[i]) {
            if (_vertexesSCC[i] != _vertexesSCC[j] && !graphContains(_SCCgraph, _vertexesSCC[i], _vertexesSCC[j])) {
                _SCCgraph[_vertexesSCC[i]].push_back(_vertexesSCC[j]);
            }
        }
    }
}

int SCC::getNumSinks(vector<vector<int>> graph, int numOfVertexes) {
    int numZeroOutDegree = 0;
    for (int i = 0; i < numOfVertexes; i++) {
        if(graph[i].size() == 0) numZeroOutDegree++;
    }
    return numZeroOutDegree;
}

int SCC::getNumSources(vector<vector<int>> graph, int numOfVertexes) {
    int numZeroInDegree = 0;
    vector<vector<int>> reversedGraph = reverseGraph(graph, numOfVertexes);
    for (int i = 0; i < numOfVertexes; i++) {
        if(reversedGraph[i].size() == 0) numZeroInDegree++;
    }
    return numZeroInDegree;
}

void SCC::printNumMinimalEdges() {
    int numSinks = getNumSinks(_SCCgraph, _numSCC);
    int numSources = getNumSources(_SCCgraph, _numSCC);
    cout << (numSinks > numSources ? numSinks : numSources) << endl;
}
