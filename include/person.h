#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include "limb.h"

using namespace std;



/**
 * Person class, mainly used fot experimentation with the language,
 * OOP concepts and array memory handling
 */
class Person {
private:
    string name_;

    int health_;

    Limb *limbs_;

    int limbNum_ = 0;

    int limbCeilingIncrement_ = 4;

    int limbCeiling_ = limbCeilingIncrement_;

    void expandLimbMemory();


public:
    Person() {}

    Person(string);

    ~Person();

    string getName();

    void setName(string);

    // Prints the meaning of personhood. For its universal nature for all beings,
    // method is intendet as static
    static void defineMeaningOfPersonhood();

    // Add a new limb to the person
    void addLimb(Limb);

    // Print limb info to the screen
    void printLimbs();
};


#endif