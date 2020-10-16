#include "Warrior.h"

Warrior::Warrior(const string & name, double health, double attackStrength, string allegiance)
:Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
{
    
}

void Warrior::attack(Character & opp){
    double damage = 0;
    if(opp.getType() == WARRIOR){
        Warrior &oppo = dynamic_cast<Warrior &>(opp);
        if(allegiance == oppo.allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << oppo.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else{
            damage = (health / MAX_HEALTH) * attackStrength;
            oppo.damage(damage);
            cout << "Warrior " << name << " attacks " << oppo.getName() << " --- SLASH!!" << endl;
            cout << oppo.getName() << " takes " << damage << " damage." << endl;
        }
    }
    else{
            damage = (health / MAX_HEALTH) * attackStrength;
            opp.damage(damage);
            cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
            cout << opp.getName() << " takes " << damage << " damage." << endl;
    }
}


