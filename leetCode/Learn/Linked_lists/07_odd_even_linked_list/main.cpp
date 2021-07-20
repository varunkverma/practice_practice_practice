#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *o = head;
    ListNode *p = head->next;
    ListNode *q = p->next;

    while (q != nullptr)
    {
        p->next = q->next;
        q->next = o->next;
        o->next = q;

        o = o->next;
        p = p->next;
        q = p != nullptr ? p->next : nullptr;
    }
    return head;
}