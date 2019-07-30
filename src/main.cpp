#include <iostream>
#include <vector>

#include "file_reader.h"

#include "person.h"
#include "philosopher.h"

#include "xml_node.h"
#include "xml_parser.h"
#include "i_speaker.h"

using namespace std;
using namespace xml;


void personSandBox();
void xmlSandBox();


template <class T>
T* sum (T a, T b) {
    T* arr = new T[2];
    arr[0] = a;
    arr[1] = b;
    return arr;
}

void personSandBox() {
    ISpeaker *sp = new Philosopher("Ailurocrates", "Cats are nice");
    sp->sayOneLiner();
}

void xmlSandBox() {
    FileReader rdr("meta.xml");
    string xml = rdr.read();

    // Loop used to test performance and memory leaks.
    // Inrease iterations (and check memory consumption) to see results.
    for (int i = 0; i < 1; i++) {
            XmlParser parser(xml);
            XmlNode *root = parser.parse();
            XmlNode *n = root->getChildAt(0)->getChildAt(0);
            vector<XmlNode*> tree = root->fetchAllFromTree();
            
            root->DestroyTree();
            cout << endl;
        }
}

int main() {
    xmlSandBox();
    personSandBox();

    return 0;
}