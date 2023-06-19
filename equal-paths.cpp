#include "equal-paths.h"
#include <algorithm>
using namespace std;


// You may add any prototypes of helper functions here
// Helper function to calculate the height of a tree
int calculateHeight(Node* node) {
    if (node == nullptr){
        return 0;
    }

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + max(leftHeight, rightHeight);
}

bool equalPaths(Node * root)
{
    if (root == nullptr){
        return true;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    if (leftHeight != rightHeight){
        return false;
    }

    return equalPaths(root->left) && equalPaths(root->right);
}