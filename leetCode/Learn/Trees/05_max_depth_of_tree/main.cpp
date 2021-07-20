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

int max_depth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    // find max depth for left children
    int left_depth = max_depth(root->left);
    // find max depth for right children
    int right_depth = max_depth(root->right);

    // return max(left,right) + 1
    return max(left_depth, right_depth) + 1;
}

int main()
{
    return 0;
}