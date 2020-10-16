#include "TransportationLink.h"

#include <string>
#include <vector>

using namespace std;

#ifndef __RIVERSEGMENT_H__
#define __RIVERSEGMENT_H__

class RiverSegment: public TransportationLink{
    private:
    vector<double> scheduledDepartureTimes;
    double _speed;
    
    public:
    RiverSegment(const string &, double, double);
    void setSpeed(double);
    void addDepartureTime(double);
    
    unsigned computeArrivalTime(unsigned) const;
};
#endif