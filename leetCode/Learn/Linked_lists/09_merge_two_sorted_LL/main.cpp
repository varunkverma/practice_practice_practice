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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *newLL = nullptr;
        ListNode *np = newLL;

        ListNode *sn = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                sn = l1;
                l1 = l1->next;
            }
            else
            {
                sn = l2;
                l2 = l2->next;
            }

            if (newLL == nullptr)
            {
                newLL = sn;
                np = newLL;
            }
            else
            {
                np->next = sn;
                np = np->next;
            }
        }

        if (l1 != nullptr)
        {
            if (newLL == nullptr)
            {
                newLL = l1;
            }
            else
            {
                np->next = l1;
            }
            l1 = nullptr;
        }
        if (l2 != nullptr)
        {
            if (newLL == nullptr)
            {
                newLL = l2;
            }
            else
            {
                np->next = l2;
            }
            l2 = nullptr;
        }
        return newLL;
    }
};