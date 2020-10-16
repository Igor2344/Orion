#include "TransportationLink.h"

#include <string>
#include <vector>

using namespace std;

#ifndef __ROADSEGMENT_H__
#define __ROADSEGMENT_H__

class RoadSegment: public TransportationLink{
    private:
    vector<double> hourlySpeeds;
    
    public:
    RoadSegment(const string &, double, double);
    void setHourSpeed(unsigned, double);
    void setAllHourSpeeds(const vector<double> &);
    
    unsigned computeArrivalTime(unsigned) const;
};
#endif