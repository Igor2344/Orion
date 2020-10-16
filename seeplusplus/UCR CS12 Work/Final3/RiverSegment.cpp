#include "RiverSegment.h"

#include <string>
#include <vector>

using namespace std;

RiverSegment::RiverSegment(const string &name, double speed, double distance)
:TransportationLink(name, distance), _speed(speed){
}

void RiverSegment::setSpeed(double speed){
    _speed = speed;
}

void RiverSegment::addDepartureTime(double hour){
    if(scheduledDepartureTimes.size() == 0){
        scheduledDepartureTimes.push_back(hour);
        return;
    }
    else{
        for(unsigned i = scheduledDepartureTimes.size()-1; i >= 0; i--){
            if(hour > scheduledDepartureTimes.at(i)){
                scheduledDepartureTimes.insert(scheduledDepartureTimes.begin() + i + 1, hour);
                return;
            }
        }
        scheduledDepartureTimes.insert(scheduledDepartureTimes.begin(), hour); // adds to front as its the earliest time out of the whole vector (only happens if the code gets here)
    }
}

unsigned RiverSegment::computeArrivalTime(unsigned minute) const{
    double timeseg;
    for(unsigned i = 0; i < scheduledDepartureTimes.size(); i++){ //for loop of entire deptime vec
        if(scheduledDepartureTimes.at(i)*60 > minute){
            timeseg = _distance/_speed; // in hours 
            return (scheduledDepartureTimes.at(i) * 60) + (timeseg * 60); //must be in minutes!!!
        }
    }
    return scheduledDepartureTimes.at(0) * 60 + ((_distance/_speed) * 60) + 1440; // IN MINUTES
}