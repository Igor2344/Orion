#include "Wizard.h"

Wizard::Wizard(const string & name, double health, double attackStrength, int rank)
:Character(WIZARD, name, health, attackStrength), rank(rank)
{
    
}

void Wizard::attack(Character & opp){
    double damage = 0;
    if(opp.getType() == WIZARD){
        Wizard &oppo = dynamic_cast<Wizard &>(opp);
        damage = attackStrength * (rank/(oppo.rank*1.0));
        oppo.damage(damage);
        cout << "Wizard " << name << " attacks " << oppo.getName() << " --- POOF!!" << endl;
        cout << oppo.getName() << " takes " << damage << " damage." << endl;
    }
    else{
        damage = attackStrength;
        opp.damage(damage);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
    }
}