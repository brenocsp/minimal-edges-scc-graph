#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <vector>

using namespace std;

class Airline {
    public:
        Airline(int numOfAirports, int numOfRoutes);
        void createAirNetwork();        
        vector<vector<int>> getAirNetwork() {return _airNetwork;};

    private:
        int _numOfAirports;
        int _numOfRoutes;
        vector<vector<int>> _airNetwork;
};

#endif