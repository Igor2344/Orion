#include <string>
#include <iostream>

using namespace std;

#include "Character.h"

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character{
    private:
    string familyName;
    
    public:
    Elf(const string &, double, double, string);
 	void attack(Character &) override;
};

#endif