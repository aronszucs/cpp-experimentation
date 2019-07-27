#include <iostream>
#include <string>
#include <vector>

#include "file_reader.h"
#include "xml_parser.h"

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
    FileReader rdr("meta.xml");
    string xml = rdr.read();

    XmlParser parser(xml);
    XmlNode *root = parser.parse();

    return 0;
}