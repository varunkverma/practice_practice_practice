#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sumHead = nullptr;
        ListNode *sp = sumHead;

        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        int s = 0, c = 0;
        ListNode *p = l1, *q = l2;

        while (p != nullptr && q != nullptr)
        {
            s = p->val + q->val + c;
            c = s / 10;
            ListNode *nn = new ListNode(s % 10);

            if (sumHead == nullptr)
            {
                sumHead = nn;
                sp = nn;
            }
            else
            {
                sp->next = nn;
                sp = sp->next;
            }
            p = p->next;
            q = q->next;
        }

        while (p != nullptr)
        {
            s = p->val + c;
            c = s / 10;
            ListNode *nn = new ListNode(s % 10);

            if (sumHead == nullptr)
            {
                sumHead = nn;
                sp = nn;
            }
            else
            {
                sp->next = nn;
                sp = sp->next;
            }
            p = p->next;
        }

        while (q != nullptr)
        {
            s = q->val + c;
            c = s / 10;
            ListNode *nn = new ListNode(s % 10);

            if (sumHead == nullptr)
            {
                sumHead = nn;
                sp = nn;
            }
            else
            {
                sp->next = nn;
                sp = sp->next;
            }
            q = q->next;
        }

        if (c > 0)
        {
            ListNode *nn = new ListNode(c);
            sp->next = nn;
        }

        return sumHead;
    }
};