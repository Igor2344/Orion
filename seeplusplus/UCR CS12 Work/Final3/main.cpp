#include "RoadSegment.h"
#include "RiverSegment.h"

#include <iostream>

using namespace std;

void constructRoute(vector<TransportationLink *> &);
int routeArrivalTime(const vector<TransportationLink *> &, unsigned);
void addRoad(vector<TransportationLink *> &);
void addRiver(vector<TransportationLink *> &);

int main() {

   vector<TransportationLink *> route1;
   constructRoute(route1);
   
   unsigned departureTime;
   unsigned arrivalTime;
   
   cout << "Enter route departure time (in minutes): ";
   cin >> departureTime;
   cout << endl;
   
   arrivalTime = routeArrivalTime(route1, departureTime);
   
   cout << "Arrival Time: " << arrivalTime << endl;
    
   return 0;
}



void constructRoute(vector<TransportationLink *> &route) {
   char option = 'q';
   
   do {
      cout << endl;
      cout << "Menu" << endl;
      cout << "- Add Road ('D' or 'd')" << endl;
      cout << "- Add River ('R' or 'r')" << endl;
      cout << "- Quit ('Q' or 'q')" << endl;
      cout << "Choose an action: ";
      cin >> option;
      cout << endl;
      cin.ignore(); // get rid of whitespace character
      
      if (option == 'd' || option == 'D') {
      	addRoad(route);
      } 
      else if (option == 'r' || option == 'R') {
      	addRiver(route);
      }
   } while (option != 'q' && option != 'Q');
}

int routeArrivalTime(const vector<TransportationLink *> &route, unsigned departureTime) {
   unsigned arrivalTime = departureTime;
   for (unsigned i = 0; i < route.size(); ++i) {
      arrivalTime = route.at(i)->computeArrivalTime(arrivalTime);
   }
   return arrivalTime;
}

void addRoad(vector<TransportationLink *> &route) {
   string name;
   double speed;
   double distance;
   char answer = 'n';
   unsigned hour;
   
   cout << "Enter name of road: ";
   getline(cin, name);
   cout << endl;
   cout << "Enter road's default speed: ";
   cin >> speed;
   cout << endl;
   cout << "Enter road's distance: ";
   cin >> distance;
   cout << endl;
   RoadSegment *road = new RoadSegment(name, speed, distance);
   
   cout << "Enter non-default speeds by hour (if any):" << endl;
   cout << "Enter new speed? (y or n): ";
   cin >> answer;
   cout << endl;
   while (answer != 'n' && answer != 'N') {
      cout << "Which hour? (0 to 23): ";
      cin >> hour;
      cout << endl;
      if (hour > 23) {
         cout << "Invalid hour. Speed not updated." << endl;
      } else {
         cout << "Enter speed for hour " << hour << ": ";
         cin >> speed;
         cout << endl;
         road->setHourSpeed(hour, speed);
      }
      cout << "Enter new speed? (y or n): ";
      cin >> answer;
      cout << endl;
   }
   route.push_back(road);
}

void addRiver(vector<TransportationLink *> &route) {
   string name;
   double speed;
   double distance;
   char answer = 'n';
   double hour;
   
   cout << "Enter name of river: ";
   getline(cin, name);
   cout << endl;
   cout << "Enter river's speed: ";
   cin >> speed;
   cout << endl;
   cout << "Enter river's distance: ";
   cin >> distance;
   cout << endl;
   RiverSegment *river = new RiverSegment(name, speed, distance);

   cout << "Enter departure times:" << endl;

   do {
      cout << "Enter time as an hour: (0 to 23.99): ";
      cin >> hour;
      cout << endl;
      if (hour >= 24) {
         cout << "Invalid hour. Departure time not added." << endl;
      } else {
         river->addDepartureTime(hour);
      }
      cout << "Enter new departure time? (y or n): ";
      cin >> answer;
      cout << endl;
   } while (answer != 'n' && answer != 'N');
   
   route.push_back(river);
}
