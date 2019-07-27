#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include "limb.h"

using namespace std;


class Person {
    private:
        string name_;
        int worryingSkill_;
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
        void induceAnxiety();
        string getName();
        void setName(string);
        int getNumberOfArms();
        int getNumberOfLegs();
        static void defineMeaningOfPersonhood();
        void addLimb(Limb);
        void printLimbs();
        virtual void sayOneLiner() {}
};


#endif