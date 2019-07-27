#include <iostream>
#include <vector>

#include "file_reader.h"
#include "xml.h"
#include "person.h"

using namespace std;


int main() {
    FileReader rdr("meta.xml");
    string xml = rdr.read();
    for (int i = 0; i < 999999; i++) {
        XmlParser parser(xml);
        XmlNode *root = parser.parse();
        XmlNode *n = root->getChildAt(0)->getChildAt(0);
        root->DestroyTree();
    }
    

    return 0;
}