#pragma once

#include "DNode.h"
#include "MaxHeap.h"

class DTree
{
public:
    DNode *root = nullptr;
    int maxDepth = 10;
    double delta = 0.000005;

    DTree() {}
    ~DTree()
    {
        delete root;
    }
    Decision getMaxInformationGain(
        vector<string> &attributes,
        vector<vector<double>> &data,
        vector<int> &outcomes,
        vector<int> &instances)
    {
        MaxHeap<Decision> informationGains;
        for (int i = 0; i < attributes.size(); i++)
        {
            informationGains.insert(getInformationGain(attributes.at(i), data.at(i), outcomes, instances));
        }
        return informationGains.removeMax();
    }
    void populate(int currentDepth, DNode *parent, vector<string> &attributes,
                  vector<vector<double>> &data, vector<int> &outcomes)
    {
        if (currentDepth >= maxDepth)
        {
            return;
        }
        parent->left = new DNode(getMaxInformationGain(attributes, data, outcomes, parent->key.instancesBelow),
                                 currentDepth, parent, nullptr, nullptr);
        if (getMaxInformationGain(attributes, data, outcomes, parent->key.instancesBelow).informationGain > delta)
        {
            populate(currentDepth + 1, parent->left, attributes, data, outcomes);
        }
        parent->right = new DNode(getMaxInformationGain(attributes, data, outcomes, parent->key.instancesAbove),
                                  currentDepth, parent, nullptr, nullptr);
        if (getMaxInformationGain(attributes, data, outcomes, parent->key.instancesAbove).informationGain > delta)
        {
            populate(currentDepth + 1, parent->right, attributes, data, outcomes);
        }
        return;
    }
    void train(
        vector<string> &attributes,
        vector<vector<double>> &data,
        vector<int> &outcomes,
        vector<int> &instances)
    {
        int currentDepth = 0;
        root = new DNode(getMaxInformationGain(attributes, data, outcomes, instances), currentDepth, nullptr, nullptr, nullptr);
        currentDepth++;

        populate(currentDepth, root, attributes, data, outcomes);
    }

    int classify(
        vector<string> &attributes,
        vector<double> &data);
    string levelOrderTraversal()
    {
        return 0;
    }
};