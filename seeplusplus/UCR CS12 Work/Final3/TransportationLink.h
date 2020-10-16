#include <string>

using namespace std;

#ifndef __TRANSPORTATIONLINK_H__
#define __TRANSPORTATIONLINK_H__

const int HOURS_PER_DAY = 24;
const int MINS_PER_HOUR = 60;
const int MINS_PER_DAY = MINS_PER_HOUR * HOURS_PER_DAY; //24 * 60

class TransportationLink {
 protected:
    string _name;
    double _distance;

 public:
    TransportationLink(const string &, double);
    const string & getName() const;
    double getDistance() const;
    void setDistance(double);

    // Passes in the departure time (as minute) and returns arrival time (as minute)
    // For example: 
    //     8 am will be passed in as 480 (8 * 60)
    //     2:30 pm will be passed in as 870 (14.5 * 60) 
    virtual unsigned computeArrivalTime(unsigned minute) const = 0;
};

#endif