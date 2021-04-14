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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // declare empty vector
        vector<int> inorderTraversalSequence = vector<int>();
        // check if root is null
        if (root == nullptr)
        {
            return inorderTraversalSequence;
        }
        // insert root in traversal sequence
        inorderTraversalSequence.push_back(root->val);
        auto leftTraversal = inorderTraversal(root->left);
        auto rightTraversal = inorderTraversal(root->right);

        // return in sequece left->root->right
        leftTraversal.insert(leftTraversal.end(), inorderTraversalSequence.begin(), inorderTraversalSequence.end());
        leftTraversal.insert(leftTraversal.end(), rightTraversal.begin(), rightTraversal.end());

        return leftTraversal;
    }
};

int main()
{

    return 0;
}