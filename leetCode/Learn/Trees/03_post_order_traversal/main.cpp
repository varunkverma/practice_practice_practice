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
    vector<int> postorderTraversal(TreeNode *root)
    {
        // declare empty vector
        vector<int> postorderTraversalSequence = vector<int>();
        // check if root is null
        if (root == nullptr)
        {
            return postorderTraversalSequence;
        }
        // insert root in traversal sequence
        postorderTraversalSequence.push_back(root->val);
        auto leftTraversal = postorderTraversal(root->left);
        auto rightTraversal = postorderTraversal(root->right);

        // return in sequece left->root->right
        leftTraversal.insert(leftTraversal.end(), rightTraversal.begin(), rightTraversal.end());
        leftTraversal.insert(leftTraversal.end(), postorderTraversalSequence.begin(), postorderTraversalSequence.end());

        return leftTraversal;
    }
};

int main()
{

    return 0;
}