#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    ListNode *getIntersectionNode(ListNode *head)
    {
        // check if linked list is empty or only one node exists, return null
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *hare, *tortoise = head;

        while (hare != nullptr)
        {
            // move tortoise by node
            tortoise = tortoise->next;

            // move hare by 2 nodes
            hare = hare->next;
            if (hare != nullptr)
            {
                hare = hare->next;
            }
            if (hare == tortoise)
            {
                return tortoise;
            }
        }
        return nullptr;
    }

    ListNode *getCycleEnteranceNode(ListNode *head, ListNode *intersectionNode)
    {
        ListNode *ptr1 = head;
        ListNode *ptr2 = intersectionNode;

        while (ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }

public:
    ListNode *detectCycle(ListNode *head) // using flyod's hare and tortoise
    {

        ListNode *intersectionNode = this->getIntersectionNode(head);

        if (intersectionNode == nullptr)
        {
            return nullptr;
        }

        ListNode *cycleEnteranceNode = this->getCycleEnteranceNode(head, intersectionNode);

        return cycleEnteranceNode;
    }
};
