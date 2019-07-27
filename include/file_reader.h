#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <iostream>
#include <string>

using namespace std;


class FileReader {
    private:
        string filepath_;

    public:
        FileReader(string filepath) : filepath_(filepath) {}
        string read();
};

#endif