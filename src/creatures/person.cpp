#include <iostream>
#include <string>
#include "person.h"
#include "limb.h"

using namespace std;


Person::Person(string name) : name_(name) {
    health_ = 100;
    limbs_ = new Limb[4];
}

Person::~Person() {
    delete [] limbs_;
}

string Person::getName() {
    return name_;
}

void Person::setName(string name) {
    name_ = name;
}

int Person::getNumberOfArms() {
    throw new std::exception();
}

int Person::getNumberOfLegs() {
    throw new std::exception();
}

void Person::induceAnxiety() {
    cout << "Ouch" << endl;
}

void Person::defineMeaningOfPersonhood() {
    cout << "To be a person is to have coffee without needing to." << endl;
}

void Person::addLimb(Limb limb) {
    if (limbNum_ < limbCeiling_) {
        limbs_[limbNum_] = limb;
        limbNum_++;
    } else {
        expandLimbMemory();
        limbs_[limbNum_] = limb;
        limbNum_++;
    }
}

void Person::expandLimbMemory() {
    int newSize = limbCeiling_ + limbCeilingIncrement_;
    Limb tmp[newSize];
    int i;
    for (i = 0; i < limbCeiling_; i++) {
        tmp[i] = limbs_[i];
    }
    delete [] limbs_;
    limbs_ = new Limb[newSize];
    for (i = 0; i < limbCeiling_; i++) {
        limbs_[i] = tmp[i];
    }
    limbCeiling_ = newSize;
}

void Person::printLimbs() {
    for (int i = 0; i < limbNum_; i++) {
        cout << limbs_[i].getName() << endl;
    }
}
