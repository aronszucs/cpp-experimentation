#include <iostream>
#include <string>
#ifndef _XML_DESERIALIZER_H
#define _XML_DESERIALIZER_H

using namespace std;


class XmlNode {
    private:
        int start_;
        int end_;
        XmlNode *parent_;
        string *xml_;

    public:
        XmlNode(XmlNode *parent, string *xml, int start, int end);
        XmlNode() {}
        string getInnerStr();
        XmlNode* getParent() {return parent_;}

};


class XmlParser {
    private:
        string xml_;
        string currentTag_ ;
        string currentTagInner_ ;
        string currentTagName_;
        string currentParams_;
        bool currentOpen_;
        int seekerStart_; 
        int seekerEnd_;

        bool nextTag();
        string getCurrent();
        string getCurrentInner();
        void handleTagName(int &nameEnd, int &whiteSpacePos, int &tagSize, bool &hasParams);

    public:
        XmlParser(string xml);
        XmlNode* parse();
    
};


#endif