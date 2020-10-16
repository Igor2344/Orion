#include <iostream>
using namespace std;

#include "Distance.h"

Distance::Distance(){
    feet = 0;
    inches = 0;
}

Distance::Distance(unsigned ft, double in){
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in){
    feet = 0;
    inches = in;
    init();
}
unsigned Distance::getFeet() const{
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
    return feet*12 + inches*1.0;
}

double Distance::distanceInFeet() const{
    return feet + inches/12.0;
}

double Distance::distanceInMeters() const{
    return distanceInInches()*0.0254;
}

Distance Distance::operator+(const Distance &rhs) const{
    return Distance(feet + rhs.feet, inches + rhs.inches);
}

Distance Distance::operator-(const Distance &rhs) const{
    return Distance(distanceInInches() - rhs.distanceInInches());
}

ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init(){
    if(inches >= 12){
        feet = feet + inches/12.0;
        inches = inches - static_cast<int>(inches/12)*12.0;
    }
    else if(inches < 0){
        inches = -1.0*inches;
        init();
    }
    else{
        feet = feet;
        inches = inches;
    }
}