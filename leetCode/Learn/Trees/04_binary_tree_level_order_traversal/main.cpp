#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> levelOrderTraversal(TreeNode *root)
{
    // traversal vector
    vector<vector<int>> traversalVec;
    // check if root is nullptr return []
    if (root == nullptr)
    {
        return traversalVec;
    }

    queue<TreeNode *> utilQueue;
    TreeNode *currentNode;
    // insert root into a queue
    utilQueue.push(root);

    while (utilQueue.size())
    {
        // get the current no. of elements in queue
        int nodesInCurrentLevel = utilQueue.size();
        vector<int> dq;

        while (nodesInCurrentLevel > 0)
        {

            currentNode = utilQueue.front();
            utilQueue.pop();
            dq.push_back(currentNode->val);

            // if any children to current node, push them to the queue
            if (currentNode->left != nullptr)
            {
                utilQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                utilQueue.push(currentNode->right);
            }
            nodesInCurrentLevel--;
        }

        traversalVec.push_back(dq);
    }

    return traversalVec;
}

int main()
{

    return 0;
}