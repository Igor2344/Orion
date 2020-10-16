#include "RoadSegment.h"

#include <string>
#include <vector>

using namespace std;

RoadSegment::RoadSegment(const string &name, double speed, double _distance)
:TransportationLink(name, _distance){
    vector<double> speeds(24,speed);
    setAllHourSpeeds(speeds);
}

void RoadSegment::setHourSpeed(unsigned hour, double speed){
    hourlySpeeds.at(hour) = speed;
}

void RoadSegment::setAllHourSpeeds(const vector<double> &hourlyS){
    hourlySpeeds = hourlyS;
}
unsigned RoadSegment::computeArrivalTime(unsigned minute) const{
    unsigned hour = minute / 60;
    double time = _distance / hourlySpeeds.at(hour);
    return minute + (time*60);
}