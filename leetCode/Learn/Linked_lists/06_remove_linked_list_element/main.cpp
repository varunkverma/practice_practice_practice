#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    ListNode *p = head;
    ListNode *q = nullptr;

    while (p != nullptr)
    {
        if (p == head && p->val == val)
        {
            q = p;
            p = p->next;
            head = p;
            // delete q;
        }
        else
        {
            q = p->next;
            if (q == nullptr || q->val != val)
            {
                p = p->next;
                continue;
            }

            if (q != nullptr && q->val == val)
            {
                p->next = q->next;
                // delete q;
            }
        }
    }
    return head;
}