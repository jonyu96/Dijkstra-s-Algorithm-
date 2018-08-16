//
//  Generate_Routes.cc
//  Assignment3
//
//  Created by Jonathan Yu on 6/8/18.
//  Copyright © 2018 Jonathan Yu. All rights reserved.
//
//  Simple program that generates routes/schedule for
//  Assignment 3.

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    
    if (argc < 2) {
        cerr << "Output text file is required!" << endl;
        return EXIT_FAILURE;
    }
    
    ofstream out;
    out.open(argv[1]);
    
    out << "#World 1: WELL-KNOWN WORLDS" << endl;
    out << "#World 2: PERLEMIAN TRADE ROUTE" << endl;
    out << "#World 3: FROM THE CORE TO THE OUTER RIM AND BEYOND" << endl;
    out << "#World 4: OTHER WORLDS AND REGIONS OF INTEREST" << endl;
    
    int time = 0;
    out << "#World 1 -- Ship #1" << endl;
    for (int i = 0; i < 5; i++) {
        out << "Andromeda Ascendant" << "\t";
        out << "Sullust" << "\t" << time << "\t";
        time += 22;
        out << "Hoth" << "\t" << time << endl;
        time += 4;
        
        out << "Andromeda Ascendant" << "\t";
        out << "Hoth" << "\t" << time << "\t";
        time += 60;
        out << "Endor" << "\t" << time << endl;
        time += 4;
        
        out << "Andromeda Ascendant" << "\t";
        out << "Endor" << "\t" << time << "\t";
        time += 32;
        out << "Bespin" << "\t" << time << endl;
        time += 4;
        
        out << "Andromeda Ascendant" << "\t";
        out << "Bespin" << "\t" << time << "\t";
        time += 32;
        out << "Endor" << "\t" << time << endl;
        time += 4;
        
        out << "Andromeda Ascendant" << "\t";
        out << "Endor" << "\t" << time << "\t";
        time += 60;
        out << "Hoth" << "\t" << time << endl;
        time += 4;
        
        out << "Andromeda Ascendant" << "\t";
        out << "Hoth" << "\t" << time << "\t";
        time += 22;
        out << "Sullust" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 1 -- Ship #2" << endl;
    for (int i = 0; i < 10; i++) {
        out << "USSC Discovery One" << "\t";
        out << "Tatooine" << "\t" << time << "\t";
        time += 40;
        out << "Gamorr" << "\t" << time << endl;
        time += 4;
        
        out << "USSC Discovery One" << "\t";
        out << "Gamorr" << "\t" << time << "\t";
        time += 40;
        out << "Tatooine" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 1 -- Ship #3" << endl;
    for (int i = 0; i < 5; i++) {
        out << "Galactica" << "\t";
        out << "Yavin" << "\t" << time << "\t";
        time += 5;
        out << "Alderaan" << "\t" << time << endl;
        time += 4;
        
        out << "Galactica" << "\t";
        out << "Alderaan" << "\t" << time << "\t";
        time += 13;
        out << "Dantooine" << "\t" << time << endl;
        time += 4;
        
        out << "Galactica" << "\t";
        out << "Dantooine" << "\t" << time << "\t";
        time += 32;
        out << "Dagobah" << "\t" << time << endl;
        time += 4;
        
        out << "Galactica" << "\t";
        out << "Dagobah" << "\t" << time << "\t";
        time += 32;
        out << "Dantooine" << "\t" << time << endl;
        time += 4;
        
        out << "Galactica" << "\t";
        out << "Dantooine" << "\t" << time << "\t";
        time += 13;
        out << "Alderaan" << "\t" << time << endl;
        time += 4;
        
        out << "Galactica" << "\t";
        out << "Alderaan" << "\t" << time << "\t";
        time += 5;
        out << "Yavin" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 1 to World 3 -- Ship #4" << endl;
    for (int i = 0; i < 5; i++) {
        out << "Heart of Gold" << "\t";
        out << "Corellia" << "\t" << time << "\t";
        time += 6;
        out << "Alderaan" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Alderaan" << "\t" << time << "\t";
        time += 7;
        out << "Tatooine" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Tatooine" << "\t" << time << "\t";
        time += 16;
        out << "Bespin" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Bespin" << "\t" << time << "\t";
        time += 6;
        out << "Corellia" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Corellia" << "\t" << time << "\t";
        time += 12;
        out << "Yaga Minor" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Yaga Minor" << "\t" << time << "\t";
        time += 12;
        out << "Corellia" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Corellia" << "\t" << time << "\t";
        time += 6;
        out << "Alderaan" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Alderaan" << "\t" << time << "\t";
        time += 8;
        out << "Bespin" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Bespin" << "\t" << time << "\t";
        time += 32;
        out << "Endor" << "\t" << time << endl;
        time += 4;
        
        out << "Heart of Gold" << "\t";
        out << "Endor" << "\t" << time << "\t";
        time += 17;
        out << "Corellia" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 3 -- Ship #5" << endl;
    for (int i = 0; i < 7; i++) {
        out << "Millenium Falcon" << "\t";
        out << "Yaga Minor" << "\t" << time << "\t";
        time += 53;
        out << "Kashyyyk" << "\t" << time << endl;
        time += 4;
        
        out << "Millenium Falcon" << "\t";
        out << "Kashyyyk" << "\t" << time << "\t";
        time += 53;
        out << "Yaga Minor" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 3 -- Ship #6" << endl;
    for (int i = 0; i < 7; i++) {
        out << "Moya" << "\t";
        out << "Yaga Minor" << "\t" << time << "\t";
        time += 30;
        out << "Wayland" << "\t" << time << endl;
        time += 4;
        
        out << "Moya" << "\t";
        out << "Wayland" << "\t" << time << "\t";
        time += 21;
        out << "Myrkr" << "\t" << time << endl;
        time += 4;
        
        out << "Moya" << "\t";
        out << "Myrkr" << "\t" << time << "\t";
        time += 21;
        out << "Wayland" << "\t" << time << endl;
        time += 4;
        
        out << "Moya" << "\t";
        out << "Wayland" << "\t" << time << "\t";
        time += 30;
        out << "Yaga Minor" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 2 -- Ship #7" << endl;
    for (int i = 0; i < 10; i++) {
        out << "NSEA Protector" << "\t";
        out << "Ralltiir" << "\t" << time << "\t";
        time += 4;
        out << "Chandrila" << "\t" << time << endl;
        time += 4;
        
        out << "NSEA Protector" << "\t";
        out << "Chandrila" << "\t" << time << "\t";
        time += 3;
        out << "Esseles" << "\t" << time << endl;
        time += 4;
        
        out << "NSEA Protector" << "\t";
        out << "Esseles" << "\t" << time << "\t";
        time += 4;
        out << "Corulag" << "\t" << time << endl;
        time += 4;
        
        out << "NSEA Protector" << "\t";
        out << "Corulag" << "\t" << time << "\t";
        time += 2;
        out << "Brentaal" << "\t" << time << endl;
        time += 4;
        
        out << "NSEA Protector" << "\t";
        out << "Brentaal" << "\t" << time << "\t";
        time += 5;
        out << "Rhinnal" << "\t" << time << endl;
        time += 4;
        
        out << "NSEA Protector" << "\t";
        out << "Rhinnal" << "\t" << time << "\t";
        time += 1;
        out << "Ralltiir" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 4 -- Ship #8" << endl;
    for (int i = 0; i < 10; i++) {
        out << "Red Dwarf" << "\t";
        out << "Corporate Sector" << "\t" << time << "\t";
        time += 7;
        out << "Hapes Cluster" << "\t" << time << endl;
        time += 4;
        
        out << "Red Dwarf" << "\t";
        out << "Hapes Cluster" << "\t" << time << "\t";
        time += 12;
        out << "Kessel" << "\t" << time << endl;
        time += 4;
        
        out << "Red Dwarf" << "\t";
        out << "Kessel" << "\t" << time << "\t";
        time += 27;
        out << "Bakura" << "\t" << time << endl;
        time += 4;
        
        out << "Red Dwarf" << "\t";
        out << "Bakura" << "\t" << time << "\t";
        time += 27;
        out << "Kessel" << "\t" << time << endl;
        time += 4;
        
        out << "Red Dwarf" << "\t";
        out << "Kessel" << "\t" << time << "\t";
        time += 12;
        out << "Hapes Cluster" << "\t" << time << endl;
        time += 4;
        
        out << "Red Dwarf" << "\t";
        out << "Hapes Cluster" << "\t" << time << "\t";
        time += 7;
        out << "Corporate Sector" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 4 -- Ship #9" << endl;
    for (int i = 0; i < 10; i++) {
        out << "Serenity" << "\t";
        out << "Bakura" << "\t" << time << "\t";
        time += 22;
        out << "Mon Calamari" << "\t" << time << endl;
        time += 4;
        
        out << "Serenity" << "\t";
        out << "Mon Calamari" << "\t" << time << "\t";
        time += 22;
        out << "Bakura" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    time = 0;
    out << "#World 2 to World 4 -- Ship #10" << endl;
    for (int i = 0; i < 5; i++) {
        out << "USS Enterprise" << "\t";
        out << "Corellia" << "\t" << time << "\t";
        time += 4;
        out << "Coruscant" << "\t" << time << endl;
        time += 4;
        
        out << "USS Enterprise" << "\t";
        out << "Coruscant" << "\t" << time << "\t";
        time += 15;
        out << "Corporate Sector" << "\t" << time << endl;
        time += 4;
        
        out << "USS Enterprise" << "\t";
        out << "Corporate Sector" << "\t" << time << "\t";
        time += 15;
        out << "Coruscant" << "\t" << time << endl;
        time += 4;
        
        out << "USS Enterprise" << "\t";
        out << "Coruscant" << "\t" << time << "\t";
        time += 12;
        out << "Ralltiir" << "\t" << time << endl;
        time += 4;
        
        out << "USS Enterprise" << "\t";
        out << "Ralltiir" << "\t" << time << "\t";
        time += 12;
        out << "Coruscant" << "\t" << time << endl;
        time += 4;
        
        out << "USS Enterprise" << "\t";
        out << "Coruscant" << "\t" << time << "\t";
        time += 15;
        out << "Corporate Sector" << "\t" << time << endl;
        time += 4;
        
        out << "USS Enterprise" << "\t";
        out << "Corporate Sector" << "\t" << time << "\t";
        time += 15;
        out << "Coruscant" << "\t" << time << endl;
        time += 4;
        
        out << "USS Enterprise" << "\t";
        out << "Coruscant" << "\t" << time << "\t";
        time += 4;
        out << "Corellia" << "\t" << time << endl;
        time += 4;
    }
    out << endl;
    
    out.close();
    return EXIT_SUCCESS;
}


