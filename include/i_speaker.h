#ifndef _ISPEAKER_H
#define _ISPEAKER_H

#include <iostream>
#include <string>

using namespace std;

/**
 * Main interface class for speakers of any kind. Most useful to be implemented by subclasses of Person
 */
class ISpeaker {
public:
    virtual void sayOneLiner() = 0;
    
};

#endif