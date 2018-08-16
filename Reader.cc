//
//  Reader.cc
//  Assignment3
//
//  Created by Jonathan Yu on 5/28/18.
//  Copyright © 2018 Jonathan Yu. All rights reserved.

#include "Reader.h"

using namespace std;

Reader::Reader() : input(cin), constraints(), previous_ship_id(),
                   previous_destination_planet(), previous_arrival_time(), ship_id(),
                   departure_planet(), departure_time(), destination_planet(),
                   arrival_time(), planets(), edges(), ships(), galaxy() {}

Reader::Reader(istream& input, Travel_Times* constraints) : input(input),
                   constraints(constraints), previous_ship_id(-1), previous_destination_planet(nullptr),
                   previous_arrival_time(-1), ship_id(-1), departure_planet(nullptr),
                   departure_time(0), destination_planet(nullptr), arrival_time(0),
                   planets(), edges(), ships(), galaxy(nullptr) {}

Reader::~Reader() {}

Galaxy* Reader::load() {
    
    constructGalaxy();
    readSchedule();
    
    return galaxy;
}

void Reader::constructGalaxy() {
    galaxy = new Galaxy();
    
    for (int i = 0; i < constraints->size; i++) {
        
        string start = constraints->passages[i].first;
        string destination = constraints->passages[i].second;
        int time = constraints->times[i];
        
        Planet* startPlanet;
        Planet* destPlanet;
        
        if (planets.count(start) == 0) {
            startPlanet = new Planet(start);
            planets[start] = startPlanet;
            galaxy->add(startPlanet);
        } else {
            startPlanet = planets[start];
        }
        
        if (planets.count(destination) == 0) {
            destPlanet = new Planet(destination);
            planets[destination] = destPlanet;
            galaxy->add(destPlanet);
        } else {
            destPlanet = planets[destination];
        }
        
        Edge* fromStart = new Edge(destPlanet, time);
        startPlanet->add(fromStart);
        edges[startPlanet][destPlanet] = fromStart;
        
        Edge* fromDest = new Edge(startPlanet, time);
        destPlanet->add(fromDest);
        edges[destPlanet][startPlanet] = fromDest;
    }
    dumpGalaxy();
}

void Reader::readSchedule() {
    cerr << "########## Schedule ##########\n\n";
    string line;
    while (getline(input, line)) {
        
        // lines that are empty or start with '#' are ignored
        if (line.size() == 0 || line.at(0) == '#') continue;
        istringstream iss(line);
        
        // read ship name
        string ship;
        iss >> ship;
        while (iss.get() == ' ') {
            string temp;
            iss >> temp;
            ship += " " + temp;
        }
        if (ships.count(ship) == 0) {
            ship_id = galaxy->fleet.add(ship);
            ships[ship] = ship_id;
        }
        
        // read departing planet and time
        string departPlanet;
        iss >> departPlanet;
        while (iss.get() == ' ') {
            string temp;
            iss >> temp;
            departPlanet += " " + temp;
        }
        iss >> departure_time;
        
        // read destination planet and arrival time
        string destPlanet;
        iss >> destPlanet;
        while (iss.get() == ' ') {
            string temp;
            iss >> temp;
            destPlanet += " " + temp;
        }
        iss >> arrival_time;
        
        this->departure_planet = planets[departPlanet];
        this->destination_planet = planets[destPlanet];
        
        // validate route is valid and consistent with galaxy structure
        validate();
        
        Leg leg(ship_id, departure_time, arrival_time);
        edges[this->departure_planet][this->destination_planet]->add(leg);
        
        // print current leg
        printLeg();
    }
    cerr << endl;
}

void Reader::dumpGalaxy() {
    
    cerr << "########## Galaxy ##########\n";
    cerr << "Number of Planets: " << planets.size() << endl;
    cerr << endl;

    for (auto& it : edges) {
        cerr << "- " << it.first->name << " -" << endl;
        cerr << it.second.size() << " Destinations:" << endl;
        for (auto& it2 : it.second) {
            cerr << "\t[" << it2.first->name << ": " << it2.second->time << "]" << endl;
        }
        cerr << endl;
    }
}

void Reader::validate() {
    
    // check trip from departure planet to destination planet exists in conduits
    if (edges[departure_planet].count(destination_planet) == 0) {
        cerr << "Invalid trip!" << endl;
        cerr << "Passage from departure planet to destination planet does not exist!" << endl;
        cerr << "Departure planet: " << departure_planet->name;
        cerr << "\tDestination planet: " << destination_planet->name;
        
        exit(EXIT_FAILURE);
    }
    
    // if trip is a non-transfer, check two things:
    // 1) previous destination planet and departure planet are same
    // 2) departure time is 4 or more hours past the previous arrival time
    if (ship_id == previous_ship_id) {
        if (previous_destination_planet != departure_planet) {
            cerr << "Invalid trip!" << endl;
            cerr << "-- NON-TRANSFER: Previous destination planet";
            cerr << " must be same as departure planet!" << endl;
            cerr << "Previous destination planet: " << previous_destination_planet->name;
            cerr << "\tDeparture planet: " << departure_planet->name << endl;
            exit(EXIT_FAILURE);
        }
        
        if (departure_time < (previous_arrival_time + MIN_LAYOVER_TIME)) {
            cerr << "Invalid trip!" << endl;
            cerr << "-- NON-TRANSFER: Departure time is not";
            cerr << "4 or more hours after previous arrival time!" << endl;
            cerr << "Departure time: " << departure_time << endl;
            cerr << "Previous arrival time: " << previous_arrival_time << endl;
        }
    }
    
    // if trip is first of itinerary or a transfer type:
    // 1) if first trip, check departure time is at 0
    // 2) if transfer type, check departure time is 4 or more hours past previous
    // arrival time
    if (previous_ship_id != ship_id) {
        if (previous_ship_id == -1 && departure_time < 0) {
            cerr << "Invalid trip!" << endl;
            cerr << "Departure time must start at 0!" << endl;
            cerr << "Departure time: " << departure_time << endl;
        }
        if ((previous_ship_id != -1) &&
            (departure_time < (previous_arrival_time + TRANSFER_TIME))) {
            cerr << "Invalid trip!" << endl;
            cerr << "-- Transfer: Departure time is not";
            cerr << "4 or more hours after previous arrival time" << endl;
            cerr << "Departure time: " << departure_time << endl;
            cerr << "Previous Arrival time: " << previous_arrival_time << endl;
        }
    }
}

void Reader::printLeg() {
    cerr << galaxy->fleet.name(ship_id) << "\t"
         << departure_planet->name
         << "\t" << departure_time << "\t" << destination_planet->name
         << "\t" << arrival_time << endl;
}


