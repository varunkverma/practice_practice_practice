#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *p = head;
    ListNode *q = nullptr;

    while (p->next != nullptr)
    {
        q = p->next;
        p->next = q->next;
        q->next = head;
        head = q;
    }

    return head;
}

int main()
{
    return 0;
}