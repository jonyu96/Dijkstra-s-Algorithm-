//
//  Galaxy.cc
//  Assignment3
//
//  Created by Jonathan Yu on 5/28/18.
//  Copyright © 2018 Jonathan Yu. All rights reserved.
//

#include "Galaxy.h"

using namespace std;

// dump Itinerary routes for each planet as well as:
// 1) Arrival Time
// 2) Total Enroute Time
// 3) Time in Space
void Itinerary::dump(Fleet& fleet, std::ostream& out,
                     int count) {
    
    int size = destinations.size();
    int timeInSpace = 0;
    string previousPlanet = origin->name;
    
    out << "########## " << "Itinerary #" << count <<  " ##########\n\n";
    
    for (int i = size - 1; i >= 0; i--) {
        out << fleet.name(legs[i].id) << "\t";
        out << previousPlanet << "\t" << legs[i].departure_time << "\t";
        out << destinations[i]->name << "\t" << legs[i].arrival_time;
        timeInSpace += legs[i].arrival_time - legs[i].departure_time;
        previousPlanet = destinations[i]->name;
        out << endl;
    }
    
    out << endl;
    out << "Arrival Time: " << legs[0].arrival_time << endl;
    out << "Total Enroute Time: ";
    out << legs[0].arrival_time - legs[size - 1].departure_time << endl;
    out << "Time in Space: " << timeInSpace << endl;
}

// print Itineraries for each planet (cout)
void Itinerary::print(Fleet& fleet, std::ostream& out) {
    int size = destinations.size();
    string previousPlanet = origin->name;
    
    out << "#" << origin->name << " --> " << destinations[0]->name << endl;
    for (int i = size - 1; i >= 0; i--) {
        out << fleet.name(legs[i].id) << "\t";
        out << previousPlanet << "\t" << legs[i].departure_time << "\t";
        out << destinations[i]->name << "\t" << legs[i].arrival_time;
        previousPlanet = destinations[i]->name;
        out << endl;
    }
    out << endl;
}

// print the legs scheduled for each edge (pair of planets)
void Edge::dump(Galaxy* galaxy) {
    if (legs.size() != 0) {
        cerr << destination->name << " |";
        cerr << time << "|" << endl;
        for (int i = 0; i < legs.size(); i++) {
            
            cerr << "\t" << galaxy->fleet.name(legs[i].id) << "\t";
            cerr << "[" << legs[i].departure_time << "\t";
            cerr << legs[i].arrival_time << "]" << endl;
        }
        cerr << endl;
    }
}
