#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // declare empty vector
        vector<int> preOrderTraversalSequence = vector<int>();
        // check if root is null
        if (root == nullptr)
        {
            return preOrderTraversalSequence;
        }
        // insert root in traversal sequence
        preOrderTraversalSequence.push_back(root->val);
        auto leftTraversal = preorderTraversal(root->left);
        auto rightTraversal = preorderTraversal(root->right);

        // return in sequece root->left->right
        preOrderTraversalSequence.insert(preOrderTraversalSequence.end(), leftTraversal.begin(), leftTraversal.end());
        preOrderTraversalSequence.insert(preOrderTraversalSequence.end(), rightTraversal.begin(), rightTraversal.end());

        return preOrderTraversalSequence;
    }
};

int main()
{

    return 0;
}