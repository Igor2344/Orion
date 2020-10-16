#include <string>
#include <iostream>

using namespace std;

#include "Character.h"

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard:public Character{
    private:
    int rank;
    
    public:
    Wizard(const string &, double, double, int);
 	void attack(Character &) override;
};

#endif