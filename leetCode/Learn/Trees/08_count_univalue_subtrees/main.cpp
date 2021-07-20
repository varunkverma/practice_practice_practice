// Given the root of a binary tree, return the number of uni-value subtrees.
// A uni-value subtree means all nodes of the subtree have the same value.
// Basically, parent node and chilren node val should be same. If a leafnode, then simply count it

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

struct Token
{
    int count;
    bool isPrevUnival;
};

Token postOrderTraversal(TreeNode *node, Token token)
{
    if (node == nullptr)
    {
        return {
            token.count,
            true};
    }
    if (isLeafNode(node))
    {
        token.count++;
        token.isPrevUnival = true;
        return token;
    }
    // left node
    Token lToken = postOrderTraversal(node->left, token);

    // right node
    Token rToken = postOrderTraversal(node->right, lToken);

    token.count = rToken.count;
    token.isPrevUnival = lToken.isPrevUnival && rToken.isPrevUnival;

    if (token.isPrevUnival)
    {
        if (node->left != nullptr && node->left->val != node->val)
        {
            token.isPrevUnival = false;
        }
        if (node->right != nullptr && node->right->val != node->val)
        {
            token.isPrevUnival = false;
        }
    }

    if (token.isPrevUnival)
    {
        token.count++;
    }
    return token;
}

bool isLeafNode(TreeNode *node)
{
    if (node != nullptr && node->left == nullptr && node->right == nullptr)
    {
        return true;
    }
    return false;
}

// using pre-order traversal
int countUnivalSubtrees(TreeNode *root)
{
    // if root is null
    if (root == nullptr)
    {
        return 0;
    }
    Token t = {
        0, false};
    Token resToken = postOrderTraversal(root, t);
    return resToken.count;
}

int main()
{
    return 0;
}
