//
//  Reader.h
//  Assignment3
//
//  Created by Jonathan Yu on 5/28/18.
//  Copyright © 2018 Jonathan Yu. All rights reserved.
//

#ifndef Reader_h
#define Reader_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <map>

#include "Galaxy.h"

// container storing information on list of conduits:
// 1) starting planet 2) destination planet 3) travel time
struct Travel_Times {
    
    std::vector<std::pair<std::string, std::string>> passages;
    std::vector<int> times;
    int size = 0;
};

class Reader {
public:
    
    // constructors/destructor
    Reader();
    Reader(std::istream& input, Travel_Times* constraints);
    ~Reader();
    
    Galaxy* load();
    
private:
    
    // Route structure under construction.
    Galaxy* galaxy;
    
    // construct galaxy
    void constructGalaxy();
    
    // read schedule
    void readSchedule();
    
    // print structure of galaxy
    void dumpGalaxy();
    
    // Verify that that current leg is a valid continuation of the
    // previous leg or the beginning of the route for another ship.
    void validate();
    void printLeg();
    
    static const int MIN_LAYOVER_TIME = 4;
    std::istream& input;
    
    // Data structure holding the travel times between planets.
    Travel_Times* constraints;
    
    // Planet name to planet object
    std::map<std::string, Planet*> planets;
    
    // Planet-name pair to edge object
    std::map<const Planet*, std::map<const Planet*, Edge*>> edges;
    
    // Ship name to id.
    std::map<std::string, Ship_ID> ships;
    
    // Previous leg information for validation.
    Ship_ID previous_ship_id;
    Planet* previous_destination_planet;
    int previous_arrival_time;
    
    // Current leg information
    Ship_ID ship_id;
    Planet* departure_planet;
    Time departure_time;
    Planet* destination_planet;
    Time arrival_time;
    
};

#endif
