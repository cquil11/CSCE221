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
    DNode(Decision key, int depth, DNode *parent, DNode *left, DNode *right)
        : key(key), depth(depth), parent(parent), left(left), right(right) {}
};