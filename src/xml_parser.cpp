#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "xml.h"

using namespace std;


XmlNode* XmlParser::parse() {
    XmlNode *out;
    vector<XmlNode*> nodes;
    vector<XmlNode*> parents;
    parents.push_back(nullptr);
    while (nextTag()) {
        if (currentOpen_) {
            // Add node
            map<string, string> *prm = extractParams();
            XmlNode *n = new XmlNode(currentTagName_, prm);
            prm->

            // Append node to last parent
            XmlNode *p = parents.back();
            if (p != nullptr)
                p->append(n);
            nodes.push_back(n);

            // Add node to parent
            parents.push_back(n);
        } else {
            parents.pop_back();
        }
    }
    return nodes.front();
}

XmlParser::XmlParser(string xml) : xml_(xml) {
    seekerStart_ = -1;
}

bool XmlParser::nextTag() {
    // Start seeker
    seekerStart_ = xml_.find('<', seekerStart_ + 1);
    if (seekerStart_ == -1) {
        return false;
    }
    
    // Full tag
    seekerEnd_ = xml_.find('>', seekerStart_ + 1) + 1;
    currentTag_ = xml_.substr(seekerStart_, seekerEnd_ - seekerStart_);

    // Name
    int nameEnd;
    int whiteSpacePos = currentTag_.find(' ');
    int tagSize = currentTag_.size();
    bool hasParams;
    handleTagName(nameEnd, whiteSpacePos, tagSize, hasParams);

    // Params
    
    if (hasParams) {
        int end = tagSize - whiteSpacePos;
        if (currentTag_[tagSize - 2] == '/') {
            currentParams_ = currentTag_.substr(whiteSpacePos, end - 2);
        } else {
            currentParams_ = currentTag_.substr(whiteSpacePos, end - 1);
        }
    } else {
        currentParams_ = "";
    }
    return true;
}

void XmlParser::handleTagName(int &nameEnd, int whiteSpacePos, int tagSize, bool &hasParams) {
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
}

map<string, string>* XmlParser::extractParams() {
    int size = currentParams_.size();
    int beg = -1;
    string name;
    string value;
    bool nameDone = false;
    char chr;
    map<string, string> *paramMap = new map<string, string>;
    for (int i = 0; i < size; i++) {
        chr = currentParams_[i];
        if (nameDone) {
            if (chr == '"') {
               if (beg == -1) {
                   beg = i + 1;
               } else {
                   value = currentParams_.substr(beg, i - beg);
                    nameDone = false;
                    paramMap->insert({name, value});
                    beg = -1;
               }
            }
        } else {
            if (chr != ' ' && beg == -1) {
                beg = i;
            } else if (chr == '=') {
                name = currentParams_.substr(beg, i - beg);
                nameDone = true;
                beg = -1;
            }
        }
    }
    return paramMap;
}
