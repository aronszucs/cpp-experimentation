#include <iostream>
#include <string>
#include <vector>

#include "xml_parser.h"

using namespace std;



XmlNode::XmlNode(XmlNode *parent, string *xml, int start, int end)
    : parent_(parent), xml_(xml), start_(start), end_(end) {}
