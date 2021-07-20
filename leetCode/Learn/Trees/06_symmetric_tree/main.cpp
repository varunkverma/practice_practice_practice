// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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

bool isVecSymmetric(vector<int> *A)
{
    bool isSymmetric = true;
    for (int i = 0, j = A->size() - 1; i < (A->size() / 2); i++, j--)
    {
        if (A->at(i) != A->at(j))
        {
            isSymmetric = false;
            break;
        }
    }
    return isSymmetric;
}

bool isSymmetric(TreeNode *root)
{ // using level-order traversal
    // check if null, return false
    if (root == nullptr)
    {
        return false;
    }

    // create a queue & enqueue root
    queue<TreeNode *> utilQueue;
    utilQueue.push(root);

    // create a variable to store if tree is symmetric
    bool isTreeSymmetric = true;

    // while queue isn't empty && isTreeSymmetric is true
    while (utilQueue.size() > 0 && isTreeSymmetric)
    {

        // current size of queue
        int currentSize = utilQueue.size();

        // temporary vector
        vector<int> tempVec;

        // while currentSize doesn't become 0
        while (currentSize > 0)
        {
            // Get the front node from utilQueue
            TreeNode *currentNode = utilQueue.front();
            // pop the node from queue
            utilQueue.pop();

            // if node has a left child, push it to queue and put its value in tempVec
            if (currentNode->left != nullptr)
            {
                utilQueue.push(currentNode->left);
                tempVec.push_back(currentNode->left->val);
            }
            else
            {
                // push -101 to tempVec
                tempVec.push_back(-101);
            }

            // if node has a right child, push it to queue and put its value in tempVec
            if (currentNode->right != nullptr)
            {
                utilQueue.push(currentNode->right);
                tempVec.push_back(currentNode->right->val);
            }
            else
            {
                // push -101 to tempVec
                tempVec.push_back(-101);
            }

            // decrement currentSize by -1
            currentSize--;
        }

        // update isTreeSymmetric with the symmetry of tempVec
        isTreeSymmetric = isVecSymmetric(&tempVec);
    }

    return isTreeSymmetric;
}

int main()
{
    vector<int> A{1, 2, 3, 2, 1};
    vector<int> B{1, 2, 2, 1};
    vector<int> C{1, 3, 2, 1};

    cout << isVecSymmetric(&A) << endl;
    cout << isVecSymmetric(&B) << endl;
    cout << isVecSymmetric(&C) << endl;

    return 0;
}