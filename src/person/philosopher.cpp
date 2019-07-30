#include <iostream>
#include <string>
#include "philosopher.h"

using namespace std;


Philosopher::Philosopher(string name, string philosophy) :
    Person(name), philosophy_(philosophy) {}

void Philosopher::sayOneLiner() {
    cout << philosophy_ << endl;
}
