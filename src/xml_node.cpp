#include <iostream>
#include <string>
#include <vector>
#include <map>


#include "person.h"
#include "xml_node.h"

using namespace std;


namespace xml {

    XmlNode::XmlNode(string name, map<string, string> *params)
    : name_(name), params_(params) {}

    XmlNode::~XmlNode() {
        delete params_;
    }

    void XmlNode::append(XmlNode *childNode) {
        children_.push_back(childNode);
        childNode->parent_ = this;
    }

    void XmlNode::print() {
        cout << "# " << name_ << endl;
        cout << "params: " << params_ << endl;
        cout << "parent: " << parent_->name_ << endl;
        cout << "children: ";
        for (int i = 0; i < children_.size(); i++) {
            cout << children_.at(i)->name_ << ", ";
        }
        cout << endl << "---------------------------" << endl;
    }

    string XmlNode::getParamKey(string name) {
        return params_->at(name);
    }

    vector<string> XmlNode::getParamKeys() {
        map<string, string> m;
        vector<string> v;
        map<string,string>::iterator it = params_->begin();
        for(it; it != params_->end(); ++it) {
            v.push_back(it->first);
        }
        return v;
    }

    XmlNode* XmlNode::getRoot() {
        XmlNode *p = parent_;
        if (parent_ == nullptr) {
            return this;
        }
        while (p->getParent() != nullptr) {
            p = p->getParent();
        }
        return p;
    }

    void XmlNode::DestroyTree() {
        vector<XmlNode*> nodes = fetchAllFromTree();
        for (int i = nodes.size() - 1; i >= 0; i--) {
            delete nodes.at(i);
        }
    }

    void XmlNode::recursiveTreeFetch(XmlNode *node, vector<XmlNode*> &nodes) {
        vector<XmlNode*> children = node->getChildren();
        for (int i = 0; i < children.size(); i++) {
            XmlNode *n = children.at(i);
            nodes.push_back(n);
            recursiveTreeFetch(n, nodes);
        }
    }

    vector<XmlNode*> XmlNode::fetchAllFromTree() {
        XmlNode *r = getRoot();
        vector<XmlNode*> nodes;
        nodes.push_back(r);
        recursiveTreeFetch(r, nodes);
        return nodes;
    }
}
