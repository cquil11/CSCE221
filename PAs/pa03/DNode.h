#pragma once

#include "DecisionLogic.h"

class DNode
{
public:
    Decision key;
    int depth;
    DNode *parent;
    DNode *left;
    DNode *right;
    DNode() {}
    // Note: Could have created more constructors for different instances. Instead, I just 
    // called the constructor with nullptr for the irrelevant variables
    DNode(Decision key, int depth, DNode *parent, DNode *left, DNode *right)
        : key(key), depth(depth), parent(parent), left(left), right(right) {}
};