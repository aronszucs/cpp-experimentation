#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "xml_node.h"

#ifndef _XML_PARSER_H
#define _XML_PARSER_H

using namespace std;

namespace xml {


/**
 * Xml parser, capable of deserializing xml strings and converting them to xml nodes. 
 */
class XmlParser {
private:
    string xml_;

    string currentTag_ ;

    string currentTagName_;

    string currentParams_;

    bool currentOpen_;

    int seekerStart_; 

    int seekerEnd_;

    bool nextTag();

    void handleTagName(int &nameEnd, int whiteSpacePos, int tagSize, bool &hasParams);

    map<string, string>* extractParams();
        

public:
    XmlParser(string xml);
    
    // Returns a pointer to the root node of the xml.
    XmlNode* parse();
    
};

}

#endif