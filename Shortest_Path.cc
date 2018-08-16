//
//  Shortest_Path.cc
//  Assignment3
//
//  Created by Jonathan Yu on 5/21/18.
//  Copyright © 2018 Jonathan Yu. All rights reserved.
//
//  Constructs a galaxy from the list of conduits and
//  finds the shortest longest-path of a pair of planets.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "Reader.h"

using namespace std;

void readConduits(ifstream& input, Travel_Times*& constraints) {
    
    string line;
    while (getline(input, line)) {
        
        if (line.size() == 0 || line.at(0) == '#') continue;
        istringstream iss(line);
        
        string startPlanet;
        iss >> startPlanet;
        while (iss.get() == ' ') {
            string temp;
            iss >> temp;
            startPlanet += " " + temp;
        }
        
        string endPlanet;
        iss >> endPlanet;
        if (iss.get() == ' ') {
            string temp;
            iss >> temp;
            endPlanet += " " + temp;
        }
        
        int time;
        iss >> time;
        
        pair<string, string> temp = make_pair(startPlanet, endPlanet);
        constraints->passages.push_back(temp);
        constraints->times.push_back(time);
        constraints->size++;
    }
}

int main(int argc, char** argv) {
    
    // check if required file arguments are passed
    if (argc < 3) {
        cerr << "Required input files missing!" << endl;
        return EXIT_FAILURE;
    }
    
    // open Conduits.txt
    ifstream input;
    input.open(argv[1]);
    
    // read and process list of conduits 
    Travel_Times* constraints = new Travel_Times();
    if (input.is_open()) {
        readConduits(input, constraints);
    } else {
        return EXIT_FAILURE;
    }
    input.close();
    
    // open Routes.txt
    input.open(argv[2]);
    if (!input.is_open()) {
        return EXIT_FAILURE;
    }
    
    Reader reader(input, constraints);
    Galaxy* galaxy = reader.load();
    galaxy->dump();
    galaxy->search();
    
    input.close();
    
    return EXIT_SUCCESS;
}
