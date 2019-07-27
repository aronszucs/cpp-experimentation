#include <iostream>

#include "file_reader.h"
#include "xml.h"
#include "person.h"

using namespace std;




int main() {
    FileReader rdr("meta.xml");
    string xml = rdr.read();

    XmlParser parser(xml);
    XmlNode *root = parser.parse();

    XmlNode *n = root->getChildAt(0);

    cout << n->getParam("lvlnum");
    
    

    return 0;
}