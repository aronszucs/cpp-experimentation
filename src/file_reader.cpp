#include <iostream>
#include <string>
#include <fstream>

#include "file_reader.h"

using namespace std;


string FileReader::read() {
    
    ifstream in(filepath_, std::ios::in);
    in.seekg(0, std::ios::end);
    int bufferSize = in.tellg();
    in.seekg(0, std::ios::beg);
    char fileChars[bufferSize];

    in.read(fileChars, bufferSize);
    in.close();
    string str = fileChars;
    return str;
}