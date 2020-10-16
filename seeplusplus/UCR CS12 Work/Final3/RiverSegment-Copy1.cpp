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
    if(scheduledDepartureTimes.size() == 0){ // if its the first scheduled time
        scheduledDepartureTimes.push_back(hour);
        return;
    }
    else{
        for(unsigned i = 0; i < scheduledDepartureTimes.size(); i++){
            if(hour > scheduledDepartureTimes.at(i)){
                scheduledDepartureTimes.insert(scheduledDepartureTimes.begin() + i + 1, hour);
                return;
            }
        }
        scheduledDepartureTimes.insert(scheduledDepartureTimes.begin(), hour); //pushes departure time to front since its the earlier time
        return;
    }
}

unsigned RiverSegment::computeArrivalTime(unsigned minute) const{
    double timeseg;
    for(unsigned i = 0; i < scheduledDepartureTimes.size(); i++){
        if(scheduledDepartureTimes.at(i)*60 > minute){
            timeseg = _distance/_speed; // in hours 
            return (scheduledDepartureTimes.at(i) * 60) + (timeseg * 60); //must be in minutes!!!
        }
    }
    return scheduledDepartureTimes.at(0) * 60 + ((_distance/_speed) * 60); // IN MINUTES
}