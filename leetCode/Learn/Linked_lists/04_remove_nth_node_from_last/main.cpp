#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *prevNode = nullptr;
    ListNode *currentNode = head, *aheadNode = head;

    for (int i = 1; i <= n; i++)
    {
        aheadNode = aheadNode->next;
    }

    while (aheadNode != nullptr)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
        aheadNode = aheadNode->next;
    }

    if (currentNode == head)
    {
        head = currentNode->next;
    }
    else
    {
        prevNode->next = currentNode->next;
    }

    delete currentNode;

    return head;
}

int main()
{

    return 0;
}