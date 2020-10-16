#include "Elf.h"
Elf::Elf(const string & name, double health, double attackStrength, string familyName)
:Character(ELF, name, health, attackStrength), familyName(familyName)
{
    
}

void Elf::attack(Character & opp){
    double damage = 0;
    if(opp.getType() == ELF){
        Elf &oppo = dynamic_cast<Elf &>(opp);
        if(familyName == oppo.familyName){
            cout << "Elf " << name << " does not attack Elf " << oppo.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
        }
        else{
            damage = (health / MAX_HEALTH) * attackStrength;
            oppo.damage(damage);
            cout << "Elf " << name << " shoots an arrow at " << oppo.getName() << " --- TWANG!!" << endl;
            cout << oppo.getName() << " takes " << damage << " damage." << endl;
        }
    }
    else{
        damage = (health / MAX_HEALTH) * attackStrength;
        opp.damage(damage);
        cout << "Elf " << name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
    }
}