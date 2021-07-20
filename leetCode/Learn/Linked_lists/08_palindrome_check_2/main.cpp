#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseLL(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *p = head;

    while (p != nullptr && p->next != nullptr)
    {
        ListNode *q = p->next;
        p->next = q->next;
        q->next = head;
        head = q;
    }

    return head;
}

ListNode *getMiddleNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *r = head, *t = head;

    while (r != nullptr)
    {
        t = t->next;
        r = r->next;
        if (r != nullptr)
        {
            r = r->next;
        }
    }
    return t;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *middleNode = getMiddleNode(head);

    ListNode *prevMiddle = head;

    while (prevMiddle->next != middleNode)
    {
        prevMiddle = prevMiddle->next;
    }

    prevMiddle->next = reverseLL(middleNode);

    ListNode *p = head;
    ListNode *q = prevMiddle->next;

    while (q != nullptr)
    {
        if (p->val != q->val)
        {
            return false;
        }
        p = p->next;
        q = q->next;
    }

    // middleNode = prevMiddle->next;
    prevMiddle->next = reverseLL(prevMiddle->next);

    return true;
}
