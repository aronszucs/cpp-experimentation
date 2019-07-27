#include <iostream>
#include <string>
#include <vector>
#include <map>


#include "person.h"
#include "xml.h"

using namespace std;



XmlNode::XmlNode(string name, map<string, string> *params)
: name_(name), params_(params) {
}

XmlNode::~XmlNode() {
    cout << "asdas" << endl;

    children_.clear();
}

void XmlNode::append(XmlNode *node) {
    children_.push_back(node);
    node->parent_ = this;
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

string XmlNode::getParam(string name) {
    return params_->at(name);
}