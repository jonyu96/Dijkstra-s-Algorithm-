# Dijkstra's Algorithm 

This was a final class project from Professor's Morris Bernstein's CSS 343. The objective of this project was to define a working route structure of each planet in the Star Wars Galaxy using the given travel times (shown in the image below)
and use Dijkstra's Algorithm to find the longest shortest-path from one planet to another. Some given limitations were: 

* Ten ships must be utillized to offer passage between all planets
* All ten ships start at Time-0 and times are in 1-hr increments with an imperial day as 24 hrs 
* At every stop, there is a minimum layover of 4 hours 
* When a passenger transfers ships, the minimum 4 hours layover still applies 

<img width="600" height="600" src="https://github.com/jonyu96/Dijkstra-s-Algorithm-/blob/master/journey-times.jpg">

The route structure must utilize all 10 ships and make it possible to travel between all pairs of planets. 

Overview of the program: 

1. Text file (conduits.txt) is created to represent the travel times of the Star Wars Galaxy
2. Text file containing a made-up route structure represents the set route structure of the galaxy 
3. The program, Reader.h, reads these files in to create a Galaxy object, which contains the logisitics and structure of the route structure
4. The program, Galaxy.h, searches for the longest shortest-path a passenger can take for each planet and output two files: 

   * information of the Galaxy: structure, route schedule, route structure, list of itineraries (arrival time, total enroute time, and time in space)
   * longest shortest-path itineraries for each planet in the same standard file format 
   
Using the route struture (routes.txt), this is the LONGEST of the longest-shortest-paths of the 27 planets: 

* Itinerary 27

   [Serenity]	Mon Calamari	26 -->	Bakura	48
   
   [Red Dwarf]	Bakura	58 -->	Kessel	85
   
   [Red Dwarf]	Kessel	89 --> Hapes Cluster	101
   
   [Red Dwarf]	Hapes Cluster	105	--> Corporate Sector	112
   
   [USS Enterprise]	Corporate Sector	--> 151	Coruscant	166
   
   [USS Enterprise]	Coruscant	240	--> Corellia	244
   
   [Heart of Gold]	Corellia	375	--> Yaga Minor	387
   
   [Moya]	Yaga Minor	--> 472	Wayland	502
   
   [Moya]	Wayland	506	--> Myrkr	527
   
   Arrival Time: 527
   Total Enroute Time: 501
   Time in Space: 150

## Installing 

1. Download the project source code files. 
2. Create a route structure using the same file format as the given "routes.txt"
   * Feel free to modify the Generate_Routes.cc program to help you create your route structure txt file. 
3. Run the BUILD.sh script on terminal. 
4. Run the RUN.sh script on terminal. 
5. View all of the longest shortest-path from each planet to a planet on the galaxylog.txt file. 
   * Find the LONGEST longest shortest-path from that file based on the 'arrival time' and 'total enroute time' 

## Contribution 

This was the final class project for CSS 343 (Data Structures & Algorithms II) by Professor Morris Bernstein.
Feel free to check out the [Project Specs](http://courses.washington.edu/css343/bernstein/2018-q2/assignment-03.html)
