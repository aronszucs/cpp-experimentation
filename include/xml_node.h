#include <iostream>
#include <string>
#include <vector>
#include <map>
#ifndef _XML_NODE_H
#define _XML_NODE_H

using namespace std;

namespace xml {

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

            // Get inner xml string belonging to this node
            string getInnerStr();

            // Get the parent of this node. Returns nullptr if node is root
            XmlNode* getParent() {return parent_;}

            // Get a vector containing all the children
            vector<XmlNode*> getChildren() {return children_;}

            // Get child node at the given index
            XmlNode* getChildAt(int id) {return children_.at(id);}

            string getName() {return name_;}

            // Append a new node as a child of this node
            void append(XmlNode *childNode);

            // Returns param value by key
            string getParamKey(string key);

            // Returns xml parameter keys
            vector<string> getParamKeys();

            // Returns the root node of this node's tree
            XmlNode* getRoot();
            
            // Frees memory occupied by all nodes belonging to this tree
            void DestroyTree();

            // Prints node data to the screen
            void print();

            // Returns all the related nodes belonging to this node's tree
            vector<XmlNode*> fetchAllFromTree();
    };

}

#endif