#include <iostream>
#include <string>
#include <vector>
#include <map>
#ifndef _XML_H
#define _XML_H

using namespace std;


class XmlNode {
    private:
        string name_;
        map<string, string> *params_;
        XmlNode *parent_ = nullptr;
        vector<XmlNode*> children_;

        void recursiveTreeFetch(XmlNode *node, vector<XmlNode*> &nodes);

    public:
        XmlNode(string name, map<string, string> *params);
        XmlNode() {}
        ~XmlNode();
        string getInnerStr();
        XmlNode* getParent() {return parent_;}
        vector<XmlNode*> getChildren() {return children_;}
        XmlNode* getChildAt(int id) {return children_.at(id);}
        string getName() {return name_;}
        void append(XmlNode *node);
        string getParam(string name);
        vector<string> getParamKeys();
        XmlNode* getRoot();
        void DestroyTree();
        void print();
        vector<XmlNode*> fetchAllFromTree();
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
        map<string, string>* extractParams();
        
    public:
        XmlParser(string xml);
        XmlNode* parse();
    
};


#endif