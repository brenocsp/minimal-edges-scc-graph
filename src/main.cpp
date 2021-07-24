#include "Airline.hpp"
#include "SCC.hpp"

int main() {

    int numOfAirports;
    int numOfRoutes;
    cin >> numOfAirports >> numOfRoutes;

    Airline *airline = new Airline(numOfAirports, numOfRoutes);
    airline->createAirNetwork();

    SCC *scc = new SCC(airline->getAirNetwork(), numOfAirports);
    scc->identifyVertexesSCC();
    scc->generateSCCgraph();
    scc->printNumMinimalEdges();

    delete scc;
    delete airline;

    return 0;
}