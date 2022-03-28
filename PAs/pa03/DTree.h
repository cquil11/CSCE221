#pragma once

#include <sstream>
#include "DNode.h"
#include "MaxHeap.h"
#include "Queue.h"

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
    /**
     * @brief Iterates through the attributes vector and
     *   calls the provided getInformationGain() for each attribute
     *
     * @param attributes
     * @param data
     * @param outcomes
     * @param instances
     * @return Decision the decision acquired from scanning the attributes and data
     */
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
    /**
     * @brief Helper function for the train function. Recursively populates the
     * left and right children of the root all the way "down" the MaxHeap
     *
     * @param currentDepth
     * @param parent
     * @param attributes
     * @param data
     * @param outcomes
     */
    void populate(int currentDepth, DNode *parent, vector<string> &attributes,
                  vector<vector<double>> &data, vector<int> &outcomes)
    {
        // Note: This function was created following the guidelines laid out in the
        // PA assignment desription
        // The base case is if the current depth has reached the max depth (greater than or equal to is simply a failsafe),
        // then the function terminates and recalls up the call stack
        if (currentDepth >= maxDepth)
        {
            return;
        }
        // Otherwise, a new left and right node is added with the appropriate information gains. THAT new node is only
        // populated with children if and only if the max information gain is above the threshold. Otherwise, the funtion
        // terminates and recalls up the call stack
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
    /**
     * @brief Takes the set of attributes, all data, and the
     *   list of outcomes and instances so that it can build the
     *   decision tree
     *
     * @param attributes
     * @param data
     * @param outcomes
     * @param instances
     */
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

    /**
     * @brief Given a single instance, which is a list of attributes and
     *   their corresponding data points in parallel vectors, your
     *   goal is to return the decision tree’s guess for the likely class
     *   or outcome
     *
     * @param attributes
     * @param data
     * @return int the binary outcomes of the decision
     */
    int classify(
        vector<string> &attributes,
        vector<double> &data)
    {
        DNode *cur = root;

        // Parses through the decision tree, going either left or right at each
        // level (depending on the value of the current node's data compared against its threshold), until the lowest
        // level of the tree has been reached. Then, the function returns that node's
        while (cur->right != nullptr && cur->left != nullptr)
        {
            int index = 0;
            while (index < attributes.size() && cur->key.attribute != attributes.at(index))
                index++;
            if (data.at(index) <= cur->key.threshold)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }

        return cur->key.majorityBelow;
    }
    /**
     * @brief Print the tree in order of level, separated by a tab on each level
     *
     * @return string
     */
    string levelOrderTraversal()
    {
        Queue<DNode *> q;
        stringstream ss;

        q.push_back(root);

        while (!q.empty())
        {
            DNode *u = q.pop_front();
            ss << string(u->depth, '\t') << u->key;

            if (u->left)
                q.push_back(u->left);
            if (u->right)
                q.push_back(u->right);
        }

        return ss.str();
    }
};