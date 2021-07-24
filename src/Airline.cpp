#include "Airline.hpp"

Airline::Airline(int numOfAirports, int numOfRoutes) {
    _numOfAirports = numOfAirports;
    _numOfRoutes = numOfRoutes;
}

void Airline::createAirNetwork() {
    vector<vector<int>> airNetwork(_numOfAirports);
    int origin, destination;

    for (int i = 0; i < _numOfRoutes; i++) {
        cin >> origin >> destination;
        airNetwork[origin-1].push_back(destination-1);
    }
    _airNetwork = airNetwork;
}