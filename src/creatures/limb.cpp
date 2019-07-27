#include <iostream>
#include <string>
#include "limb.h"

using namespace std;

Limb::Limb(string newName) {
    name = newName;
}
Limb::Limb() {
    
}


string Limb::getName() {
    return name;
}

string Limb::getType() {
    return type;
}

string Limb::getHoldable() {
    return "plunger";
}
