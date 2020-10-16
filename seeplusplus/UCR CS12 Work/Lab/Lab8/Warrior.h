#include <string>
#include <iostream>
using namespace std;

#include "Character.h"

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior: public Character{
    private:
    string allegiance;
    
    public:
    Warrior(const string &, double, double, string);
 	void attack(Character &) override;
    
};

#endif