#include <iostream>
#include <set>

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
        set<ListNode *> encounderedNodes;

        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        if (headA == headB)
        {
            return headA;
        }

        ListNode *p = headA;
        ListNode *q = headB;

        while (p != nullptr || q != nullptr)
        {
            // check if p exits in set
            if (p != nullptr)
            {

                if (encounderedNodes.count(p) >= 1)
                {
                    return p;
                }

                encounderedNodes.insert(p);
                p = p->next;
            }

            // check if q exits in set
            if (q != nullptr)
            {

                if (encounderedNodes.count(q) >= 1)
                {
                    return q;
                }

                encounderedNodes.insert(q);
                q = q->next;
            }
        }

        return nullptr;
    }
};

int main()
{
    return 0;
}