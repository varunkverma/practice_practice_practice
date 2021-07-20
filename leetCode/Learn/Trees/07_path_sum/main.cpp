// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children.

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool processTree(TreeNode *node, int currentSum, int targetSum)
{
    // check if a leaf-node
    if (node->left == nullptr && node->right == nullptr)
    {
        // check and return if currentSum is equal to targetSum
        return currentSum == targetSum;
    }

    // declare a bool var to represent resultValue to be returned from this node
    bool nodeResult = false;

    // its not a leaf node, check if it has a left-child node
    if (node->left != nullptr)
    {
        // // check if left->val + currentSum > targetSum, if targetSum > 0
        // if (targetSum > 0 && node->left->val > targetSum)
        // {
        //     // if yes, set nodeResult to false
        //     nodeResult = false;
        // }
        // // check if left->val + currentSum < targetSum, if targetSum < 0
        // else if (targetSum < 0 && node->left->val < targetSum)
        // {
        //     // if yes, set nodeResult to false
        //     nodeResult = false;
        // }
        // else
        // {
        // else, make a recursive call to left node and store its returned value into nodeResult
        nodeResult = processTree(node->left, currentSum + node->left->val, targetSum);
        // }
    }

    // check if nodeResult is false and a right child exists
    if (nodeResult == false && node->right != nullptr)
    {
        // // check if right->val + currentSum > targetSum, if targetSum > 0
        // if (targetSum > 0 && node->right->val > targetSum)
        // {
        //     // if yes, set nodeResult to false
        //     nodeResult = false;
        // }
        // // check if right->val + currentSum < targetSum, if targetSum < 0
        // else if (targetSum < 0 && node->right->val < targetSum)
        // {
        //     // if yes, set nodeResult to false
        //     nodeResult = false;
        // }
        // else
        // {
        // else, make a recursive call to right node and store its returned value into nodeResult
        nodeResult = processTree(node->right, currentSum + node->right->val, targetSum);
        // }
    }

    // return this node's result
    return nodeResult;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    // if root is null, retrun false
    if (root == nullptr)
    {
        return false;
    }
    return processTree(root, root->val, targetSum);
}