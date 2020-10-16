#include "TransportationLink.h"

#include <string>

using namespace std;

TransportationLink::TransportationLink(const string &name, double distance)
 : _name(name), _distance(distance)
{}

const string & TransportationLink::getName() const {
    return _name;
}

double TransportationLink::getDistance() const {
   return _distance;
}

void TransportationLink::setDistance(double distance) {
   _distance = distance;
}
