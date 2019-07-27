#ifndef _PHILOSOPHER_GUARD
#define _PHILOSOPHER_GUARD

#include <iostream>
#include "person.h"

using namespace std;


class Philosopher : public Person {
    private:
        string philosophy_;

    public:
        Philosopher(string, string);
        void sayOneLiner();

};


#endif