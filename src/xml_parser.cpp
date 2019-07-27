#include <iostream>
#include <string>
#include <vector>

#include "xml_parser.h"

using namespace std;


XmlNode* XmlParser::parse() {
    XmlNode *out;
    vector<XmlNode> nodes(10);


    while (nextTag()) {
        cout << currentParams_ << endl;
    }
    
    return out;
}

XmlParser::XmlParser(string xml) : xml_(xml) {
    seekerStart_ = -1;
}

bool XmlParser::nextTag() {
    // Start seeker
    seekerStart_ = xml_.find('<', seekerStart_ + 1);
    if (seekerStart_ == -1)
        return false;
    
    // Full tag
    seekerEnd_ = xml_.find('>', seekerStart_ + 1) + 1;
    currentTag_ = xml_.substr(seekerStart_, seekerEnd_ - seekerStart_);

    // Name
    int nameEnd;
    int whiteSpacePos = currentTag_.find(' ');
    int tagSize = currentTag_.size();
    bool hasParams;
    if (whiteSpacePos != -1) {
        nameEnd = whiteSpacePos;
        hasParams = true;
    } else {
        nameEnd = tagSize -2;
        hasParams = false;
    }

    if (currentTag_[1] == '/') {
        currentTagName_ = currentTag_.substr(2, nameEnd - 1);
        currentOpen_ = false;
        
    } else {
        currentTagName_ = currentTag_.substr(1, nameEnd);
        currentOpen_ = true;
    }

    // Params
    
    if (hasParams) {
        int end = tagSize - whiteSpacePos;
        if (currentTag_[tagSize - 2] == '/') {
            currentParams_ = currentTag_.substr(whiteSpacePos, end - 2);
        } else {
            currentParams_ = currentTag_.substr(whiteSpacePos, end - 1);
        }
    }
    return true;
}

void XmlParser::handleTagName(int &nameEnd, int &whiteSpacePos, int &tagSize, bool &hasParams) {

}



string XmlParser::getCurrentInner() {
    
}