#ifndef _LIMB_H
#define _LIMB_H

#include <iostream>
#include <string>

using namespace std;




class Limb{
    private:
        string name;
        string type;

    public:
        Limb();
        Limb(string newName);
        string getName();
        string getType();
        string getHoldable();
};
#endif