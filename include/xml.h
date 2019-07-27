#include <iostream>
#include <string>
#include <vector>
#ifndef _XML_H
#define _XML_H

using namespace std;


class XmlNode {
    private:
        string name_;
        string params_;
        XmlNode *parent_ = nullptr;
        vector<XmlNode*> children_;
        string *xml_;

    public:
        XmlNode(string name, string params);
        XmlNode() {}
        ~XmlNode();
        string getInnerStr();
        XmlNode* getParent() {return parent_;}
        string getName() {return name_;}
        string getParams() {return params_;}
        void append(XmlNode *node);
        void print();
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
        void handleTagName(int &nameEnd, int whiteSpacePos, int tagSize, bool &hasParams);

    public:
        XmlParser(string xml);
        XmlNode* parse();
    
};


#endif