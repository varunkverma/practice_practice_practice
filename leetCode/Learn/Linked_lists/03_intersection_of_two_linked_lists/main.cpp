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
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p = headA;
        ListNode *q = headB;

        while (p != q)
        {
            p = p == nullptr ? headB : p->next;
            q = q == nullptr ? headA : q->next;
        }

        return p;
    }
};

int main()
{
    return 0;
}