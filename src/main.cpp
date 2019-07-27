#include <iostream>
#include <string>
#include <vector>

#include "file_reader.h"
#include "xml.h"
#include "person.h"

using namespace std;


void fuck(int a) {
    a++;
}

class Data {
    public:
        int h = 7;
        int b = 8;
        int c = 9;
};

int main() {
    FileReader rdr("0.tr");
    string xml = rdr.read();

    XmlParser parser(xml);
    XmlNode *root = parser.parse();



    return 0;
}