#include "Node.hpp"

// I took this part from GeeksforGeeks, but I promise I
// still understand the process, this solution is just elegant
int max(int a, int b)
{
    return (a >= b) ? a : b;
}

template <typename T>
int getHeight(Node<T>* node)
{
    if (node == nullptr)
        return 0;
 
    return 1 + max(getHeight(node->left_),
                   getHeight(node->right_));
}

template <typename T>
bool isBalanced(const Node<T> *node)
{

    bool isLeftBalanced, isRightBalanced;
    int leftHeight, rightHeight;

    if (node == nullptr)
    {
        return true;
    }

    leftHeight = getHeight(node->left_);
    rightHeight = getHeight(node->right_);

    isLeftBalanced = isBalanced(node->left_);
    isRightBalanced = isBalanced(node->right_);

    if (std::abs(rightHeight - leftHeight) > 1)
    {
        return false;
    }
    else
    {
        return isLeftBalanced && isRightBalanced;
    }


}

int main()
{


    return 0;
}