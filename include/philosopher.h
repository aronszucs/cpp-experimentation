#ifndef _PHILOSOPHER_GUARD
#define _PHILOSOPHER_GUARD

#include <iostream>
#include "person.h"
#include "i_speaker.h"

using namespace std;


/**
 * Philosopher, an intriguing subset of Person. Due to overwhelming thougts needed
 * to be cathartically discarded, Philosopher implements ISpeaker as an interface
 * to say one liners
 */
class Philosopher : public Person, public ISpeaker {
private:
    string philosophy_;

public:
    Philosopher(string name, string philosophy);

    // Says philosophical one liner.
    void sayOneLiner();
};


#endif